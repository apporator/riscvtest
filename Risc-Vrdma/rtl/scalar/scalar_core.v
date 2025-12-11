`include "../common/config.vh"
`include "../common/defines.vh"

module scalar_core (
    input  wire         clk,
    input  wire         rst_n,

    output reg  [31:0]  scalar_addr,
    output reg  [31:0]  scalar_wdata,
    output reg  [3:0]   scalar_wstrb,
    output reg          scalar_valid,
    output reg          scalar_wen,
    input  wire [31:0]  scalar_rdata,
    input  wire         scalar_ready
);

    localparam ALU_ADD  = 4'd0;
    localparam ALU_SUB  = 4'd1;
    localparam ALU_AND  = 4'd2;
    localparam ALU_OR   = 4'd3;
    localparam ALU_XOR  = 4'd4;

    localparam STATE_FETCH_REQ  = 3'd0;
    localparam STATE_FETCH_WAIT = 3'd1;
    localparam STATE_DECODE     = 3'd2;
    localparam STATE_EXECUTE    = 3'd3;
    localparam STATE_MEM_REQ    = 3'd4;
    localparam STATE_MEM_WAIT   = 3'd5;
    localparam STATE_WRITEBACK  = 3'd6;

    reg [2:0]  state;
    reg [31:0] pc;
    reg [31:0] next_pc;
    reg [31:0] inst;
    reg [31:0] regs [0:`NUM_SCALAR_REGS-1];

    wire [6:0] opcode = inst[6:0];
    wire [4:0] rd     = inst[11:7];
    wire [2:0] funct3 = inst[14:12];
    wire [4:0] rs1    = inst[19:15];
    wire [4:0] rs2    = inst[24:20];
    wire [6:0] funct7 = inst[31:25];

    wire [31:0] imm_i = {{20{inst[31]}}, inst[31:20]};
    wire [31:0] imm_s = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    wire [31:0] imm_b = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
    wire [31:0] imm_u = {inst[31:12], 12'b0};
    wire [31:0] imm_j = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};

    reg [31:0] rs1_val;
    reg [31:0] rs2_val;
    reg [31:0] alu_result;
    reg        do_reg_write;
    reg        do_mem_read;
    reg        do_mem_write;
    reg [31:0] mem_addr_reg;
    reg [31:0] mem_wdata_reg;

    integer i;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= STATE_FETCH_REQ;
            pc <= 32'b0;
            next_pc <= 32'h4;
            inst <= 32'h00000013;
            scalar_addr <= 32'b0;
            scalar_wdata <= 32'b0;
            scalar_wstrb <= 4'b0;
            scalar_valid <= 1'b0;
            scalar_wen <= 1'b0;
            alu_result <= 32'b0;
            do_reg_write <= 1'b0;
            do_mem_read <= 1'b0;
            do_mem_write <= 1'b0;
            mem_addr_reg <= 32'b0;
            mem_wdata_reg <= 32'b0;
            rs1_val <= 32'b0;
            rs2_val <= 32'b0;

            for (i = 0; i < `NUM_SCALAR_REGS; i = i + 1) begin
                regs[i] <= 32'b0;
            end
        end else begin
            case (state)
                STATE_FETCH_REQ: begin
                    scalar_addr <= pc;
                    scalar_valid <= 1'b1;
                    scalar_wen <= 1'b0;
                    scalar_wstrb <= 4'b0;
                    state <= STATE_FETCH_WAIT;
                end

                STATE_FETCH_WAIT: begin
                    if (scalar_ready) begin
                        inst <= scalar_rdata;
                        scalar_valid <= 1'b0;
                        state <= STATE_DECODE;
                    end
                end

                STATE_DECODE: begin
                    rs1_val <= (rs1 < `NUM_SCALAR_REGS && rs1 != 5'b0) ? regs[rs1] : 32'b0;
                    rs2_val <= (rs2 < `NUM_SCALAR_REGS && rs2 != 5'b0) ? regs[rs2] : 32'b0;
                    do_reg_write <= 1'b0;
                    do_mem_read <= 1'b0;
                    do_mem_write <= 1'b0;
                    next_pc <= pc + 4;
                    state <= STATE_EXECUTE;
                end

                STATE_EXECUTE: begin
                    case (opcode)
                        `OPCODE_LUI: begin
                            alu_result <= imm_u;
                            do_reg_write <= 1'b1;
                            state <= STATE_WRITEBACK;
                        end

                        `OPCODE_AUIPC: begin
                            alu_result <= pc + imm_u;
                            do_reg_write <= 1'b1;
                            state <= STATE_WRITEBACK;
                        end

                        `OPCODE_JAL: begin
                            alu_result <= pc + 4;
                            next_pc <= pc + imm_j;
                            do_reg_write <= 1'b1;
                            state <= STATE_WRITEBACK;
                        end

                        `OPCODE_JALR: begin
                            alu_result <= pc + 4;
                            next_pc <= (rs1_val + imm_i) & 32'hFFFFFFFE;
                            do_reg_write <= 1'b1;
                            state <= STATE_WRITEBACK;
                        end

                        `OPCODE_BRANCH: begin
                            reg branch_taken;
                            branch_taken = 1'b0;
                            case (funct3)
                                3'b000: branch_taken = (rs1_val == rs2_val);
                                3'b001: branch_taken = (rs1_val != rs2_val);
                                3'b100: branch_taken = ($signed(rs1_val) < $signed(rs2_val));
                                3'b101: branch_taken = ($signed(rs1_val) >= $signed(rs2_val));
                                3'b110: branch_taken = (rs1_val < rs2_val);
                                3'b111: branch_taken = (rs1_val >= rs2_val);
                                default: branch_taken = 1'b0;
                            endcase
                            if (branch_taken) begin
                                next_pc <= pc + imm_b;
                            end
                            state <= STATE_WRITEBACK;
                        end

                        `OPCODE_LOAD: begin
                            mem_addr_reg <= rs1_val + imm_i;
                            do_mem_read <= 1'b1;
                            do_reg_write <= 1'b1;
                            state <= STATE_MEM_REQ;
                        end

                        `OPCODE_STORE: begin
                            mem_addr_reg <= rs1_val + imm_s;
                            mem_wdata_reg <= rs2_val;
                            do_mem_write <= 1'b1;
                            state <= STATE_MEM_REQ;
                        end

                        `OPCODE_OP_IMM: begin
                            case (funct3)
                                3'b000: alu_result <= rs1_val + imm_i;
                                3'b010: alu_result <= ($signed(rs1_val) < $signed(imm_i)) ? 32'd1 : 32'd0;
                                3'b011: alu_result <= (rs1_val < imm_i) ? 32'd1 : 32'd0;
                                3'b100: alu_result <= rs1_val ^ imm_i;
                                3'b110: alu_result <= rs1_val | imm_i;
                                3'b111: alu_result <= rs1_val & imm_i;
                                3'b001: alu_result <= rs1_val << inst[24:20];
                                3'b101: begin
                                    if (funct7[5])
                                        alu_result <= $signed(rs1_val) >>> inst[24:20];
                                    else
                                        alu_result <= rs1_val >> inst[24:20];
                                end
                                default: alu_result <= 32'b0;
                            endcase
                            do_reg_write <= 1'b1;
                            state <= STATE_WRITEBACK;
                        end

                        `OPCODE_OP: begin
                            case (funct3)
                                3'b000: begin
                                    if (funct7[5])
                                        alu_result <= rs1_val - rs2_val;
                                    else
                                        alu_result <= rs1_val + rs2_val;
                                end
                                3'b001: alu_result <= rs1_val << rs2_val[4:0];
                                3'b010: alu_result <= ($signed(rs1_val) < $signed(rs2_val)) ? 32'd1 : 32'd0;
                                3'b011: alu_result <= (rs1_val < rs2_val) ? 32'd1 : 32'd0;
                                3'b100: alu_result <= rs1_val ^ rs2_val;
                                3'b101: begin
                                    if (funct7[5])
                                        alu_result <= $signed(rs1_val) >>> rs2_val[4:0];
                                    else
                                        alu_result <= rs1_val >> rs2_val[4:0];
                                end
                                3'b110: alu_result <= rs1_val | rs2_val;
                                3'b111: alu_result <= rs1_val & rs2_val;
                                default: alu_result <= 32'b0;
                            endcase
                            do_reg_write <= 1'b1;
                            state <= STATE_WRITEBACK;
                        end

                        default: begin
                            state <= STATE_WRITEBACK;
                        end
                    endcase
                end

                STATE_MEM_REQ: begin
                    scalar_addr <= mem_addr_reg;
                    scalar_wdata <= mem_wdata_reg;
                    scalar_wstrb <= do_mem_write ? 4'b1111 : 4'b0000;
                    scalar_wen <= do_mem_write;
                    scalar_valid <= 1'b1;
                    state <= STATE_MEM_WAIT;
                end

                STATE_MEM_WAIT: begin
                    if (scalar_ready) begin
                        if (do_mem_read) begin
                            alu_result <= scalar_rdata;
                        end
                        scalar_valid <= 1'b0;
                        scalar_wen <= 1'b0;
                        scalar_wstrb <= 4'b0;
                        state <= STATE_WRITEBACK;
                    end
                end

                STATE_WRITEBACK: begin
                    if (do_reg_write && rd != 5'b0 && rd < `NUM_SCALAR_REGS) begin
                        regs[rd] <= alu_result;
                    end
                    pc <= next_pc;
                    do_reg_write <= 1'b0;
                    do_mem_read <= 1'b0;
                    do_mem_write <= 1'b0;
                    state <= STATE_FETCH_REQ;
                end

                default: state <= STATE_FETCH_REQ;
            endcase
        end
    end

endmodule
