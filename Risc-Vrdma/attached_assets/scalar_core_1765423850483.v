`include "../common/config.vh"
`include "../common/defines.vh"

module scalar_core (
    input  wire         clk,
    input  wire         rst_n,

    // Scalar memory interface to axi4_master
    output reg  [31:0]  scalar_addr,
    output reg  [31:0]  scalar_wdata,
    output reg  [3:0]   scalar_wstrb,
    output reg          scalar_valid,
    output reg          scalar_wen,
    input  wire [31:0]  scalar_rdata,
    input  wire         scalar_ready
);
	reg [31:0] forward_a;
	reg [31:0] forward_b;
    // 5-stage pipelined RV32I-like scalar core (minimal subset)
    // Stages: IF -> ID -> EX -> MEM -> WB

    // Program counter
    reg [31:0] pc;

    // Register file (NUM_SCALAR_REGS entries; recommend setting to 32 in config.vh)
    reg [31:0] regs [0:`NUM_SCALAR_REGS-1];

    // Pipeline registers
    // IF/ID
    reg [31:0] if_id_pc;
    reg [31:0] if_id_inst;

    // ID/EX
    reg [31:0] id_ex_pc;
    reg [31:0] id_ex_rs1_val;
    reg [31:0] id_ex_rs2_val;
    reg [4:0]  id_ex_rs1;
    reg [4:0]  id_ex_rs2;
    reg [4:0]  id_ex_rd;
    reg [6:0]  id_ex_opcode;
    reg [2:0]  id_ex_funct3;
    reg [6:0]  id_ex_funct7;
    reg [31:0] id_ex_imm;
    // control signals
    reg        id_ex_reg_write;
    reg        id_ex_mem_read;
    reg        id_ex_mem_write;
    reg        id_ex_alu_src; // 1 => imm
    reg [3:0]  id_ex_alu_op;  // simple code for ADD,SUB,AND,OR,XOR
    reg        id_ex_branch;
    reg        id_ex_jump;

    // EX/MEM
    reg [31:0] ex_mem_pc;
    reg [31:0] ex_mem_alu_result;
    reg [31:0] ex_mem_rs2_val; // for stores
    reg [4:0]  ex_mem_rd;
    reg        ex_mem_reg_write;
    reg        ex_mem_mem_read;
    reg        ex_mem_mem_write;

    // MEM/WB
    reg [31:0] mem_wb_pc;
    reg [31:0] mem_wb_alu_result;
    reg [31:0] mem_wb_mem_rdata;
    reg [4:0]  mem_wb_rd;
    reg        mem_wb_reg_write;
    reg        mem_wb_mem_read;

    // Control for stalling and flushing
    reg stall;      // freeze IF/ID and PC
    reg flush_ifid; // used to flush after branch taken

    // Instruction decode wires
    wire [6:0] if_opcode = if_id_inst[6:0];
    wire [4:0] if_rd     = if_id_inst[11:7];
    wire [2:0] if_funct3 = if_id_inst[14:12];
    wire [4:0] if_rs1    = if_id_inst[19:15];
    wire [4:0] if_rs2    = if_id_inst[24:20];
    wire [6:0] if_funct7 = if_id_inst[31:25];

    // Forwarded operand values for EX stage
    reg [31:0] alu_src1;
    reg [31:0] alu_src2;

    // Decoded immediates in ID stage
    reg [31:0] imm_i;
    reg [31:0] imm_s;
    reg [31:0] imm_b;
    reg [31:0] imm_u;
    reg [31:0] imm_j;

    // ALU operation encoding
    localparam ALU_ADD  = 4'd0;
    localparam ALU_SUB  = 4'd1;
    localparam ALU_AND  = 4'd2;
    localparam ALU_OR   = 4'd3;
    localparam ALU_XOR  = 4'd4;

    integer i;

    // Initialize state
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 32'b0;
            if_id_pc <= 32'b0;
            if_id_inst <= 32'b0;

            id_ex_pc <= 32'b0;
            id_ex_rs1_val <= 32'b0;
            id_ex_rs2_val <= 32'b0;
            id_ex_rs1 <= 5'b0;
            id_ex_rs2 <= 5'b0;
            id_ex_rd <= 5'b0;
            id_ex_opcode <= 7'b0;
            id_ex_funct3 <= 3'b0;
            id_ex_funct7 <= 7'b0;
            id_ex_imm <= 32'b0;
            id_ex_reg_write <= 1'b0;
            id_ex_mem_read <= 1'b0;
            id_ex_mem_write <= 1'b0;
            id_ex_alu_src <= 1'b0;
            id_ex_alu_op <= ALU_ADD;
            id_ex_branch <= 1'b0;
            id_ex_jump <= 1'b0;

            ex_mem_pc <= 32'b0;
            ex_mem_alu_result <= 32'b0;
            ex_mem_rs2_val <= 32'b0;
            ex_mem_rd <= 5'b0;
            ex_mem_reg_write <= 1'b0;
            ex_mem_mem_read <= 1'b0;
            ex_mem_mem_write <= 1'b0;

            mem_wb_pc <= 32'b0;
            mem_wb_alu_result <= 32'b0;
            mem_wb_mem_rdata <= 32'b0;
            mem_wb_rd <= 5'b0;
            mem_wb_reg_write <= 1'b0;
            mem_wb_mem_read <= 1'b0;

            stall <= 1'b0;
            flush_ifid <= 1'b0;

            scalar_addr <= 32'b0;
            scalar_wdata <= 32'b0;
            scalar_wstrb <= 4'b0;
            scalar_valid <= 1'b0;
            scalar_wen <= 1'b0;

            for (i = 0; i < `NUM_SCALAR_REGS; i = i + 1) begin
                regs[i] <= 32'b0;
            end
        end else begin
            // Default control signals
            if (flush_ifid) begin
                if_id_inst <= 32'b0; // flush instruction (becomes NOP)
                if_id_pc <= 32'b0;
                flush_ifid <= 1'b0;
            end

            // ------------------ WB stage ------------------
            if (mem_wb_reg_write && mem_wb_rd != 5'b0 && mem_wb_rd < `NUM_SCALAR_REGS) begin
                if (mem_wb_mem_read) begin
                    regs[mem_wb_rd] <= mem_wb_mem_rdata;
                end else begin
                    regs[mem_wb_rd] <= mem_wb_alu_result;
                end
            end

            // ------------------ MEM stage ------------------
            // Handle memory interface: if EX stage requested mem access, it's initiated here
            // Note: ex_mem_mem_read/ex_mem_mem_write indicate the operation for the current MEM stage
            if (ex_mem_mem_read || ex_mem_mem_write) begin
                // If there is already a pending scalar transaction, keep asserting until scalar_ready
                if (!scalar_valid) begin
                    scalar_addr <= ex_mem_alu_result; // address computed in EX
                    scalar_wdata <= ex_mem_rs2_val;
                    scalar_wstrb <= 4'b1111;
                    scalar_wen <= ex_mem_mem_write;
                    scalar_valid <= 1'b1;
                end else begin
                    if (scalar_ready) begin
                        // capture read data if read
                        if (ex_mem_mem_read) begin
                            mem_wb_mem_rdata <= scalar_rdata;
                        end
                        scalar_valid <= 1'b0;
                        scalar_wen <= 1'b0;
                        scalar_wstrb <= 4'b0;
                    end
                end
            end else begin
                // No memory operation this cycle
                scalar_valid <= 1'b0;
                scalar_wen <= 1'b0;
                scalar_wstrb <= 4'b0;
            end

            // ------------------ EX stage result -> EX/MEM regs ------------------
            ex_mem_pc <= id_ex_pc;
            ex_mem_rd <= id_ex_rd;
            ex_mem_reg_write <= id_ex_reg_write;
            ex_mem_mem_read <= id_ex_mem_read;
            ex_mem_mem_write <= id_ex_mem_write;
            ex_mem_rs2_val <= id_ex_rs2_val;

            // Compute ALU inputs with forwarding
            // Forward from MEM/WB


            // Forwarding for rs1
            if (id_ex_rs1 != 5'b0 && id_ex_rs1 == ex_mem_rd && ex_mem_reg_write) begin
                forward_a = ex_mem_alu_result;
            end else if (id_ex_rs1 != 5'b0 && id_ex_rs1 == mem_wb_rd && mem_wb_reg_write) begin
                if (mem_wb_mem_read)
                    forward_a = mem_wb_mem_rdata;
                else
                    forward_a = mem_wb_alu_result;
            end else begin
                forward_a = id_ex_rs1_val;
            end

            // Forwarding for rs2
            if (id_ex_rs2 != 5'b0 && id_ex_rs2 == ex_mem_rd && ex_mem_reg_write) begin
                forward_b = ex_mem_alu_result;
            end else if (id_ex_rs2 != 5'b0 && id_ex_rs2 == mem_wb_rd && mem_wb_reg_write) begin
                if (mem_wb_mem_read)
                    forward_b = mem_wb_mem_rdata;
                else
                    forward_b = mem_wb_alu_result;
            end else begin
                forward_b = id_ex_rs2_val;
            end

            // Select ALU operands
            alu_src1 <= forward_a;
            alu_src2 <= id_ex_alu_src ? id_ex_imm : forward_b;

            // Perform ALU operation combinationally and register into ex_mem_alu_result
            case (id_ex_alu_op)
                ALU_ADD:  ex_mem_alu_result <= alu_src1 + alu_src2;
                ALU_SUB:  ex_mem_alu_result <= alu_src1 - alu_src2;
                ALU_AND:  ex_mem_alu_result <= alu_src1 & alu_src2;
                ALU_OR:   ex_mem_alu_result <= alu_src1 | alu_src2;
                ALU_XOR:  ex_mem_alu_result <= alu_src1 ^ alu_src2;
                default:  ex_mem_alu_result <= alu_src1 + alu_src2;
            endcase

            // ------------------ MEM/WB pipeline regs ------------------
            mem_wb_pc <= ex_mem_pc;
            mem_wb_alu_result <= ex_mem_alu_result;
            mem_wb_rd <= ex_mem_rd;
            mem_wb_reg_write <= ex_mem_reg_write;
            mem_wb_mem_read <= ex_mem_mem_read;

            // ------------------ ID stage -> ID/EX pipeline regs ------------------
            if (!stall) begin
                id_ex_pc <= if_id_pc;
                id_ex_rs1_val <= regs[if_rs1 < `NUM_SCALAR_REGS ? if_rs1 : 0];
                id_ex_rs2_val <= regs[if_rs2 < `NUM_SCALAR_REGS ? if_rs2 : 0];
                id_ex_rs1 <= if_rs1;
                id_ex_rs2 <= if_rs2;
                id_ex_rd <= if_rd;
                id_ex_opcode <= if_opcode;
                id_ex_funct3 <= if_funct3;
                id_ex_funct7 <= if_funct7;
                id_ex_imm <= 32'b0;
                id_ex_reg_write <= 1'b0;
                id_ex_mem_read <= 1'b0;
                id_ex_mem_write <= 1'b0;
                id_ex_alu_src <= 1'b0;
                id_ex_alu_op <= ALU_ADD;
                id_ex_branch <= 1'b0;
                id_ex_jump <= 1'b0;

                // Decode control and imm
                imm_i <= {{20{if_id_inst[31]}}, if_id_inst[31:20]};
                imm_s <= {{20{if_id_inst[31]}}, if_id_inst[31:25], if_id_inst[11:7]};
                imm_b <= {{19{if_id_inst[31]}}, if_id_inst[31], if_id_inst[7], if_id_inst[30:25], if_id_inst[11:8], 1'b0};
                imm_u <= {if_id_inst[31:12], 12'b0};
                imm_j <= {{11{if_id_inst[31]}}, if_id_inst[31], if_id_inst[19:12], if_id_inst[20], if_id_inst[30:21], 1'b0};

                case (if_opcode)
                    `OPCODE_LUI: begin
                        id_ex_imm <= imm_u;
                        id_ex_reg_write <= 1'b1;
                        id_ex_alu_src <= 1'b1;
                        id_ex_alu_op <= ALU_ADD; // ALU passes imm
                    end
                    `OPCODE_AUIPC: begin
                        id_ex_imm <= imm_u;
                        id_ex_reg_write <= 1'b1;
                        id_ex_alu_src <= 1'b1;
                        id_ex_alu_op <= ALU_ADD; // ALU will add pc + imm in EX
                    end
                    `OPCODE_JAL: begin
                        id_ex_imm <= imm_j;
                        id_ex_reg_write <= 1'b1;
                        id_ex_jump <= 1'b1;
                    end
                    `OPCODE_JALR: begin
                        id_ex_imm <= imm_i;
                        id_ex_reg_write <= 1'b1;
                        id_ex_jump <= 1'b1;
                    end
                    `OPCODE_BRANCH: begin
                        id_ex_branch <= 1'b1;
                        // only BEQ implemented
                        id_ex_alu_op <= ALU_SUB;
                    end
                    `OPCODE_LOAD: begin
                        // LW (funct3==010)
                        if (if_funct3 == 3'b010) begin
                            id_ex_mem_read <= 1'b1;
                            id_ex_reg_write <= 1'b1;
                            id_ex_alu_src <= 1'b1;
                            id_ex_imm <= imm_i;
                            id_ex_alu_op <= ALU_ADD; // compute address
                        end
                    end
                    `OPCODE_STORE: begin
                        // SW (funct3==010)
                        if (if_funct3 == 3'b010) begin
                            id_ex_mem_write <= 1'b1;
                            id_ex_alu_src <= 1'b1;
                            id_ex_imm <= imm_s;
                            id_ex_alu_op <= ALU_ADD; // compute address
                        end
                    end
                    `OPCODE_OP_IMM: begin
                        // ADDI
                        if (if_funct3 == 3'b000) begin
                            id_ex_reg_write <= 1'b1;
                            id_ex_alu_src <= 1'b1;
                            id_ex_imm <= imm_i;
                            id_ex_alu_op <= ALU_ADD;
                        end
                    end
                    `OPCODE_OP: begin
                        // Register-register ops
                        case (if_funct3)
                            3'b000: begin
                                if (if_funct7 == 7'b0100000) id_ex_alu_op <= ALU_SUB; else id_ex_alu_op <= ALU_ADD;
                                id_ex_reg_write <= 1'b1;
                            end
                            3'b111: begin id_ex_alu_op <= ALU_AND; id_ex_reg_write <= 1'b1; end
                            3'b110: begin id_ex_alu_op <= ALU_OR;  id_ex_reg_write <= 1'b1; end
                            3'b100: begin id_ex_alu_op <= ALU_XOR; id_ex_reg_write <= 1'b1; end
                            default: begin id_ex_reg_write <= 1'b0; end
                        endcase
                    end
                    default: begin
                        // NOP or unimplemented
                    end
                endcase
            end // !stall

            // ------------------ IF stage / PC update ------------------
            if (!stall) begin
                if (id_ex_jump) begin
                    // JAL/JALR handled via EX stage - flush IF/ID and set pc in EX result when branch/jump taken
                    // We don't update PC here for jump; EX will assert flush and new PC
                end else begin
                    if (ex_mem_mem_read && scalar_valid) begin
                        // If memory operation in progress, stall fetching new instructions to avoid overwhelming scalar interface
                    end
                    // Default: PC increments; however branch resolution happens in EX and will set flush_ifid when taken
                    pc <= pc + 4;
                end
            end

            // ------------------ IF/ID update ------------------
            if (!stall) begin
                if_id_pc <= pc;
                if_id_inst <= 32'h00000013; // default NOP
            end

            // Compute stall conditions: load-use hazard
            stall <= 1'b0;
            // If ID/EX is a load and its rd matches rs1 or rs2 of IF_ID, stall one cycle
            if (id_ex_mem_read && (id_ex_rd != 5'b0) && ( (id_ex_rd == if_rs1) || (id_ex_rd == if_rs2) )) begin
                stall <= 1'b1;
            end

            // Branch resolution and flush: simple scheme
            // If EX stage indicates branch taken (e.g., zero from ALU subtraction), we flush IF/ID and set PC
            // For simplicity, branch detection uses ex_mem_alu_result == 0 for BEQ
            if (id_ex_branch) begin
                // evaluate branch condition using forwarded values
                if (forward_a - forward_b == 0) begin
                    // branch taken: compute target = id_ex_pc + id_ex_imm
                    pc <= id_ex_pc + id_ex_imm;
                    flush_ifid <= 1'b1;
                end
            end

            // Note: This simplified control will need refinement
        end
    end

endmodule
