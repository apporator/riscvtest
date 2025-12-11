//==============================================================================
// RDMA Engine - Hardware descriptor queue and DMA controller
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module rdma_engine (
    input wire clk,
    input wire rst_n,
    
    // Control interface
    input wire [31:0]  desc_addr,
    input wire         desc_valid,
    output reg         desc_ready,
    output reg         done,
    output reg         error,
    
    // Memory interface
    output reg [31:0]        mem_addr,
    output reg [`VLEN-1:0]   mem_wdata,
    output reg [`VLEN/8-1:0] mem_wstrb,
    output reg               mem_valid,
    output reg               mem_wen,
    input  wire [`VLEN-1:0]  mem_rdata,
    input  wire              mem_ready
);

    // Descriptor queue
    reg [127:0] desc_queue [`DESC_QUEUE_DEPTH-1:0];
    reg [`DESC_QUEUE_INDEX_BITS-1:0] queue_head;
    reg [`DESC_QUEUE_INDEX_BITS-1:0] queue_tail;
    reg [`DESC_QUEUE_INDEX_BITS-1:0] queue_count;
    
    // Current descriptor
    reg [127:0] current_desc;
    reg [31:0]  transfer_count;
    reg [31:0]  src_addr;
    reg [31:0]  dst_addr;
    
    // State machine
    reg [2:0] state;
    
    integer i;
    
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= `RDMA_IDLE;
            queue_head <= {`DESC_QUEUE_INDEX_BITS{1'b0}};
            queue_tail <= {`DESC_QUEUE_INDEX_BITS{1'b0}};
            queue_count <= {`DESC_QUEUE_INDEX_BITS{1'b0}};
            desc_ready <= 1'b1;
            done <= 1'b0;
            error <= 1'b0;
            mem_valid <= 1'b0;
            
            for (i = 0; i < `DESC_QUEUE_DEPTH; i = i + 1) begin
                desc_queue[i] <= 128'b0;
            end
        end else begin
            case (state)
                `RDMA_IDLE: begin
                    done <= 1'b0;
                    error <= 1'b0;
                    mem_valid <= 1'b0;
                    
                    // Accept new descriptors
                    if (desc_valid && queue_count < `DESC_QUEUE_DEPTH) begin
                        desc_queue[queue_tail] <= {96'b0, desc_addr};
                        queue_tail <= queue_tail + 1;
                        queue_count <= queue_count + 1;
                    end
                    
                    // Process queue
                    if (queue_count > 0) begin
                        current_desc <= desc_queue[queue_head];
                        state <= `RDMA_FETCH_DESC;
                    end
                    
                    desc_ready <= (queue_count < `DESC_QUEUE_DEPTH);
                end
                
                `RDMA_FETCH_DESC: begin
                    // Extract descriptor fields
                    src_addr <= current_desc[63:32];
                    dst_addr <= current_desc[95:64];
                    transfer_count <= {16'b0, current_desc[31:16]};
                    
                    if (current_desc[`DESC_VALID]) begin
                        state <= `RDMA_VALIDATE;
                    end else begin
                        error <= 1'b1;
                        state <= `RDMA_ERROR;
                    end
                end
                
                `RDMA_VALIDATE: begin
                    // Simple validation: check alignment
                    if ((src_addr & 6'h3f) != 0 || (dst_addr & 6'h3f) != 0) begin
                        error <= 1'b1;
                        state <= `RDMA_ERROR;
                    end else begin
                        state <= `RDMA_TRANSFER;
                    end
                end
                
                `RDMA_TRANSFER: begin
                    // Simplified transfer: single beat
                    if (transfer_count > 0) begin
                        mem_addr <= src_addr;
                        mem_valid <= 1'b1;
                        mem_wen <= 1'b0;
                        
                        if (mem_ready) begin
                            mem_valid <= 1'b0;
                            state <= `RDMA_UPDATE;
                        end
                    end else begin
                        done <= 1'b1;
                        queue_head <= queue_head + 1;
                        queue_count <= queue_count - 1;
                        state <= `RDMA_IDLE;
                    end
                end
                
                `RDMA_UPDATE: begin
                    // Write to destination
                    mem_addr <= dst_addr;
                    mem_wdata <= mem_rdata;
                    mem_wstrb <= {(`VLEN/8){1'b1}};
                    mem_valid <= 1'b1;
                    mem_wen <= 1'b1;
                    
                    if (mem_ready) begin
                        mem_valid <= 1'b0;
                        transfer_count <= transfer_count - 64;
                        src_addr <= src_addr + 64;
                        dst_addr <= dst_addr + 64;
                        state <= `RDMA_TRANSFER;
                    end
                end
                
                `RDMA_ERROR: begin
                    queue_head <= queue_head + 1;
                    queue_count <= queue_count - 1;
                    state <= `RDMA_IDLE;
                end
                
                default: state <= `RDMA_IDLE;
            endcase
        end
    end

endmodule
