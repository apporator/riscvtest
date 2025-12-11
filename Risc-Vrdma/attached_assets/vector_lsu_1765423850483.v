//==============================================================================
// Vector Load/Store Unit
// Supports unit-stride, strided, and indexed addressing modes
// Handles element width conversion, alignment, and segment operations
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_lsu #(
    parameter VLEN = `VLEN
)(
    input wire clk,
    input wire rst_n,
    
    // Control inputs
    input wire        valid,
    input wire        is_load,
    input wire        is_store,
    input wire        unit_stride,
    input wire        strided,
    input wire        indexed,
    input wire [2:0]  sew,
    input wire [31:0] vl,
    input wire [31:0] base_addr,
    input wire [31:0] stride,          // For strided access
    input wire [VLEN-1:0] indices,     // For indexed access
    input wire [2:0]  nf,              // Number of fields (segments)
    input wire        vm,              // Mask enable (1=unmasked)
    input wire [VLEN/8-1:0] mask,
    input wire [4:0]  vd_addr,
    input wire [4:0]  vs3_addr,
    
    // Vector register interface
    output reg [4:0]         vrf_r_addr,
    input wire [VLEN-1:0]    vrf_r_data,
    output reg [4:0]         vrf_w_addr,
    output reg [VLEN-1:0]    vrf_w_data,
    output reg               vrf_w_en,
    
    // Memory interface
    output reg [31:0]        mem_addr,
    output reg [VLEN-1:0]    mem_wdata,
    output reg [VLEN/8-1:0]  mem_wstrb,
    output reg               mem_valid,
    output reg               mem_wen,
    input  wire [VLEN-1:0]   mem_rdata,
    input  wire              mem_ready,
    
    // Status outputs
    output reg               busy,
    output reg               done
);

    // State machine
    localparam IDLE       = 3'b000;
    localparam CALC_ADDR  = 3'b001;
    localparam MEM_REQ    = 3'b010;
    localparam MEM_WAIT   = 3'b011;
    localparam WRITEBACK  = 3'b100;
    localparam DONE_STATE = 3'b101;
    
    reg [2:0] state;
    reg [31:0] element_count;
    reg [VLEN-1:0] result_buffer;
    reg [31:0] segment_idx;
    
    // Element width in bytes
    wire [6:0] elem_bytes = (sew == `SEW_8)  ? 7'd1  :
                            (sew == `SEW_16) ? 7'd2  :
                            (sew == `SEW_32) ? 7'd4  : 7'd8;
    
    // Calculate memory address for current element
    reg [31:0] current_addr;
    always @(*) begin
        if (unit_stride) begin
            // Unit-stride: addr = base + elem_count * elem_size * (nf + 1)
            current_addr = base_addr + (element_count * elem_bytes * (nf + 1)) + (segment_idx * elem_bytes);
        end else if (strided) begin
            // Strided: addr = base + elem_count * stride
            current_addr = base_addr + (element_count * stride) + (segment_idx * elem_bytes);
        end else if (indexed) begin
            // Indexed: addr = base + index[elem_count]
            case (sew)
                `SEW_8:  current_addr = base_addr + indices[element_count*8 +: 8];
                `SEW_16: current_addr = base_addr + indices[element_count*16 +: 16];
                `SEW_32: current_addr = base_addr + indices[element_count*32 +: 32];
                `SEW_64: current_addr = base_addr + indices[element_count*64 +: 32];
                default: current_addr = base_addr;
            endcase
        end else begin
            current_addr = base_addr;
        end
    end
    
    // State machine
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            element_count <= 32'b0;
            segment_idx <= 32'b0;
            busy <= 1'b0;
            done <= 1'b0;
            mem_valid <= 1'b0;
            mem_wen <= 1'b0;
            vrf_w_en <= 1'b0;
            result_buffer <= {VLEN{1'b0}};
            vrf_r_addr <= 5'b0;
            vrf_w_addr <= 5'b0;
        end else begin
            case (state)
                IDLE: begin
                    busy <= 1'b0;
                    done <= 1'b0;
                    vrf_w_en <= 1'b0;
                    
                    if (valid) begin
                        element_count <= 32'b0;
                        segment_idx <= 32'b0;
                        result_buffer <= {VLEN{1'b0}};
                        busy <= 1'b1;
                        
                        if (is_load) begin
                            vrf_w_addr <= vd_addr;
                        end else begin
                            vrf_r_addr <= vs3_addr;
                        end
                        
                        state <= CALC_ADDR;
                    end
                end
                
                CALC_ADDR: begin
                    // Check if current element is masked
                    if (vm || mask[element_count]) begin
                        mem_addr <= current_addr;
                        state <= MEM_REQ;
                    end else begin
                        // Skip masked element
                        if (element_count >= vl - 1) begin
                            state <= DONE_STATE;
                        end else begin
                            element_count <= element_count + 1;
                            state <= CALC_ADDR;
                        end
                    end
                end
                
                MEM_REQ: begin
                    mem_valid <= 1'b1;
                    mem_wen <= is_store;
                    
                    if (is_store) begin
                        // Prepare store data
                        case (sew)
                            `SEW_8: begin
                                mem_wdata <= {64{vrf_r_data[element_count*8 +: 8]}};
                                mem_wstrb <= (64'b1 << current_addr[5:0]);
                            end
                            `SEW_16: begin
                                mem_wdata <= {32{vrf_r_data[element_count*16 +: 16]}};
                                mem_wstrb <= (64'b11 << current_addr[5:1]);
                            end
                            `SEW_32: begin
                                mem_wdata <= {16{vrf_r_data[element_count*32 +: 32]}};
                                mem_wstrb <= (64'b1111 << current_addr[5:2]);
                            end
                            `SEW_64: begin
                                mem_wdata <= {8{vrf_r_data[element_count*64 +: 64]}};
                                mem_wstrb <= (64'b11111111 << current_addr[5:3]);
                            end
                        endcase
                    end
                    
                    state <= MEM_WAIT;
                end
                
                MEM_WAIT: begin
                    if (mem_ready) begin
                        mem_valid <= 1'b0;
                        
                        if (is_load) begin
                            // Extract loaded data
                            case (sew)
                                `SEW_8: begin
                                    result_buffer[element_count*8 +: 8] <= mem_rdata[(current_addr[5:0])*8 +: 8];
                                end
                                `SEW_16: begin
                                    result_buffer[element_count*16 +: 16] <= mem_rdata[(current_addr[5:1])*16 +: 16];
                                end
                                `SEW_32: begin
                                    result_buffer[element_count*32 +: 32] <= mem_rdata[(current_addr[5:2])*32 +: 32];
                                end
                                `SEW_64: begin
                                    result_buffer[element_count*64 +: 64] <= mem_rdata[(current_addr[5:3])*64 +: 64];
                                end
                            endcase
                        end
                        
                        // Check if we need to process more segments
                        if (segment_idx < nf) begin
                            segment_idx <= segment_idx + 1;
                            state <= CALC_ADDR;
                        end else begin
                            segment_idx <= 32'b0;
                            
                            // Move to next element
                            if (element_count >= vl - 1) begin
                                if (is_load) begin
                                    state <= WRITEBACK;
                                end else begin
                                    state <= DONE_STATE;
                                end
                            end else begin
                                element_count <= element_count + 1;
                                state <= CALC_ADDR;
                            end
                        end
                    end
                end
                
                WRITEBACK: begin
                    vrf_w_data <= result_buffer;
                    vrf_w_en <= 1'b1;
                    state <= DONE_STATE;
                end
                
                DONE_STATE: begin
                    mem_valid <= 1'b0;
                    mem_wen <= 1'b0;
                    vrf_w_en <= 1'b0;
                    busy <= 1'b0;
                    done <= 1'b1;
                    state <= IDLE;
                end
                
                default: state <= IDLE;
            endcase
        end
    end

endmodule
