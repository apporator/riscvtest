//==============================================================================
// Vector Mask Operations Unit
// Supports vcpop.m, vfirst.m, vmsbf.m, vmsif.m, vmsof.m, viota.m, vid.v
// and mask-register logical operations
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_mask_unit #(
    parameter VLEN = `VLEN
)(
    input wire clk,
    input wire rst_n,
    
    // Control
    input wire [5:0]       funct6,
    input wire [4:0]       vs2_op,     // Operation encoding from vs2 field
    input wire [2:0]       sew,
    input wire [31:0]      vl,
    
    // Operands
    input wire [VLEN/8-1:0] mask_a,    // First mask operand
    input wire [VLEN/8-1:0] mask_b,    // Second mask operand
    input wire [VLEN-1:0]   vec_src,   // Vector source for some ops
    
    // Results
    output reg [VLEN/8-1:0] mask_result,
    output reg [31:0]       scalar_result,  // For vcpop, vfirst
    output reg [VLEN-1:0]   vec_result,     // For viota, vid
    output reg              valid
);

    integer i;
    
    // Mask logical operations
    always @(*) begin
        mask_result = {(VLEN/8){1'b0}};
        scalar_result = 32'b0;
        vec_result = {VLEN{1'b0}};
        valid = 1'b1;
        
        case (funct6)
            //------------------------------------------------------------------
            // Mask-Register Logical Operations (mm suffix)
            //------------------------------------------------------------------
            6'h18: mask_result = mask_a & ~mask_b;  // vmandnot.mm
            6'h19: mask_result = mask_a & mask_b;   // vmand.mm
            6'h1A: mask_result = mask_a | mask_b;   // vmor.mm
            6'h1B: mask_result = mask_a ^ mask_b;   // vmxor.mm
            6'h1C: mask_result = mask_a | ~mask_b;  // vmornot.mm
            6'h1D: mask_result = ~(mask_a & mask_b); // vmnand.mm
            6'h1E: mask_result = ~(mask_a | mask_b); // vmnor.mm
            6'h1F: mask_result = ~(mask_a ^ mask_b); // vmxnor.mm
            
            //------------------------------------------------------------------
            // Mask Population Count and Find-First
            //------------------------------------------------------------------
            6'h10: begin // vmunary0 group
                case (vs2_op)
                    5'b00010: begin // vcpop.m - Count population of mask
                        for (i = 0; i < VLEN/8; i = i + 1) begin
                            if (i < vl && mask_a[i]) begin
                                scalar_result = scalar_result + 1;
                            end
                        end
                    end
                    
                    5'b00011: begin // vfirst.m - Find first set bit
                        scalar_result = 32'hFFFFFFFF; // Default: -1 (not found)
                        for (i = 0; i < VLEN/8; i = i + 1) begin
                            if (i < vl && mask_a[i] && scalar_result == 32'hFFFFFFFF) begin
                                scalar_result = i;
                            end
                        end
                    end
                    
                    default: scalar_result = 32'b0;
                endcase
            end
            
            //------------------------------------------------------------------
            // Mask Set-Before-First, Set-Including-First, Set-Only-First
            //------------------------------------------------------------------
            6'h12: begin // vmunary0 group (mask transformations)
                case (vs2_op)
                    5'b00001: begin // vmsbf.m - Set-before-first
                        reg first_found;
                        first_found = 1'b0;
                        for (i = 0; i < VLEN/8; i = i + 1) begin
                            if (i < vl) begin
                                if (!first_found && !mask_a[i]) begin
                                    mask_result[i] = 1'b1;
                                end else begin
                                    first_found = 1'b1;
                                    mask_result[i] = 1'b0;
                                end
                            end
                        end
                    end
                    
                    5'b00010: begin // vmsif.m - Set-including-first
                        reg first_found;
                        first_found = 1'b0;
                        for (i = 0; i < VLEN/8; i = i + 1) begin
                            if (i < vl) begin
                                if (!first_found) begin
                                    mask_result[i] = 1'b1;
                                    if (mask_a[i]) begin
                                        first_found = 1'b1;
                                    end
                                end else begin
                                    mask_result[i] = 1'b0;
                                end
                            end
                        end
                    end
                    
                    5'b00011: begin // vmsof.m - Set-only-first
                        reg first_found;
                        first_found = 1'b0;
                        for (i = 0; i < VLEN/8; i = i + 1) begin
                            if (i < vl) begin
                                if (!first_found && mask_a[i]) begin
                                    mask_result[i] = 1'b1;
                                    first_found = 1'b1;
                                end else begin
                                    mask_result[i] = 1'b0;
                                end
                            end
                        end
                    end
                    
                    //----------------------------------------------------------
                    // Iota and ID operations
                    //----------------------------------------------------------
                    5'b10000: begin // viota.m - Iota (index of set bits)
                        reg [31:0] count;
                        count = 32'b0;
                        case (sew)
                            `SEW_8: begin
                                for (i = 0; i < 64; i = i + 1) begin
                                    if (i < vl) begin
                                        if (mask_a[i]) begin
                                            vec_result[i*8 +: 8] = count[7:0];
                                            count = count + 1;
                                        end else begin
                                            vec_result[i*8 +: 8] = 8'b0;
                                        end
                                    end
                                end
                            end
                            `SEW_16: begin
                                for (i = 0; i < 32; i = i + 1) begin
                                    if (i < vl) begin
                                        if (mask_a[i]) begin
                                            vec_result[i*16 +: 16] = count[15:0];
                                            count = count + 1;
                                        end else begin
                                            vec_result[i*16 +: 16] = 16'b0;
                                        end
                                    end
                                end
                            end
                            `SEW_32: begin
                                for (i = 0; i < 16; i = i + 1) begin
                                    if (i < vl) begin
                                        if (mask_a[i]) begin
                                            vec_result[i*32 +: 32] = count;
                                            count = count + 1;
                                        end else begin
                                            vec_result[i*32 +: 32] = 32'b0;
                                        end
                                    end
                                end
                            end
                            `SEW_64: begin
                                for (i = 0; i < 8; i = i + 1) begin
                                    if (i < vl) begin
                                        if (mask_a[i]) begin
                                            vec_result[i*64 +: 64] = {32'b0, count};
                                            count = count + 1;
                                        end else begin
                                            vec_result[i*64 +: 64] = 64'b0;
                                        end
                                    end
                                end
                            end
                        endcase
                    end
                    
                    5'b10001: begin // vid.v - Element index
                        case (sew)
                            `SEW_8: begin
                                for (i = 0; i < 64; i = i + 1) begin
                                    if (i < vl) begin
                                        vec_result[i*8 +: 8] = i[7:0];
                                    end
                                end
                            end
                            `SEW_16: begin
                                for (i = 0; i < 32; i = i + 1) begin
                                    if (i < vl) begin
                                        vec_result[i*16 +: 16] = i[15:0];
                                    end
                                end
                            end
                            `SEW_32: begin
                                for (i = 0; i < 16; i = i + 1) begin
                                    if (i < vl) begin
                                        vec_result[i*32 +: 32] = i;
                                    end
                                end
                            end
                            `SEW_64: begin
                                for (i = 0; i < 8; i = i + 1) begin
                                    if (i < vl) begin
                                        vec_result[i*64 +: 64] = {32'b0, i[31:0]};
                                    end
                                end
                            end
                        endcase
                    end
                    
                    default: begin
                        mask_result = {(VLEN/8){1'b0}};
                        vec_result = {VLEN{1'b0}};
                    end
                endcase
            end
            
            default: begin
                mask_result = {(VLEN/8){1'b0}};
                scalar_result = 32'b0;
                vec_result = {VLEN{1'b0}};
            end
        endcase
    end

endmodule
