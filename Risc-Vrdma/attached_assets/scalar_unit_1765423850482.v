//==============================================================================
// Scalar Unit - RV32E Base Integer ISA
// 2-stage pipeline: Fetch-Decode, Execute
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module scalar_unit (
    input wire clk,
    input wire rst_n,
    
    // Memory interface
    output reg [31:0] mem_addr,
    output reg [31:0] mem_wdata,
    output reg [3:0]  mem_wstrb,
    output reg        mem_valid,
    output reg        mem_wen,
    input  wire [31:0] mem_rdata,
    input  wire       mem_ready,
    
    // Vector CSR interface
    output reg [31:0] vl_write_data,
    output reg        vl_write_en,
    output reg [31:0] vtype_write_data,
    output reg        vtype_write_en,
    
    // Debug
    output wire [31:0] debug_pc,
    output wire        debug_valid
);

    // Program counter
    reg [31:0] pc;
    reg [31:0] next_pc;
    
    // Pipeline registers
    reg [31:0] fd_pc;
    reg [31:0] fd_inst;
    reg        fd_valid;
    
    // Register file (RV32E - 16 registers)
    reg [31:0] regfile [0:15];
    integer i;
    
    // Instruction decode
    wire [6:0]  opcode = fd_inst[6:0];
    wire [4:0]  rd     = fd_inst[11:7];
    wire [2:0]  funct3 = fd_inst[14:12];
    wire [4:0]  rs1    = fd_inst[19:15];
    wire [4:0]  rs2    = fd_inst[24:20];
    wire [6:0]  funct7 = fd_inst[31:25];
    wire [11:0] csr_addr = fd_inst[31:20];
    
    // Immediate generation
    wire [31:0] imm_i = {{20{fd_inst[31]}}, fd_inst[31:20]};
    wire [31:0] imm_s = {{20{fd_inst[31]}}, fd_inst[31:25], fd_inst[11:7]};
    wire [31:0] imm_b = {{19{fd_inst[31]}}, fd_inst[31], fd_inst[7], fd_inst[30:25], fd_inst[11:8], 1'b0};
    wire [31:0] imm_u = {fd_inst[31:12], 12'b0};
    wire [31:0] imm_j = {{11{fd_inst[31]}}, fd_inst[31], fd_inst[19:12], fd_inst[20], fd_inst[30:21], 1'b0};
    
    // Register read
    wire [31:0] rs1_data = (rs1 == 5'b0) ? 32'b0 : regfile[rs1];
    wire [31:0] rs2_data = (rs2 == 5'b0) ? 32'b0 : regfile[rs2];
    
    // ALU
    reg [31:0] alu_result;
    wire [31:0] alu_op1 = rs1_data;
    reg [31:0] alu_op2;
    
    // Branch condition
    reg branch_taken;
    
    // Control signals
    reg [2:0] state;
    localparam S_FETCH = 3'b000;
    localparam S_DECODE = 3'b001;
    localparam S_EXECUTE = 3'b010;
    localparam S_MEM_ACCESS = 3'b011;
    localparam S_WRITEBACK = 3'b100;
    
    reg [31:0] writeback_data;
    reg [4:0]  writeback_rd;
    reg        writeback_en;
    
    // Load/Store control
    reg is_load;
    reg is_store;
    reg [2:0] mem_funct3;
    
    // Decode stage signals
    wire decode_is_load = (fd_valid && opcode == `OPCODE_LOAD);
    wire decode_is_store = (fd_valid && opcode == `OPCODE_STORE);
    
    //--------------------------------------------------------------------------
    // Pipeline: Fetch-Decode-Execute State Machine
    //--------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 32'h0;
            fd_pc <= 32'h0;
            fd_inst <= 32'h0;
            fd_valid <= 1'b0;
            state <= S_FETCH;
            is_load <= 1'b0;
            is_store <= 1'b0;
        end else begin
            case (state)
                S_FETCH: begin
                    mem_addr <= pc;
                    mem_valid <= 1'b1;
                    mem_wen <= 1'b0;
                    mem_wstrb <= 4'b0000;
                    if (mem_ready) begin
                        fd_inst <= mem_rdata;
                        fd_pc <= pc;
                        fd_valid <= 1'b1;
                        state <= S_EXECUTE;
                    end
                end
                
                S_EXECUTE: begin
                    mem_valid <= 1'b0;
                    // Register load/store flags from decode
                    if (decode_is_load) begin
                        is_load <= 1'b1;
                        is_store <= 1'b0;
                        mem_funct3 <= funct3;
                        state <= S_MEM_ACCESS;
                    end else if (decode_is_store) begin
                        is_load <= 1'b0;
                        is_store <= 1'b1;
                        mem_funct3 <= funct3;
                        state <= S_MEM_ACCESS;
                    end else begin
                        is_load <= 1'b0;
                        is_store <= 1'b0;
                        state <= S_WRITEBACK;
                    end
                end
                
                S_MEM_ACCESS: begin
                    if (is_load) begin
                        mem_addr <= alu_result;
                        mem_valid <= 1'b1;
                        mem_wen <= 1'b0;
                        if (mem_ready) begin
                            // Load data alignment and sign extension
                            case (mem_funct3)
                                3'b000: writeback_data <= {{24{mem_rdata[7]}}, mem_rdata[7:0]};   // LB
                                3'b001: writeback_data <= {{16{mem_rdata[15]}}, mem_rdata[15:0]}; // LH
                                3'b010: writeback_data <= mem_rdata;                               // LW
                                3'b100: writeback_data <= {24'b0, mem_rdata[7:0]};                 // LBU
                                3'b101: writeback_data <= {16'b0, mem_rdata[15:0]};                // LHU
                                default: writeback_data <= mem_rdata;
                            endcase
                            state <= S_WRITEBACK;
                        end
                    end else if (is_store) begin
                        mem_addr <= alu_result;
                        mem_valid <= 1'b1;
                        mem_wen <= 1'b1;
                        case (mem_funct3)
                            3'b000: begin // SB
                                mem_wdata <= {24'b0, rs2_data[7:0]};
                                mem_wstrb <= 4'b0001;
                            end
                            3'b001: begin // SH
                                mem_wdata <= {16'b0, rs2_data[15:0]};
                                mem_wstrb <= 4'b0011;
                            end
                            3'b010: begin // SW
                                mem_wdata <= rs2_data;
                                mem_wstrb <= 4'b1111;
                            end
                            default: begin
                                mem_wdata <= rs2_data;
                                mem_wstrb <= 4'b1111;
                            end
                        endcase
                        if (mem_ready) begin
                            state <= S_WRITEBACK;
                        end
                    end
                end
                
                S_WRITEBACK: begin
                    mem_valid <= 1'b0;
                    if (writeback_en && writeback_rd != 5'b0) begin
                        regfile[writeback_rd] <= writeback_data;
                    end
                    pc <= next_pc;
                    is_load <= 1'b0;
                    is_store <= 1'b0;
                    state <= S_FETCH;
                end
                
                default: state <= S_FETCH;
            endcase
        end
    end
    
    //--------------------------------------------------------------------------
    // Execute Stage: ALU and Control
    //--------------------------------------------------------------------------
    always @(*) begin
        // Defaults
        alu_op2 = rs2_data;
        alu_result = 32'b0;
        branch_taken = 1'b0;
        next_pc = pc + 4;
        writeback_data = alu_result;
        writeback_rd = rd;
        writeback_en = 1'b0;
        vl_write_en = 1'b0;
        vtype_write_en = 1'b0;
        vl_write_data = 32'b0;
        vtype_write_data = 32'b0;
        
        if (fd_valid) begin
            case (opcode)
                `OPCODE_OP_IMM: begin
                    alu_op2 = imm_i;
                    case (funct3)
                        3'b000: alu_result = alu_op1 + alu_op2;
                        3'b010: alu_result = ($signed(alu_op1) < $signed(alu_op2)) ? 32'b1 : 32'b0;
                        3'b011: alu_result = (alu_op1 < alu_op2) ? 32'b1 : 32'b0;
                        3'b100: alu_result = alu_op1 ^ alu_op2;
                        3'b110: alu_result = alu_op1 | alu_op2;
                        3'b111: alu_result = alu_op1 & alu_op2;
                        3'b001: alu_result = alu_op1 << alu_op2[4:0];
                        3'b101: alu_result = funct7[5] ? ($signed(alu_op1) >>> alu_op2[4:0]) : (alu_op1 >> alu_op2[4:0]);
                    endcase
                    writeback_data = alu_result;
                    writeback_en = 1'b1;
                end
                
                `OPCODE_OP: begin
                    case (funct3)
                        3'b000: alu_result = funct7[5] ? (alu_op1 - alu_op2) : (alu_op1 + alu_op2);
                        3'b001: alu_result = alu_op1 << alu_op2[4:0];
                        3'b010: alu_result = ($signed(alu_op1) < $signed(alu_op2)) ? 32'b1 : 32'b0;
                        3'b011: alu_result = (alu_op1 < alu_op2) ? 32'b1 : 32'b0;
                        3'b100: alu_result = alu_op1 ^ alu_op2;
                        3'b101: alu_result = funct7[5] ? ($signed(alu_op1) >>> alu_op2[4:0]) : (alu_op1 >> alu_op2[4:0]);
                        3'b110: alu_result = alu_op1 | alu_op2;
                        3'b111: alu_result = alu_op1 & alu_op2;
                    endcase
                    writeback_data = alu_result;
                    writeback_en = 1'b1;
                end
                
                `OPCODE_LUI: begin
                    writeback_data = imm_u;
                    writeback_en = 1'b1;
                end
                
                `OPCODE_AUIPC: begin
                    writeback_data = fd_pc + imm_u;
                    writeback_en = 1'b1;
                end
                
                `OPCODE_JAL: begin
                    writeback_data = fd_pc + 4;
                    writeback_en = 1'b1;
                    next_pc = fd_pc + imm_j;
                end
                
                `OPCODE_JALR: begin
                    writeback_data = fd_pc + 4;
                    writeback_en = 1'b1;
                    next_pc = (rs1_data + imm_i) & ~32'b1;
                end
                
                `OPCODE_BRANCH: begin
                    case (funct3)
                        3'b000: branch_taken = (rs1_data == rs2_data);
                        3'b001: branch_taken = (rs1_data != rs2_data);
                        3'b100: branch_taken = ($signed(rs1_data) < $signed(rs2_data));
                        3'b101: branch_taken = ($signed(rs1_data) >= $signed(rs2_data));
                        3'b110: branch_taken = (rs1_data < rs2_data);
                        3'b111: branch_taken = (rs1_data >= rs2_data);
                    endcase
                    if (branch_taken) next_pc = fd_pc + imm_b;
                end
                
                `OPCODE_LOAD: begin
                    alu_result = rs1_data + imm_i;
                    writeback_en = 1'b1;
                end
                
                `OPCODE_STORE: begin
                    alu_result = rs1_data + imm_s;
                    writeback_en = 1'b0; // Don't writeback for stores
                end
                
                `OPCODE_SYSTEM: begin
                    case (funct3)
                        3'b001: begin // CSRRW
                            if (csr_addr == `CSR_VL) begin
                                vl_write_data = rs1_data;
                                vl_write_en = 1'b1;
                            end else if (csr_addr == `CSR_VTYPE) begin
                                vtype_write_data = rs1_data;
                                vtype_write_en = 1'b1;
                            end
                        end
                    endcase
                end
            endcase
        end
    end
    
    // Debug outputs
    assign debug_pc = pc;
    assign debug_valid = fd_valid;
    
    // Initialize register file
    initial begin
        for (i = 0; i < 16; i = i + 1) begin
            regfile[i] = 32'h0;
        end
    end

endmodule
