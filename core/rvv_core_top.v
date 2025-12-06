//==============================================================================
// RVV Core Top Module
// Integrates scalar unit, vector unit, MMU, and RDMA engine
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module rvv_core_top (
    input wire clk,
    input wire rst_n,
    
    // AXI4 Master Interface
    output wire [`AXI_ADDR_WIDTH-1:0] axi_awaddr,
    output wire [7:0]                  axi_awlen,
    output wire [2:0]                  axi_awsize,
    output wire [1:0]                  axi_awburst,
    output wire                        axi_awvalid,
    input  wire                        axi_awready,
    
    output wire [`AXI_DATA_WIDTH-1:0] axi_wdata,
    output wire [`AXI_DATA_WIDTH/8-1:0] axi_wstrb,
    output wire                        axi_wlast,
    output wire                        axi_wvalid,
    input  wire                        axi_wready,
    
    input  wire [1:0]                  axi_bresp,
    input  wire                        axi_bvalid,
    output wire                        axi_bready,
    
    output wire [`AXI_ADDR_WIDTH-1:0] axi_araddr,
    output wire [7:0]                  axi_arlen,
    output wire [2:0]                  axi_arsize,
    output wire [1:0]                  axi_arburst,
    output wire                        axi_arvalid,
    input  wire                        axi_arready,
    
    input  wire [`AXI_DATA_WIDTH-1:0] axi_rdata,
    input  wire [1:0]                  axi_rresp,
    input  wire                        axi_rlast,
    input  wire                        axi_rvalid,
    output wire                        axi_rready,
    
    // Interrupt outputs
    output wire                        irq_external,
    output wire                        irq_timer,
    
    // Debug interface
    output wire [31:0]                 debug_pc,
    output wire                        debug_valid
);

    // Scalar-Vector interface
    wire [31:0] scalar_vl_write_data;
    wire        scalar_vl_write_en;
    wire [31:0] scalar_vtype_write_data;
    wire        scalar_vtype_write_en;
    
    // Memory request from scalar unit
    wire [31:0] scalar_mem_addr;
    wire [31:0] scalar_mem_wdata;
    wire [3:0]  scalar_mem_wstrb;
    wire        scalar_mem_valid;
    wire        scalar_mem_wen;
    wire [31:0] scalar_mem_rdata;
    wire        scalar_mem_ready;
    
    // Memory request from vector unit
    wire [31:0] vector_mem_addr;
    wire [`VLEN-1:0] vector_mem_wdata;
    wire [`VLEN/8-1:0] vector_mem_wstrb;
    wire        vector_mem_valid;
    wire        vector_mem_wen;
    wire [`VLEN-1:0] vector_mem_rdata;
    wire        vector_mem_ready;
    
    // MMU interface
    wire [31:0] mmu_vaddr;
    wire [31:0] mmu_paddr;
    wire        mmu_req;
    wire        mmu_wen;
    wire        mmu_ready;
    wire        mmu_fault;
    
    // RDMA interface
    wire [31:0] rdma_desc_addr;
    wire        rdma_desc_valid;
    wire        rdma_desc_ready;
    wire        rdma_done;
    wire        rdma_error;
    
    //--------------------------------------------------------------------------
    // Scalar Unit (RV32E)
    //--------------------------------------------------------------------------
    scalar_unit u_scalar (
        .clk(clk),
        .rst_n(rst_n),
        
        // Memory interface
        .mem_addr(scalar_mem_addr),
        .mem_wdata(scalar_mem_wdata),
        .mem_wstrb(scalar_mem_wstrb),
        .mem_valid(scalar_mem_valid),
        .mem_wen(scalar_mem_wen),
        .mem_rdata(scalar_mem_rdata),
        .mem_ready(scalar_mem_ready),
        
        // Vector CSR interface
        .vl_write_data(scalar_vl_write_data),
        .vl_write_en(scalar_vl_write_en),
        .vtype_write_data(scalar_vtype_write_data),
        .vtype_write_en(scalar_vtype_write_en),
        
        // Debug
        .debug_pc(debug_pc),
        .debug_valid(debug_valid)
    );
    
    //--------------------------------------------------------------------------
    // Vector Unit
    //--------------------------------------------------------------------------
    vector_unit u_vector (
        .clk(clk),
        .rst_n(rst_n),
        
        // Configuration from scalar
        .vl_in(scalar_vl_write_data),
        .vl_we(scalar_vl_write_en),
        .vtype_in(scalar_vtype_write_data),
        .vtype_we(scalar_vtype_write_en),
        
        // Memory interface
        .mem_addr(vector_mem_addr),
        .mem_wdata(vector_mem_wdata),
        .mem_wstrb(vector_mem_wstrb),
        .mem_valid(vector_mem_valid),
        .mem_wen(vector_mem_wen),
        .mem_rdata(vector_mem_rdata),
        .mem_ready(vector_mem_ready)
    );
    
    //--------------------------------------------------------------------------
    // MMU
    //--------------------------------------------------------------------------
    mmu u_mmu (
        .clk(clk),
        .rst_n(rst_n),
        
        // Virtual to physical translation
        .vaddr(mmu_vaddr),
        .paddr(mmu_paddr),
        .req(mmu_req),
        .wen(mmu_wen),
        .ready(mmu_ready),
        .fault(mmu_fault),
        
        // Page table walker memory interface
        .ptw_mem_addr(),
        .ptw_mem_valid(),
        .ptw_mem_rdata(32'h0),
        .ptw_mem_ready(1'b1)
    );
    
    //--------------------------------------------------------------------------
    // RDMA Engine
    //--------------------------------------------------------------------------
    rdma_engine u_rdma (
        .clk(clk),
        .rst_n(rst_n),
        
        // Control interface
        .desc_addr(rdma_desc_addr),
        .desc_valid(rdma_desc_valid),
        .desc_ready(rdma_desc_ready),
        .done(rdma_done),
        .error(rdma_error),
        
        // Memory interface (connects to AXI)
        .mem_addr(),
        .mem_wdata(),
        .mem_wstrb(),
        .mem_valid(),
        .mem_wen(),
        .mem_rdata(512'h0),
        .mem_ready(1'b1)
    );
    
    //--------------------------------------------------------------------------
    // Memory Subsystem with AXI4 Master
    //--------------------------------------------------------------------------
    axi4_master u_axi_master (
        .clk(clk),
        .rst_n(rst_n),
        
        // Scalar memory requests
        .scalar_addr(scalar_mem_addr),
        .scalar_wdata(scalar_mem_wdata),
        .scalar_wstrb(scalar_mem_wstrb),
        .scalar_valid(scalar_mem_valid),
        .scalar_wen(scalar_mem_wen),
        .scalar_rdata(scalar_mem_rdata),
        .scalar_ready(scalar_mem_ready),
        
        // Vector memory requests
        .vector_addr(vector_mem_addr),
        .vector_wdata(vector_mem_wdata),
        .vector_wstrb(vector_mem_wstrb),
        .vector_valid(vector_mem_valid),
        .vector_wen(vector_mem_wen),
        .vector_rdata(vector_mem_rdata),
        .vector_ready(vector_mem_ready),
        
        // AXI4 interface
        .axi_awaddr(axi_awaddr),
        .axi_awlen(axi_awlen),
        .axi_awsize(axi_awsize),
        .axi_awburst(axi_awburst),
        .axi_awvalid(axi_awvalid),
        .axi_awready(axi_awready),
        
        .axi_wdata(axi_wdata),
        .axi_wstrb(axi_wstrb),
        .axi_wlast(axi_wlast),
        .axi_wvalid(axi_wvalid),
        .axi_wready(axi_wready),
        
        .axi_bresp(axi_bresp),
        .axi_bvalid(axi_bvalid),
        .axi_bready(axi_bready),
        
        .axi_araddr(axi_araddr),
        .axi_arlen(axi_arlen),
        .axi_arsize(axi_arsize),
        .axi_arburst(axi_arburst),
        .axi_arvalid(axi_arvalid),
        .axi_arready(axi_arready),
        
        .axi_rdata(axi_rdata),
        .axi_rresp(axi_rresp),
        .axi_rlast(axi_rlast),
        .axi_rvalid(axi_rvalid),
        .axi_rready(axi_rready)
    );
    
    // Interrupt assignments
    assign irq_external = rdma_done | rdma_error;
    assign irq_timer = 1'b0;
    
endmodule
