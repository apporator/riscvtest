`include "../common/config.vh"
`include "../common/defines.vh"

module scalar_core (
    input wire clk,
    input wire rst_n,

    // Scalar memory interface to axi4_master
    output reg [31:0] scalar_addr,
    output reg [31:0] scalar_wdata,
    output reg [3:0]  scalar_wstrb,
    output reg        scalar_valid,
    output reg        scalar_wen,
    input  wire [31:0] scalar_rdata,
    input  wire        scalar_ready
);

    // Simple RV32 scalar core (very small subset for testing)
    // Configuration from common/config.vh: XLEN, NUM_SCALAR_REGS

    // Program counter
    reg [31:0] pc;
    reg [31:0] next_pc;

    // Scalar register file (NUM_SCALAR_REGS registers; x0 hardwired to 0)
    reg [31:0] regs [0:`NUM_SCALAR_REGS-1];

    // Pipeline / control state machine
    localparam S_FETCH  = 3'b000;
    localparam S_DECODE = 3'b001;
    localparam S_EXEC   = 3'b010;
    localparam S_MEM    = 3'b011;
    localparam S_WB     = 3'b100;

    reg [2:0] state;

    // Instruction latch
    reg [31:0] inst;

    // Decoded fields
    wire [6:0] opcode = inst[6:0];
    wire [4:0] rd     = inst[11:7];
    wire [2:0] funct3 = inst[14:12];
    wire [4:0] rs1    = inst[19:15];
    wire [4:0] rs2    = inst[24:20];
    wire [6:0] funct7 = inst[31:25];

    // Immediate encodings
    reg [31:0] imm_i;
    reg [31:0] imm_s;
    reg [31:0] imm_b;
    reg [31:0] imm_u;
    reg [31:0] imm_j;

    // Execution results
    reg [31:0] alu_result;
    reg        branch_taken;

    integer i;

    // Initialize registers on reset
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 32'b0;
            state <= S_FETCH;
            scalar_addr <= 32'b0;
            scalar_wdata <= 32'b0;
            scalar_wstrb <= 4'b0;
            scalar_valid <= 1'b0;
            scalar_wen <= 1'b0;
            inst <= 32'b0;
            alu_result <= 32'b0;
            branch_taken <= 1'b0;
            for (i = 0; i < `NUM_SCALAR_REGS; i = i + 1) begin
                regs[i] <= 32'b0;
            end
        end else begin
            case (state)
                // Fetch instruction from memory using scalar interface (read)
                S_FETCH: begin
                    scalar_addr <= pc;
                    scalar_wen <= 1'b0; // read
                    scalar_valid <= 1'b1;

                    if (scalar_ready && scalar_valid) begin
                        inst <= scalar_rdata;
                        scalar_valid <= 1'b0;
                        state <= S_DECODE;
                    end
                end

                // Decode and prepare immediates
                S_DECODE: begin
                    // Sign-extend immediates
                    imm_i <= {{20{inst[31]}}, inst[31:20]};
                    imm_s <= {{20{inst[31]}}, inst[31:25], inst[11:7]};
                    imm_b <= {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
                    imm_u <= {inst[31:12], 12'b0};
                    imm_j <= {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};

                    // Default next_pc
                    next_pc <= pc + 4;
                    branch_taken <= 1'b0;

                    state <= S_EXEC;
                end

                // Execute ALU / branch calculation or start memory access
                S_EXEC: begin
                    case (opcode)
                        `OPCODE_LUI: begin
                            alu_result <= imm_u;
                            state <= S_WB;
                        end

                        `OPCODE_AUIPC: begin
                            alu_result <= pc + imm_u;
                            state <= S_WB;
                        end

                        `OPCODE_JAL: begin
                            alu_result <= pc + 4; // rd = return address
                            next_pc <= pc + imm_j;
                            branch_taken <= 1'b1;
                            state <= S_WB;
                        end

                        `OPCODE_JALR: begin
                            alu_result <= pc + 4;
                            next_pc <= (regs[rs1] + imm_i) & ~32'b1;
                            branch_taken <= 1'b1;
                            state <= S_WB;
                        end

                        `OPCODE_BRANCH: begin
                            // Only implement BEQ for now
                            if (funct3 == 3'b000) begin // BEQ
                                if (regs[rs1] == regs[rs2]) begin
                                    next_pc <= pc + imm_b;
                                    branch_taken <= 1'b1;
                                end
                            end
                            state <= S_WB;
                        end

                        `OPCODE_LOAD: begin
                            // Only implement LW (funct3==010)
                            if (funct3 == 3'b010) begin
                                scalar_addr <= regs[rs1] + imm_i;
                                scalar_wen <= 1'b0; // read
                                scalar_valid <= 1'b1;
                                state <= S_MEM;
                            end else begin
                                // Unsupported load - treat as NOP
                                state <= S_WB;
                            end
                        end

                        `OPCODE_STORE: begin
                            // Only implement SW (funct3==010)
                            if (funct3 == 3'b010) begin
                                scalar_addr <= regs[rs1] + imm_s;
                                scalar_wdata <= regs[rs2];
                                scalar_wstrb <= 4'b1111;
                                scalar_wen <= 1'b1; // write
                                scalar_valid <= 1'b1;
                                state <= S_MEM;
                            end else begin
                                // Unsupported store - treat as NOP
                                state <= S_WB;
                            end
                        end

                        `OPCODE_OP_IMM: begin
                            // Only implement ADDI
                            if (funct3 == 3'b000) begin
                                alu_result <= regs[rs1] + imm_i;
                            end else begin
                                alu_result <= 32'b0;
                            end
                            state <= S_WB;
                        end

                        `OPCODE_OP: begin
                            // Register-register ALU: implement ADD/SUB/AND/OR/XOR
                            case (funct3)
                                3'b000: begin
                                    if (funct7 == 7'b0100000) // SUB
                                        alu_result <= regs[rs1] - regs[rs2];
                                    else // ADD
                                        alu_result <= regs[rs1] + regs[rs2];
                                end
                                3'b111: alu_result <= regs[rs1] & regs[rs2];
                                3'b110: alu_result <= regs[rs1] | regs[rs2];
                                3'b100: alu_result <= regs[rs1] ^ regs[rs2];
                                default: alu_result <= 32'b0;
                            endcase
                            state <= S_WB;
                        end

                        default: begin
                            // Unrecognized opcode - treat as NOP
                            state <= S_WB;
                        end
                    endcase
                end

                // Wait for memory operation to complete
                S_MEM: begin
                    if (scalar_ready && scalar_valid) begin
                        scalar_valid <= 1'b0;
                        scalar_wen <= 1'b0;
                        // If this was a load, capture rdata into alu_result for WB
                        if (opcode == `OPCODE_LOAD) begin
                            alu_result <= scalar_rdata;
                        end
                        state <= S_WB;
                    end
                end

                // Write back to register file and advance PC
                S_WB: begin
                    // Write result to rd if rd != 0 and opcode writes rd
                    case (opcode)
                        `OPCODE_STORE, `OPCODE_BRANCH: begin
                            // do not write rd
                        end
                        default: begin
                            if (rd != 5'b0 && rd < `NUM_SCALAR_REGS) begin
                                regs[rd] <= alu_result;
                            end
                        end
                    endcase

                    // Update PC
                    if (branch_taken) begin
                        pc <= next_pc;
                    end else begin
                        pc <= pc + 4;
                    end

                    // Return to fetch
                    state <= S_FETCH;
                end

                default: state <= S_FETCH;
            endcase
        end
    end

    // Simple combinational read ports for register file
    // For out-of-range rs we return zero
    // Note: regs[0] is always zero by convention
    wire [31:0] rs1_val = (rs1 < `NUM_SCALAR_REGS) ? regs[rs1] : 32'b0;
    wire [31:0] rs2_val = (rs2 < `NUM_SCALAR_REGS) ? regs[rs2] : 32'b0;

    // These wires are unused in the current simple core but may help later integration
    // Keep synthesis clean by referencing them to avoid warnings
    always @(*) begin
        // noop - allow tools to see rs1_val/rs2_val used
        // (they are already referenced via regs in the sequential logic above)
    end

endmodule
