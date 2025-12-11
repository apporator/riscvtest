//==============================================================================
// Vector Integer ALU
// Supports all RVV integer operations: add, sub, shift, compare, min/max,
// multiply, divide, carry/borrow, etc.
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_int_alu #(
    parameter VLEN = `VLEN
)(
    input wire clk,
    input wire rst_n,
    
    // Operands
    input wire [VLEN-1:0]  op_a,
    input wire [VLEN-1:0]  op_b,
    input wire [VLEN-1:0]  op_c,        // For multiply-add
    input wire [31:0]      scalar_op,   // Scalar operand (for .vx ops)
    input wire [4:0]       imm5,        // 5-bit immediate (for .vi ops)
    
    // Control
    input wire [5:0]       funct6,
    input wire [2:0]       sew,          // Element width
    input wire [31:0]      vl,           // Vector length
    input wire             use_scalar,   // Use scalar_op instead of op_b
    input wire             use_imm,      // Use imm5 instead of op_b
    input wire             use_carry_in, // Use carry mask
    input wire [VLEN/8-1:0] carry_mask,  // Carry-in mask
    
    // Mask
    input wire [VLEN/8-1:0] mask,
    input wire              mask_en,
    input wire              vma,         // Mask agnostic
    input wire              vta,         // Tail agnostic
    
    // Results
    output reg [VLEN-1:0]   result,
    output reg [VLEN/8-1:0] mask_result, // For comparison/carry results
    output reg              valid,
    output reg              divide_by_zero,
    output reg              overflow
);

    integer i;
    reg [VLEN-1:0] temp_result;
    reg [VLEN/8-1:0] temp_mask_result;
    reg [VLEN-1:0] operand_b;
    
    // Prepare operand B (can be vector, scalar, or immediate)
    always @(*) begin
        if (use_imm) begin
            // Sign-extend 5-bit immediate
            operand_b = {{(VLEN-5){imm5[4]}}, imm5};
        end else if (use_scalar) begin
            // Replicate scalar across all elements based on SEW
            case (sew)
                `SEW_8:  operand_b = {64{scalar_op[7:0]}};
                `SEW_16: operand_b = {32{scalar_op[15:0]}};
                `SEW_32: operand_b = {16{scalar_op[31:0]}};
                `SEW_64: operand_b = {8{scalar_op[31:0], 32'b0}}; // Extend to 64-bit
                default: operand_b = op_b;
            endcase
        end else begin
            operand_b = op_b;
        end
    end
    
    // Element width in bits
    wire [6:0] elem_width = (sew == `SEW_8)  ? 7'd8  :
                            (sew == `SEW_16) ? 7'd16 :
                            (sew == `SEW_32) ? 7'd32 : 7'd64;
    
    // Number of elements
    wire [7:0] num_elem = VLEN / elem_width;
    
    // ALU operation execution
    always @(*) begin
        temp_result = {VLEN{1'b0}};
        temp_mask_result = {(VLEN/8){1'b0}};
        divide_by_zero = 1'b0;
        overflow = 1'b0;
        valid = 1'b1;
        
        case (sew)
            `SEW_8: begin
                for (i = 0; i < 64; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            // Add/Sub
                            6'h00: temp_result[i*8 +: 8] = op_a[i*8 +: 8] + operand_b[i*8 +: 8]; // vadd
                            6'h02: temp_result[i*8 +: 8] = op_a[i*8 +: 8] - operand_b[i*8 +: 8]; // vsub
                            6'h03: temp_result[i*8 +: 8] = operand_b[i*8 +: 8] - op_a[i*8 +: 8]; // vrsub
                            
                            // Logical
                            6'h09: temp_result[i*8 +: 8] = op_a[i*8 +: 8] & operand_b[i*8 +: 8]; // vand
                            6'h0A: temp_result[i*8 +: 8] = op_a[i*8 +: 8] | operand_b[i*8 +: 8]; // vor
                            6'h0B: temp_result[i*8 +: 8] = op_a[i*8 +: 8] ^ operand_b[i*8 +: 8]; // vxor
                            
                            // Shifts
                            6'h25: temp_result[i*8 +: 8] = op_a[i*8 +: 8] << operand_b[i*8 +: 3]; // vsll
                            6'h28: temp_result[i*8 +: 8] = op_a[i*8 +: 8] >> operand_b[i*8 +: 3]; // vsrl
                            6'h29: temp_result[i*8 +: 8] = $signed(op_a[i*8 +: 8]) >>> operand_b[i*8 +: 3]; // vsra
                            
                            // Min/Max unsigned
                            6'h04: temp_result[i*8 +: 8] = (op_a[i*8 +: 8] < operand_b[i*8 +: 8]) ? op_a[i*8 +: 8] : operand_b[i*8 +: 8]; // vminu
                            6'h06: temp_result[i*8 +: 8] = (op_a[i*8 +: 8] > operand_b[i*8 +: 8]) ? op_a[i*8 +: 8] : operand_b[i*8 +: 8]; // vmaxu
                            
                            // Min/Max signed
                            6'h05: temp_result[i*8 +: 8] = ($signed(op_a[i*8 +: 8]) < $signed(operand_b[i*8 +: 8])) ? op_a[i*8 +: 8] : operand_b[i*8 +: 8]; // vmin
                            6'h07: temp_result[i*8 +: 8] = ($signed(op_a[i*8 +: 8]) > $signed(operand_b[i*8 +: 8])) ? op_a[i*8 +: 8] : operand_b[i*8 +: 8]; // vmax
                            
                            // Comparisons (result to mask register)
                            6'h18: temp_mask_result[i] = (op_a[i*8 +: 8] == operand_b[i*8 +: 8]); // vmseq
                            6'h19: temp_mask_result[i] = (op_a[i*8 +: 8] != operand_b[i*8 +: 8]); // vmsne
                            6'h1A: temp_mask_result[i] = (op_a[i*8 +: 8] < operand_b[i*8 +: 8]);  // vmsltu
                            6'h1B: temp_mask_result[i] = ($signed(op_a[i*8 +: 8]) < $signed(operand_b[i*8 +: 8])); // vmslt
                            6'h1C: temp_mask_result[i] = (op_a[i*8 +: 8] <= operand_b[i*8 +: 8]); // vmsleu
                            6'h1D: temp_mask_result[i] = ($signed(op_a[i*8 +: 8]) <= $signed(operand_b[i*8 +: 8])); // vmsle
                            6'h1E: temp_mask_result[i] = (op_a[i*8 +: 8] > operand_b[i*8 +: 8]);  // vmsgtu
                            6'h1F: temp_mask_result[i] = ($signed(op_a[i*8 +: 8]) > $signed(operand_b[i*8 +: 8])); // vmsgt
                            
                            // Multiply (low 8 bits)
                            6'h25: temp_result[i*8 +: 8] = op_a[i*8 +: 8] * operand_b[i*8 +: 8]; // vmul
                            
                            // Add/subtract with carry
                            6'h10: begin // vadc
                                temp_result[i*8 +: 8] = op_a[i*8 +: 8] + operand_b[i*8 +: 8] + (use_carry_in ? carry_mask[i] : 1'b0);
                            end
                            6'h12: begin // vsbc
                                temp_result[i*8 +: 8] = op_a[i*8 +: 8] - operand_b[i*8 +: 8] - (use_carry_in ? carry_mask[i] : 1'b0);
                            end
                            
                            // Generate carry/borrow for mask register
                            6'h11: begin // vmadc
                                temp_mask_result[i] = (op_a[i*8 +: 8] + operand_b[i*8 +: 8] + (use_carry_in ? carry_mask[i] : 1'b0)) > 8'hFF;
                            end
                            6'h13: begin // vmsbc
                                temp_mask_result[i] = (op_a[i*8 +: 8] < (operand_b[i*8 +: 8] + (use_carry_in ? carry_mask[i] : 1'b0)));
                            end
                            
                            default: temp_result[i*8 +: 8] = 8'b0;
                        endcase
                    end else if (i >= vl && vta) begin
                        // Tail agnostic: set tail elements to 1s
                        temp_result[i*8 +: 8] = 8'hFF;
                    end else if (!mask[i] && vma) begin
                        // Mask agnostic: set masked-off elements to 1s
                        temp_result[i*8 +: 8] = 8'hFF;
                    end
                end
            end
            
            `SEW_16: begin
                for (i = 0; i < 32; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            6'h00: temp_result[i*16 +: 16] = op_a[i*16 +: 16] + operand_b[i*16 +: 16];
                            6'h02: temp_result[i*16 +: 16] = op_a[i*16 +: 16] - operand_b[i*16 +: 16];
                            6'h03: temp_result[i*16 +: 16] = operand_b[i*16 +: 16] - op_a[i*16 +: 16];
                            6'h09: temp_result[i*16 +: 16] = op_a[i*16 +: 16] & operand_b[i*16 +: 16];
                            6'h0A: temp_result[i*16 +: 16] = op_a[i*16 +: 16] | operand_b[i*16 +: 16];
                            6'h0B: temp_result[i*16 +: 16] = op_a[i*16 +: 16] ^ operand_b[i*16 +: 16];
                            6'h25: temp_result[i*16 +: 16] = op_a[i*16 +: 16] << operand_b[i*16 +: 4];
                            6'h28: temp_result[i*16 +: 16] = op_a[i*16 +: 16] >> operand_b[i*16 +: 4];
                            6'h29: temp_result[i*16 +: 16] = $signed(op_a[i*16 +: 16]) >>> operand_b[i*16 +: 4];
                            6'h04: temp_result[i*16 +: 16] = (op_a[i*16 +: 16] < operand_b[i*16 +: 16]) ? op_a[i*16 +: 16] : operand_b[i*16 +: 16];
                            6'h06: temp_result[i*16 +: 16] = (op_a[i*16 +: 16] > operand_b[i*16 +: 16]) ? op_a[i*16 +: 16] : operand_b[i*16 +: 16];
                            6'h05: temp_result[i*16 +: 16] = ($signed(op_a[i*16 +: 16]) < $signed(operand_b[i*16 +: 16])) ? op_a[i*16 +: 16] : operand_b[i*16 +: 16];
                            6'h07: temp_result[i*16 +: 16] = ($signed(op_a[i*16 +: 16]) > $signed(operand_b[i*16 +: 16])) ? op_a[i*16 +: 16] : operand_b[i*16 +: 16];
                            6'h25: temp_result[i*16 +: 16] = op_a[i*16 +: 16] * operand_b[i*16 +: 16];
                            
                            // Comparisons
                            6'h18: temp_mask_result[i] = (op_a[i*16 +: 16] == operand_b[i*16 +: 16]);
                            6'h19: temp_mask_result[i] = (op_a[i*16 +: 16] != operand_b[i*16 +: 16]);
                            6'h1A: temp_mask_result[i] = (op_a[i*16 +: 16] < operand_b[i*16 +: 16]);
                            6'h1B: temp_mask_result[i] = ($signed(op_a[i*16 +: 16]) < $signed(operand_b[i*16 +: 16]));
                            6'h1C: temp_mask_result[i] = (op_a[i*16 +: 16] <= operand_b[i*16 +: 16]);
                            6'h1D: temp_mask_result[i] = ($signed(op_a[i*16 +: 16]) <= $signed(operand_b[i*16 +: 16]));
                            
                            default: temp_result[i*16 +: 16] = 16'b0;
                        endcase
                    end else if (i >= vl && vta) begin
                        temp_result[i*16 +: 16] = 16'hFFFF;
                    end else if (!mask[i] && vma) begin
                        temp_result[i*16 +: 16] = 16'hFFFF;
                    end
                end
            end
            
            `SEW_32: begin
                for (i = 0; i < 16; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            6'h00: temp_result[i*32 +: 32] = op_a[i*32 +: 32] + operand_b[i*32 +: 32];
                            6'h02: temp_result[i*32 +: 32] = op_a[i*32 +: 32] - operand_b[i*32 +: 32];
                            6'h03: temp_result[i*32 +: 32] = operand_b[i*32 +: 32] - op_a[i*32 +: 32];
                            6'h09: temp_result[i*32 +: 32] = op_a[i*32 +: 32] & operand_b[i*32 +: 32];
                            6'h0A: temp_result[i*32 +: 32] = op_a[i*32 +: 32] | operand_b[i*32 +: 32];
                            6'h0B: temp_result[i*32 +: 32] = op_a[i*32 +: 32] ^ operand_b[i*32 +: 32];
                            6'h25: temp_result[i*32 +: 32] = op_a[i*32 +: 32] << operand_b[i*32 +: 5];
                            6'h28: temp_result[i*32 +: 32] = op_a[i*32 +: 32] >> operand_b[i*32 +: 5];
                            6'h29: temp_result[i*32 +: 32] = $signed(op_a[i*32 +: 32]) >>> operand_b[i*32 +: 5];
                            6'h04: temp_result[i*32 +: 32] = (op_a[i*32 +: 32] < operand_b[i*32 +: 32]) ? op_a[i*32 +: 32] : operand_b[i*32 +: 32];
                            6'h06: temp_result[i*32 +: 32] = (op_a[i*32 +: 32] > operand_b[i*32 +: 32]) ? op_a[i*32 +: 32] : operand_b[i*32 +: 32];
                            6'h05: temp_result[i*32 +: 32] = ($signed(op_a[i*32 +: 32]) < $signed(operand_b[i*32 +: 32])) ? op_a[i*32 +: 32] : operand_b[i*32 +: 32];
                            6'h07: temp_result[i*32 +: 32] = ($signed(op_a[i*32 +: 32]) > $signed(operand_b[i*32 +: 32])) ? op_a[i*32 +: 32] : operand_b[i*32 +: 32];
                            6'h25: temp_result[i*32 +: 32] = op_a[i*32 +: 32] * operand_b[i*32 +: 32];
                            6'h20: begin // vdivu
                                if (operand_b[i*32 +: 32] == 32'b0) begin
                                    temp_result[i*32 +: 32] = 32'hFFFFFFFF;
                                    divide_by_zero = 1'b1;
                                end else begin
                                    temp_result[i*32 +: 32] = op_a[i*32 +: 32] / operand_b[i*32 +: 32];
                                end
                            end
                            6'h21: begin // vdiv
                                if (operand_b[i*32 +: 32] == 32'b0) begin
                                    temp_result[i*32 +: 32] = 32'hFFFFFFFF;
                                    divide_by_zero = 1'b1;
                                end else begin
                                    temp_result[i*32 +: 32] = $signed(op_a[i*32 +: 32]) / $signed(operand_b[i*32 +: 32]);
                                end
                            end
                            6'h22: begin // vremu
                                if (operand_b[i*32 +: 32] == 32'b0) begin
                                    temp_result[i*32 +: 32] = op_a[i*32 +: 32];
                                end else begin
                                    temp_result[i*32 +: 32] = op_a[i*32 +: 32] % operand_b[i*32 +: 32];
                                end
                            end
                            6'h23: begin // vrem
                                if (operand_b[i*32 +: 32] == 32'b0) begin
                                    temp_result[i*32 +: 32] = op_a[i*32 +: 32];
                                end else begin
                                    temp_result[i*32 +: 32] = $signed(op_a[i*32 +: 32]) % $signed(operand_b[i*32 +: 32]);
                                end
                            end
                            6'h2D: temp_result[i*32 +: 32] = op_c[i*32 +: 32] + (op_a[i*32 +: 32] * operand_b[i*32 +: 32]); // vmacc
                            
                            // Comparisons
                            6'h18: temp_mask_result[i] = (op_a[i*32 +: 32] == operand_b[i*32 +: 32]);
                            6'h19: temp_mask_result[i] = (op_a[i*32 +: 32] != operand_b[i*32 +: 32]);
                            6'h1A: temp_mask_result[i] = (op_a[i*32 +: 32] < operand_b[i*32 +: 32]);
                            6'h1B: temp_mask_result[i] = ($signed(op_a[i*32 +: 32]) < $signed(operand_b[i*32 +: 32]));
                            
                            default: temp_result[i*32 +: 32] = 32'b0;
                        endcase
                    end else if (i >= vl && vta) begin
                        temp_result[i*32 +: 32] = 32'hFFFFFFFF;
                    end else if (!mask[i] && vma) begin
                        temp_result[i*32 +: 32] = 32'hFFFFFFFF;
                    end
                end
            end
            
            `SEW_64: begin
                for (i = 0; i < 8; i = i + 1) begin
                    if (i < vl && (!mask_en || mask[i])) begin
                        case (funct6)
                            6'h00: temp_result[i*64 +: 64] = op_a[i*64 +: 64] + operand_b[i*64 +: 64];
                            6'h02: temp_result[i*64 +: 64] = op_a[i*64 +: 64] - operand_b[i*64 +: 64];
                            6'h09: temp_result[i*64 +: 64] = op_a[i*64 +: 64] & operand_b[i*64 +: 64];
                            6'h0A: temp_result[i*64 +: 64] = op_a[i*64 +: 64] | operand_b[i*64 +: 64];
                            6'h0B: temp_result[i*64 +: 64] = op_a[i*64 +: 64] ^ operand_b[i*64 +: 64];
                            6'h25: temp_result[i*64 +: 64] = op_a[i*64 +: 64] << operand_b[i*64 +: 6];
                            6'h28: temp_result[i*64 +: 64] = op_a[i*64 +: 64] >> operand_b[i*64 +: 6];
                            6'h29: temp_result[i*64 +: 64] = $signed(op_a[i*64 +: 64]) >>> operand_b[i*64 +: 6];
                            6'h04: temp_result[i*64 +: 64] = (op_a[i*64 +: 64] < operand_b[i*64 +: 64]) ? op_a[i*64 +: 64] : operand_b[i*64 +: 64];
                            6'h06: temp_result[i*64 +: 64] = (op_a[i*64 +: 64] > operand_b[i*64 +: 64]) ? op_a[i*64 +: 64] : operand_b[i*64 +: 64];
                            6'h18: temp_mask_result[i] = (op_a[i*64 +: 64] == operand_b[i*64 +: 64]);
                            6'h19: temp_mask_result[i] = (op_a[i*64 +: 64] != operand_b[i*64 +: 64]);
                            default: temp_result[i*64 +: 64] = 64'b0;
                        endcase
                    end else if (i >= vl && vta) begin
                        temp_result[i*64 +: 64] = 64'hFFFFFFFFFFFFFFFF;
                    end else if (!mask[i] && vma) begin
                        temp_result[i*64 +: 64] = 64'hFFFFFFFFFFFFFFFF;
                    end
                end
            end
        endcase
    end
    
    // Register output
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result <= {VLEN{1'b0}};
            mask_result <= {(VLEN/8){1'b0}};
        end else begin
            result <= temp_result;
            mask_result <= temp_mask_result;
        end
    end

endmodule
