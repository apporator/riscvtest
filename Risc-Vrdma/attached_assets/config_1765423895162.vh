//==============================================================================
// RVV Core Configuration Parameters
// Based on RISC-V Vector Extension 1.0 Specification
//==============================================================================

`ifndef CONFIG_VH
`define CONFIG_VH

// Vector Configuration
`define VLEN 512
`define ELEN 64
`define NUM_VECTOR_REGS 32
`define NUM_MASK_REGS 8

// Scalar Configuration
`define XLEN 32
`define NUM_SCALAR_REGS 16

// Memory Configuration
`define PADDR_WIDTH 32
`define VADDR_WIDTH 32
`define PAGE_SIZE 4096
`define PAGE_OFFSET_BITS 12

// TLB Configuration
`define TLB_ENTRIES 16
`define TLB_INDEX_BITS 4

// RDMA Configuration
`define DESC_QUEUE_DEPTH 32
`define DESC_QUEUE_INDEX_BITS 5
`define MAX_SG_ENTRIES 16
`define MAX_TRANSFER_SIZE 65536

// AXI4 Configuration
`define AXI_DATA_WIDTH 512
`define AXI_ADDR_WIDTH 32
`define AXI_ID_WIDTH 4
`define AXI_MAX_BURST_LEN 256

// Stream Buffer Configuration
`define STREAM_BUFFER_SIZE 4096
`define NUM_ASYNC_COPY_ENGINES 2

// Pipeline Configuration
`define SCALAR_PIPELINE_STAGES 2
`define VECTOR_PIPELINE_STAGES 3

// Cache Configuration (for future expansion)
`define ICACHE_SIZE 4096
`define DCACHE_SIZE 2048
`define CACHE_LINE_SIZE 64

// Timing and Performance
`define TARGET_FREQ_MHZ 100

`endif
