//==============================================================================
// RVV Core Common Defines
// Instruction opcodes, CSR addresses, and other constants
//==============================================================================

`ifndef DEFINES_VH
`define DEFINES_VH

//------------------------------------------------------------------------------
// RISC-V Base Opcodes (RV32E)
//------------------------------------------------------------------------------
`define OPCODE_LOAD     7'b0000011
`define OPCODE_STORE    7'b0100011
`define OPCODE_BRANCH   7'b1100011
`define OPCODE_JAL      7'b1101111
`define OPCODE_JALR     7'b1100111
`define OPCODE_OP_IMM   7'b0010011
`define OPCODE_OP       7'b0110011
`define OPCODE_LUI      7'b0110111
`define OPCODE_AUIPC    7'b0010111
`define OPCODE_SYSTEM   7'b1110011

//------------------------------------------------------------------------------
// RVV Vector Opcodes
//------------------------------------------------------------------------------
`define OPCODE_VECTOR   7'b1010111

// Vector Load/Store width encoding
`define VLS_WIDTH_8     3'b000
`define VLS_WIDTH_16    3'b101
`define VLS_WIDTH_32    3'b110
`define VLS_WIDTH_64    3'b111

// Vector arithmetic function codes
`define VFUNCT3_OPIVV   3'b000
`define VFUNCT3_OPFVV   3'b001
`define VFUNCT3_OPIVX   3'b100
`define VFUNCT3_OPFVF   3'b101
`define VFUNCT3_OPMVX   3'b110

// Vector configuration
`define VFUNCT3_VSETVLI 3'b111
`define VFUNCT3_VSETIVLI 3'b111

//------------------------------------------------------------------------------
// Vector ALU Operations
//------------------------------------------------------------------------------
`define VALU_OP_ADD     6'h00
`define VALU_OP_SUB     6'h02
`define VALU_OP_MUL     6'h25
`define VALU_OP_DIV     6'h20
`define VALU_OP_AND     6'h09
`define VALU_OP_OR      6'h0A
`define VALU_OP_XOR     6'h0B
`define VALU_OP_SLL     6'h25
`define VALU_OP_SRL     6'h28
`define VALU_OP_SRA     6'h29

// Fused operations
`define VALU_OP_MACC    6'h2D
`define VALU_OP_DOT     6'h30
`define VALU_OP_LERP    6'h31

//------------------------------------------------------------------------------
// CSR Addresses
//------------------------------------------------------------------------------
// Vector CSRs
`define CSR_VSTART      12'h008
`define CSR_VXSAT       12'h009
`define CSR_VXRM        12'h00A
`define CSR_VCSR        12'h00F
`define CSR_VL          12'hC20
`define CSR_VTYPE       12'hC21
`define CSR_VLENB       12'hC22

// MMU CSRs
`define CSR_SATP        12'h180
`define CSR_MSTATUS     12'h300

//------------------------------------------------------------------------------
// MMU Definitions
//------------------------------------------------------------------------------
// Page table entry flags
`define PTE_V           0
`define PTE_R           1
`define PTE_W           2
`define PTE_X           3
`define PTE_U           4
`define PTE_G           5
`define PTE_A           6
`define PTE_D           7

// SATP mode
`define SATP_MODE_BARE  2'b00
`define SATP_MODE_SV32  2'b01

//------------------------------------------------------------------------------
// RDMA Descriptor Fields
//------------------------------------------------------------------------------
`define DESC_VALID      0
`define DESC_DONE       1
`define DESC_ERROR      2
`define DESC_SG         3

//------------------------------------------------------------------------------
// AXI4 Burst Types
//------------------------------------------------------------------------------
`define AXI_BURST_FIXED 2'b00
`define AXI_BURST_INCR  2'b01
`define AXI_BURST_WRAP  2'b10

//------------------------------------------------------------------------------
// AXI4 Response Codes
//------------------------------------------------------------------------------
`define AXI_RESP_OKAY   2'b00
`define AXI_RESP_EXOKAY 2'b01
`define AXI_RESP_SLVERR 2'b10
`define AXI_RESP_DECERR 2'b11

//------------------------------------------------------------------------------
// Vector Element Width Encoding (SEW)
//------------------------------------------------------------------------------
`define SEW_8           3'b000
`define SEW_16          3'b001
`define SEW_32          3'b010
`define SEW_64          3'b011

//------------------------------------------------------------------------------
// Vector Register Grouping (LMUL)
//------------------------------------------------------------------------------
`define LMUL_1          3'b000
`define LMUL_2          3'b001
`define LMUL_4          3'b010
`define LMUL_8          3'b011
`define LMUL_F2         3'b101
`define LMUL_F4         3'b110
`define LMUL_F8         3'b111

//------------------------------------------------------------------------------
// State Machine States
//------------------------------------------------------------------------------
// Scalar unit states
`define SCALAR_FETCH    2'b00
`define SCALAR_DECODE   2'b01
`define SCALAR_EXECUTE  2'b10
`define SCALAR_WRITEBACK 2'b11

// MMU states
`define MMU_IDLE        3'b000
`define MMU_TLB_LOOKUP  3'b001
`define MMU_PTW_L1      3'b010
`define MMU_PTW_L2      3'b011
`define MMU_UPDATE_TLB  3'b100
`define MMU_FAULT       3'b101

// RDMA states
`define RDMA_IDLE       3'b000
`define RDMA_FETCH_DESC 3'b001
`define RDMA_VALIDATE   3'b010
`define RDMA_TRANSFER   3'b011
`define RDMA_UPDATE     3'b100
`define RDMA_ERROR      3'b101

`endif
