//==============================================================================
// Vector Register File
// 32 vector registers x 512 bits each, implemented using FPGA block RAM
//==============================================================================

`include "../common/config.vh"

module vector_regfile (
    input wire clk,
    input wire rst_n,
    
    // Read port A
    input wire [4:0]             ra_addr,
    output reg [`VLEN-1:0]       ra_data,
    
    // Read port B
    input wire [4:0]             rb_addr,
    output reg [`VLEN-1:0]       rb_data,
    
    // Read port C (for 3-operand instructions)
    input wire [4:0]             rc_addr,
    output reg [`VLEN-1:0]       rc_data,
    
    // Write port
    input wire [4:0]             w_addr,
    input wire [`VLEN-1:0]       w_data,
    input wire                   w_en,
    
    // Mask register interface
    input wire [2:0]             mask_addr,
    output reg [`VLEN/8-1:0]     mask_data,
    input wire [2:0]             mask_w_addr,
    input wire [`VLEN/8-1:0]     mask_w_data,
    input wire                   mask_w_en
);

    // Vector register file storage
    // Implemented as block RAM for FPGA efficiency
    reg [`VLEN-1:0] vregs [0:31];
    
    // Mask register file (8 registers)
    reg [`VLEN/8-1:0] mask_regs [0:7];
    
    integer i;
    
    // Read ports (combinational for low latency)
    always @(*) begin
        ra_data = vregs[ra_addr];
        rb_data = vregs[rb_addr];
        rc_data = vregs[rc_addr];
        mask_data = mask_regs[mask_addr];
    end
    
    // Write port (synchronous)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < 32; i = i + 1) begin
                vregs[i] <= {`VLEN{1'b0}};
            end
        end else begin
            if (w_en) begin
                vregs[w_addr] <= w_data;
            end
        end
    end
    
    // Mask register write
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < 8; i = i + 1) begin
                mask_regs[i] <= {(`VLEN/8){1'b0}};
            end
        end else begin
            if (mask_w_en) begin
                mask_regs[mask_w_addr] <= mask_w_data;
            end
        end
    end

endmodule
