//==============================================================================
// Vector Configuration Unit
// Implements vsetvli, vsetivli, vsetvl instructions
// Calculates vl based on AVL, VLEN, SEW, and LMUL
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_config (
    input wire clk,
    input wire rst_n,
    
    // Configuration instruction inputs
    input wire        cfg_valid,
    input wire [1:0]  cfg_type,    // 00=vsetvli, 01=vsetivli, 10=vsetvl
    input wire [31:0] avl,         // Application Vector Length (from rs1 or zimm)
    input wire [10:0] vtypei,      // vtype immediate field
    input wire [4:0]  rd_addr,     // Destination register
    
    // Current vtype register
    input wire [31:0] vtype_in,
    
    // Outputs
    output reg [31:0] vl_out,      // Calculated vector length
    output reg [31:0] vtype_out,   // New vtype value
    output reg        vl_we,       // Write enable for vl CSR
    output reg        vtype_we,    // Write enable for vtype CSR
    output reg [31:0] rd_data,     // Value to write to rd (new vl)
    output reg        rd_we,       // Write enable for rd
    output reg        vill         // Illegal vtype indicator
);

    // Extract vtype fields from vtypei
    wire       vma_req  = vtypei[7];    // Vector mask agnostic
    wire       vta_req  = vtypei[6];    // Vector tail agnostic
    wire [2:0] vsew_req = vtypei[5:3];  // Selected element width
    wire [2:0] vlmul_req = vtypei[2:0]; // Vector register group multiplier
    
    // Extract current vtype fields
    wire       vill_cur = vtype_in[31];
    wire [2:0] vsew_cur = vtype_in[5:3];
    wire [2:0] vlmul_cur = vtype_in[2:0];
    
    // Calculate SEW from vsew encoding
    wire [6:0] sew = (vsew_req == 3'b000) ? 7'd8  :
                     (vsew_req == 3'b001) ? 7'd16 :
                     (vsew_req == 3'b010) ? 7'd32 :
                     (vsew_req == 3'b011) ? 7'd64 : 7'd0; // Invalid
    
    // VLMAX calculation: VLMAX = (VLEN / SEW) * LMUL
    // For fractional LMUL: LMUL = 1/2^n, so VLMAX = (VLEN / SEW) / 2^n
    reg [31:0] vlmax;
    wire [31:0] vlen_div_sew = `VLEN / sew;
    
    always @(*) begin
        case (vlmul_req)
            3'b000: vlmax = vlen_div_sew;        // LMUL = 1
            3'b001: vlmax = vlen_div_sew << 1;   // LMUL = 2
            3'b010: vlmax = vlen_div_sew << 2;   // LMUL = 4
            3'b011: vlmax = vlen_div_sew << 3;   // LMUL = 8
            3'b101: vlmax = vlen_div_sew >> 1;   // LMUL = 1/2
            3'b110: vlmax = vlen_div_sew >> 2;   // LMUL = 1/4
            3'b111: vlmax = vlen_div_sew >> 3;   // LMUL = 1/8
            default: vlmax = 32'b0;              // Reserved (3'b100)
        endcase
    end
    
    // Check for illegal vtype combinations
    wire illegal_sew = (sew == 7'd0) || (sew > `ELEN);
    wire illegal_lmul = (vlmul_req == 3'b100); // Reserved encoding
    wire illegal_vtype = illegal_sew || illegal_lmul;
    
    // Calculate new vl based on AVL and VLMAX
    // Rules from RVV spec:
    // - If AVL <= VLMAX, vl = AVL
    // - If AVL > VLMAX, vl = VLMAX
    // - If AVL = 0 and rd != 0, vl = VLMAX
    // - If AVL = 0 and rd == 0, keep current vl (if vtype unchanged)
    reg [31:0] new_vl;
    reg [31:0] current_vl_reg;  // Registered version to avoid combinational loop
    
    always @(*) begin
        if (illegal_vtype) begin
            new_vl = 32'b0;
        end else if (avl == 32'b0 && rd_addr == 5'b0 && cfg_type != 2'b01) begin
            // Special case: rd=x0, rs1=x0 → keep current vl if vtype unchanged
            if (vtypei == vtype_in[10:0]) begin
                new_vl = current_vl_reg; // Use registered vl
            end else begin
                new_vl = vlmax;
            end
        end else if (avl == 32'b0) begin
            // rd != 0, avl = 0 → set to VLMAX
            new_vl = vlmax;
        end else if (avl > vlmax) begin
            new_vl = vlmax;
        end else begin
            new_vl = avl;
        end
    end
    
    // Update vl and vtype CSRs
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            vl_out <= 32'b0;
            vtype_out <= 32'b0;
            vl_we <= 1'b0;
            vtype_we <= 1'b0;
            rd_data <= 32'b0;
            rd_we <= 1'b0;
            vill <= 1'b0;
            current_vl_reg <= 32'b0;
        end else begin
            // Always capture current vl for retention logic
            current_vl_reg <= vl_out;
            
            if (cfg_valid) begin
                vill <= illegal_vtype;
                
                if (illegal_vtype) begin
                    // Set vill bit, set vl to 0
                    vl_out <= 32'b0;
                    vtype_out <= {1'b1, 31'b0}; // vill = 1
                    vl_we <= 1'b1;
                    vtype_we <= 1'b1;
                    rd_data <= 32'b0;
                    rd_we <= (rd_addr != 5'b0);
                end else begin
                    // Normal configuration
                    vl_out <= new_vl;
                    vtype_out <= {1'b0, 23'b0, vma_req, vta_req, vsew_req, vlmul_req};
                    vl_we <= 1'b1;
                    vtype_we <= 1'b1;
                    rd_data <= new_vl; // Write new vl to rd
                    rd_we <= (rd_addr != 5'b0);
                end
            end else begin
                vl_we <= 1'b0;
                vtype_we <= 1'b0;
                rd_we <= 1'b0;
            end
        end
    end

endmodule
