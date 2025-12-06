//==============================================================================
// Vector ALU - Partitionable 512-bit datapath
// Supports FP32/FP16/INT32/INT16/INT8 precision modes
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_alu (
    input wire clk,
    input wire rst_n,
    
    // Operands
    input wire [`VLEN-1:0]  op_a,
    input wire [`VLEN-1:0]  op_b,
    input wire [`VLEN-1:0]  op_c,
    
    // Operation control
    input wire [5:0]        alu_op,
    input wire [2:0]        sew,
    input wire [31:0]       vl,
    
    // Mask
    input wire [`VLEN/8-1:0] mask,
    input wire              mask_en,
    
    // Result
    output reg [`VLEN-1:0]  result,
    output reg              valid
);

    // Element width from SEW
    wire [6:0] element_width = (sew == `SEW_8)  ? 7'd8  :
                               (sew == `SEW_16) ? 7'd16 :
                               (sew == `SEW_32) ? 7'd32 : 7'd64;
    
    // Number of elements
    wire [7:0] num_elements = `VLEN / element_width;
    
    integer i;
    reg [`VLEN-1:0] temp_result;
    
    //--------------------------------------------------------------------------
    // ALU Operations
    //--------------------------------------------------------------------------
    always @(*) begin
        temp_result = {`VLEN{1'b0}};
        valid = 1'b1;
        
        case (sew)
            `SEW_8: begin
                for (i = 0; i < 64; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (alu_op)
                            `VALU_OP_ADD: temp_result[i*8 +: 8] = op_a[i*8 +: 8] + op_b[i*8 +: 8];
                            `VALU_OP_SUB: temp_result[i*8 +: 8] = op_a[i*8 +: 8] - op_b[i*8 +: 8];
                            `VALU_OP_AND: temp_result[i*8 +: 8] = op_a[i*8 +: 8] & op_b[i*8 +: 8];
                            `VALU_OP_OR:  temp_result[i*8 +: 8] = op_a[i*8 +: 8] | op_b[i*8 +: 8];
                            `VALU_OP_XOR: temp_result[i*8 +: 8] = op_a[i*8 +: 8] ^ op_b[i*8 +: 8];
                            default: temp_result[i*8 +: 8] = 8'b0;
                        endcase
                    end
                end
            end
            
            `SEW_16: begin
                for (i = 0; i < 32; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (alu_op)
                            `VALU_OP_ADD: temp_result[i*16 +: 16] = op_a[i*16 +: 16] + op_b[i*16 +: 16];
                            `VALU_OP_SUB: temp_result[i*16 +: 16] = op_a[i*16 +: 16] - op_b[i*16 +: 16];
                            `VALU_OP_AND: temp_result[i*16 +: 16] = op_a[i*16 +: 16] & op_b[i*16 +: 16];
                            `VALU_OP_OR:  temp_result[i*16 +: 16] = op_a[i*16 +: 16] | op_b[i*16 +: 16];
                            `VALU_OP_XOR: temp_result[i*16 +: 16] = op_a[i*16 +: 16] ^ op_b[i*16 +: 16];
                            `VALU_OP_MUL: temp_result[i*16 +: 16] = op_a[i*16 +: 16] * op_b[i*16 +: 16];
                            default: temp_result[i*16 +: 16] = 16'b0;
                        endcase
                    end
                end
            end
            
            `SEW_32: begin
                for (i = 0; i < 16; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (alu_op)
                            `VALU_OP_ADD: temp_result[i*32 +: 32] = op_a[i*32 +: 32] + op_b[i*32 +: 32];
                            `VALU_OP_SUB: temp_result[i*32 +: 32] = op_a[i*32 +: 32] - op_b[i*32 +: 32];
                            `VALU_OP_AND: temp_result[i*32 +: 32] = op_a[i*32 +: 32] & op_b[i*32 +: 32];
                            `VALU_OP_OR:  temp_result[i*32 +: 32] = op_a[i*32 +: 32] | op_b[i*32 +: 32];
                            `VALU_OP_XOR: temp_result[i*32 +: 32] = op_a[i*32 +: 32] ^ op_b[i*32 +: 32];
                            `VALU_OP_MUL: temp_result[i*32 +: 32] = op_a[i*32 +: 32] * op_b[i*32 +: 32];
                            `VALU_OP_MACC: temp_result[i*32 +: 32] = op_c[i*32 +: 32] + (op_a[i*32 +: 32] * op_b[i*32 +: 32]);
                            default: temp_result[i*32 +: 32] = 32'b0;
                        endcase
                    end
                end
            end
            
            `SEW_64: begin
                for (i = 0; i < 8; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (alu_op)
                            `VALU_OP_ADD: temp_result[i*64 +: 64] = op_a[i*64 +: 64] + op_b[i*64 +: 64];
                            `VALU_OP_SUB: temp_result[i*64 +: 64] = op_a[i*64 +: 64] - op_b[i*64 +: 64];
                            `VALU_OP_AND: temp_result[i*64 +: 64] = op_a[i*64 +: 64] & op_b[i*64 +: 64];
                            `VALU_OP_OR:  temp_result[i*64 +: 64] = op_a[i*64 +: 64] | op_b[i*64 +: 64];
                            `VALU_OP_XOR: temp_result[i*64 +: 64] = op_a[i*64 +: 64] ^ op_b[i*64 +: 64];
                            default: temp_result[i*64 +: 64] = 64'b0;
                        endcase
                    end
                end
            end
        endcase
    end
    
    // Register output
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result <= {`VLEN{1'b0}};
        end else begin
            result <= temp_result;
        end
    end

endmodule
