`include "common/config.vh"
`include "common/defines.vh"

module soc_top (
    input  wire         clk,
    input  wire         rst_n,
    input  wire [31:0]  desc_addr,
    input  wire         desc_valid,
    output wire         desc_ready,
    output wire         rdma_done,
    output wire         rdma_error,
    output wire         mem_test_pass
);

    wire [31:0] scalar_addr;
    wire [31:0] scalar_wdata;
    wire [3:0]  scalar_wstrb;
    wire        scalar_valid;
    wire        scalar_wen;
    wire [31:0] scalar_rdata;
    wire        scalar_ready;

    wire [31:0] vector_addr;
    wire [`VLEN-1:0] vector_wdata;
    wire [`VLEN/8-1:0] vector_wstrb;
    wire         vector_valid;
    wire         vector_wen;
    wire [`VLEN-1:0] vector_rdata;
    wire         vector_ready;

    wire [`AXI_ADDR_WIDTH-1:0] axi_awaddr;
    wire [7:0]                axi_awlen;
    wire [2:0]                axi_awsize;
    wire [1:0]                axi_awburst;
    wire                      axi_awvalid;
    wire                      axi_awready;

    wire [`AXI_DATA_WIDTH-1:0] axi_wdata;
    wire [`AXI_DATA_WIDTH/8-1:0] axi_wstrb;
    wire                       axi_wlast;
    wire                       axi_wvalid;
    wire                       axi_wready;

    wire [1:0]                 axi_bresp;
    wire                       axi_bvalid;
    wire                       axi_bready;

    wire [`AXI_ADDR_WIDTH-1:0] axi_araddr;
    wire [7:0]                 axi_arlen;
    wire [2:0]                 axi_arsize;
    wire [1:0]                 axi_arburst;
    wire                      axi_arvalid;
    wire                      axi_arready;

    wire [`AXI_DATA_WIDTH-1:0] axi_rdata;
    wire [1:0]                axi_rresp;
    wire                      axi_rlast;
    wire                      axi_rvalid;
    wire                      axi_rready;

    scalar_core u_scalar (
        .clk(clk),
        .rst_n(rst_n),
        .scalar_addr(scalar_addr),
        .scalar_wdata(scalar_wdata),
        .scalar_wstrb(scalar_wstrb),
        .scalar_valid(scalar_valid),
        .scalar_wen(scalar_wen),
        .scalar_rdata(scalar_rdata),
        .scalar_ready(scalar_ready)
    );

    rdma_engine u_rdma (
        .clk(clk),
        .rst_n(rst_n),
        .desc_addr(desc_addr),
        .desc_valid(desc_valid),
        .desc_ready(desc_ready),
        .done(rdma_done),
        .error(rdma_error),
        .mem_addr(vector_addr),
        .mem_wdata(vector_wdata),
        .mem_wstrb(vector_wstrb),
        .mem_valid(vector_valid),
        .mem_wen(vector_wen),
        .mem_rdata(vector_rdata),
        .mem_ready(vector_ready)
    );

    axi4_master u_axi (
        .clk(clk),
        .rst_n(rst_n),
        .scalar_addr(scalar_addr),
        .scalar_wdata(scalar_wdata),
        .scalar_wstrb(scalar_wstrb),
        .scalar_valid(scalar_valid),
        .scalar_wen(scalar_wen),
        .scalar_rdata(scalar_rdata),
        .scalar_ready(scalar_ready),
        .vector_addr(vector_addr),
        .vector_wdata(vector_wdata),
        .vector_wstrb(vector_wstrb),
        .vector_valid(vector_valid),
        .vector_wen(vector_wen),
        .vector_rdata(vector_rdata),
        .vector_ready(vector_ready),
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

    axi_simple_mem u_mem (
        .clk(clk),
        .rst_n(rst_n),
        .awaddr(axi_awaddr),
        .awlen(axi_awlen),
        .awsize(axi_awsize),
        .awburst(axi_awburst),
        .awvalid(axi_awvalid),
        .awready(axi_awready),
        .wdata(axi_wdata),
        .wstrb(axi_wstrb),
        .wlast(axi_wlast),
        .wvalid(axi_wvalid),
        .wready(axi_wready),
        .bresp(axi_bresp),
        .bvalid(axi_bvalid),
        .bready(axi_bready),
        .araddr(axi_araddr),
        .arlen(axi_arlen),
        .arsize(axi_arsize),
        .arburst(axi_arburst),
        .arvalid(axi_arvalid),
        .arready(axi_arready),
        .rdata(axi_rdata),
        .rresp(axi_rresp),
        .rlast(axi_rlast),
        .rvalid(axi_rvalid),
        .rready(axi_rready),
        .test_pass(mem_test_pass)
    );

endmodule
