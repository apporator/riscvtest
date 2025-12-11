//==============================================================================
// Vector Fixed-Point ALU
// Supports saturating operations, averaging, scaling shifts, and clipping
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_fixedpt_alu #(
    parameter VLEN = `VLEN
)(
    input wire clk,
    input wire rst_n,
    
    // Operands
    input wire [VLEN-1:0]  op_a,
    input wire [VLEN-1:0]  op_b,
    input wire [31:0]      scalar_op,
    input wire [4:0]       imm5,
    
    // Control
    input wire [5:0]       funct6,
    input wire [2:0]       sew,
    input wire [31:0]      vl,
    input wire             use_scalar,
    input wire             use_imm,
    input wire [1:0]       vxrm,        // Rounding mode
    
    // Mask
    input wire [VLEN/8-1:0] mask,
    input wire              mask_en,
    
    // Results
    output reg [VLEN-1:0]   result,
    output reg              vxsat,      // Saturation flag
    output reg              valid
);

    integer i;
    reg [VLEN-1:0] temp_result;
    reg temp_vxsat;
    reg [VLEN-1:0] operand_b;
    
    // Prepare operand B
    always @(*) begin
        if (use_imm) begin
            operand_b = {{(VLEN-5){imm5[4]}}, imm5};
        end else if (use_scalar) begin
            case (sew)
                `SEW_8:  operand_b = {64{scalar_op[7:0]}};
                `SEW_16: operand_b = {32{scalar_op[15:0]}};
                `SEW_32: operand_b = {16{scalar_op[31:0]}};
                `SEW_64: operand_b = {8{scalar_op[31:0], 32'b0}};
                default: operand_b = op_b;
            endcase
        end else begin
            operand_b = op_b;
        end
    end
    
    // Fixed-point operations
    always @(*) begin
        temp_result = {VLEN{1'b0}};
        temp_vxsat = 1'b0;
        valid = 1'b1;
        
        case (sew)
            `SEW_8: begin
                for (i = 0; i < 64; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            // Saturating add unsigned
                            6'h20: begin // vsaddu
                                temp_result[i*8 +: 8] = (op_a[i*8 +: 8] + operand_b[i*8 +: 8] > 8'hFF) ? 
                                                        8'hFF : (op_a[i*8 +: 8] + operand_b[i*8 +: 8]);
                                temp_vxsat = temp_vxsat | ((op_a[i*8 +: 8] + operand_b[i*8 +: 8]) > 8'hFF);
                            end
                            
                            // Saturating add signed
                            6'h21: begin // vsadd
                                reg signed [8:0] sum;
                                sum = $signed({1'b0, op_a[i*8 +: 8]}) + $signed({1'b0, operand_b[i*8 +: 8]});
                                if (sum > $signed(9'sh7F)) begin
                                    temp_result[i*8 +: 8] = 8'h7F;
                                    temp_vxsat = 1'b1;
                                end else if (sum < $signed(-9'sh80)) begin
                                    temp_result[i*8 +: 8] = 8'h80;
                                    temp_vxsat = 1'b1;
                                end else begin
                                    temp_result[i*8 +: 8] = sum[7:0];
                                end
                            end
                            
                            // Saturating subtract unsigned
                            6'h22: begin // vssubu
                                temp_result[i*8 +: 8] = (op_a[i*8 +: 8] < operand_b[i*8 +: 8]) ? 
                                                        8'h00 : (op_a[i*8 +: 8] - operand_b[i*8 +: 8]);
                                temp_vxsat = temp_vxsat | (op_a[i*8 +: 8] < operand_b[i*8 +: 8]);
                            end
                            
                            // Saturating subtract signed
                            6'h23: begin // vssub
                                reg signed [8:0] diff;
                                diff = $signed({1'b0, op_a[i*8 +: 8]}) - $signed({1'b0, operand_b[i*8 +: 8]});
                                if (diff > $signed(9'sh7F)) begin
                                    temp_result[i*8 +: 8] = 8'h7F;
                                    temp_vxsat = 1'b1;
                                end else if (diff < $signed(-9'sh80)) begin
                                    temp_result[i*8 +: 8] = 8'h80;
                                    temp_vxsat = 1'b1;
                                end else begin
                                    temp_result[i*8 +: 8] = diff[7:0];
                                end
                            end
                            
                            // Averaging add unsigned
                            6'h08: begin // vaaddu
                                temp_result[i*8 +: 8] = (op_a[i*8 +: 8] + operand_b[i*8 +: 8] + 1) >> 1;
                            end
                            
                            // Averaging add signed
                            6'h09: begin // vaadd
                                temp_result[i*8 +: 8] = ($signed(op_a[i*8 +: 8]) + $signed(operand_b[i*8 +: 8]) + 1) >>> 1;
                            end
                            
                            // Averaging subtract unsigned
                            6'h0A: begin // vasubu
                                temp_result[i*8 +: 8] = (op_a[i*8 +: 8] - operand_b[i*8 +: 8]) >> 1;
                            end
                            
                            // Averaging subtract signed
                            6'h0B: begin // vasub
                                temp_result[i*8 +: 8] = ($signed(op_a[i*8 +: 8]) - $signed(operand_b[i*8 +: 8])) >>> 1;
                            end
                            
                            // Scaling shift right (with rounding)
                            6'h2A: begin // vssrl
                                reg [7:0] shift_amt;
                                reg [7:0] shifted;
                                reg round_bit;
                                shift_amt = operand_b[i*8 +: 3];
                                shifted = op_a[i*8 +: 8] >> shift_amt;
                                round_bit = (shift_amt > 0) ? op_a[i*8 + (shift_amt-1)] : 1'b0;
                                // Apply rounding based on vxrm
                                case (vxrm)
                                    2'b00: temp_result[i*8 +: 8] = shifted + round_bit; // RNU
                                    2'b01: temp_result[i*8 +: 8] = shifted + (round_bit & shifted[0]); // RNE
                                    2'b10: temp_result[i*8 +: 8] = shifted; // RDN
                                    2'b11: temp_result[i*8 +: 8] = shifted + round_bit; // ROD
                                endcase
                            end
                            
                            // Scaling shift right arithmetic
                            6'h2B: begin // vssra
                                reg [7:0] shift_amt;
                                reg signed [7:0] shifted;
                                reg round_bit;
                                shift_amt = operand_b[i*8 +: 3];
                                shifted = $signed(op_a[i*8 +: 8]) >>> shift_amt;
                                round_bit = (shift_amt > 0) ? op_a[i*8 + (shift_amt-1)] : 1'b0;
                                case (vxrm)
                                    2'b00: temp_result[i*8 +: 8] = shifted + round_bit;
                                    2'b01: temp_result[i*8 +: 8] = shifted + (round_bit & shifted[0]);
                                    2'b10: temp_result[i*8 +: 8] = shifted;
                                    2'b11: temp_result[i*8 +: 8] = shifted + round_bit;
                                endcase
                            end
                            
                            default: temp_result[i*8 +: 8] = 8'b0;
                        endcase
                    end
                end
            end
            
            `SEW_16: begin
                for (i = 0; i < 32; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            6'h20: begin
                                temp_result[i*16 +: 16] = (op_a[i*16 +: 16] + operand_b[i*16 +: 16] > 16'hFFFF) ? 
                                                          16'hFFFF : (op_a[i*16 +: 16] + operand_b[i*16 +: 16]);
                                temp_vxsat = temp_vxsat | ((op_a[i*16 +: 16] + operand_b[i*16 +: 16]) > 16'hFFFF);
                            end
                            6'h21: begin
                                reg signed [16:0] sum;
                                sum = $signed({1'b0, op_a[i*16 +: 16]}) + $signed({1'b0, operand_b[i*16 +: 16]});
                                if (sum > $signed(17'sh7FFF)) begin
                                    temp_result[i*16 +: 16] = 16'h7FFF;
                                    temp_vxsat = 1'b1;
                                end else if (sum < $signed(-17'sh8000)) begin
                                    temp_result[i*16 +: 16] = 16'h8000;
                                    temp_vxsat = 1'b1;
                                end else begin
                                    temp_result[i*16 +: 16] = sum[15:0];
                                end
                            end
                            6'h08: temp_result[i*16 +: 16] = (op_a[i*16 +: 16] + operand_b[i*16 +: 16] + 1) >> 1;
                            6'h09: temp_result[i*16 +: 16] = ($signed(op_a[i*16 +: 16]) + $signed(operand_b[i*16 +: 16]) + 1) >>> 1;
                            default: temp_result[i*16 +: 16] = 16'b0;
                        endcase
                    end
                end
            end
            
            `SEW_32: begin
                for (i = 0; i < 16; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            6'h20: begin
                                reg [32:0] sum;
                                sum = {1'b0, op_a[i*32 +: 32]} + {1'b0, operand_b[i*32 +: 32]};
                                temp_result[i*32 +: 32] = sum[32] ? 32'hFFFFFFFF : sum[31:0];
                                temp_vxsat = temp_vxsat | sum[32];
                            end
                            6'h21: begin
                                reg signed [32:0] sum;
                                sum = $signed({op_a[i*32+31], op_a[i*32 +: 32]}) + 
                                      $signed({operand_b[i*32+31], operand_b[i*32 +: 32]});
                                if (sum > $signed(33'sh7FFFFFFF)) begin
                                    temp_result[i*32 +: 32] = 32'h7FFFFFFF;
                                    temp_vxsat = 1'b1;
                                end else if (sum < $signed(-33'sh80000000)) begin
                                    temp_result[i*32 +: 32] = 32'h80000000;
                                    temp_vxsat = 1'b1;
                                end else begin
                                    temp_result[i*32 +: 32] = sum[31:0];
                                end
                            end
                            6'h08: temp_result[i*32 +: 32] = ({1'b0, op_a[i*32 +: 32]} + {1'b0, operand_b[i*32 +: 32]} + 1) >> 1;
                            6'h09: temp_result[i*32 +: 32] = ($signed(op_a[i*32 +: 32]) + $signed(operand_b[i*32 +: 32]) + 1) >>> 1;
                            default: temp_result[i*32 +: 32] = 32'b0;
                        endcase
                    end
                end
            end
            
            `SEW_64: begin
                for (i = 0; i < 8; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            6'h08: temp_result[i*64 +: 64] = ({1'b0, op_a[i*64 +: 64]} + {1'b0, operand_b[i*64 +: 64]} + 1) >> 1;
                            6'h09: temp_result[i*64 +: 64] = ($signed(op_a[i*64 +: 64]) + $signed(operand_b[i*64 +: 64]) + 1) >>> 1;
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
            result <= {VLEN{1'b0}};
            vxsat <= 1'b0;
        end else begin
            result <= temp_result;
            vxsat <= temp_vxsat;
        end
    end

endmodule
