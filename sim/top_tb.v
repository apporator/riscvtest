`timescale 1ns/1ps
`include "../common/config.vh"
`include "../common/defines.vh"

module top_tb;
    reg clk;
    reg rst_n;

    // Scalar interface signals
    wire [31:0] scalar_addr;
    wire [31:0] scalar_wdata;
    wire [3:0]  scalar_wstrb;
    wire        scalar_valid;
    wire        scalar_wen;
    wire [31:0] scalar_rdata;
    wire        scalar_ready;

    // Vector interface left unconnected for this testbench

    // AXI signals between axi4_master and axi_simple_mem
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
    wire                       axi_arvalid;
    wire                       axi_arready;

    wire [`AXI_DATA_WIDTH-1:0] axi_rdata;
    wire [1:0]                axi_rresp;
    wire                      axi_rlast;
    wire                      axi_rvalid;
    wire                      axi_rready;

    // Instantiate scalar core
    scalar_core uut_core (
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

    // Instantiate axi4_master
    axi4_master uut_axi (
        .clk(clk),
        .rst_n(rst_n),
        .scalar_addr(scalar_addr),
        .scalar_wdata(scalar_wdata),
        .scalar_wstrb(scalar_wstrb),
        .scalar_valid(scalar_valid),
        .scalar_wen(scalar_wen),
        .scalar_rdata(scalar_rdata),
        .scalar_ready(scalar_ready),
        .vector_addr(32'b0),
        .vector_wdata({`VLEN{1'b0}}),
        .vector_wstrb({(`VLEN/8){1'b0}}),
        .vector_valid(1'b0),
        .vector_wen(1'b0),
        .vector_rdata(),
        .vector_ready(),
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

    // Instantiate simple memory
    axi_simple_mem uut_mem (
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
        .rready(axi_rready)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz -> 10ns period
    end

    // Test sequence
    initial begin
        rst_n = 0;
        #20;
        rst_n = 1;

        // Run for a number of cycles
        #2000;
        $display("Testbench finished");
        $finish;
    end

    // Simple waveform dump
    initial begin
        $dumpfile("sim/top_tb.vcd");
        $dumpvars(0, top_tb);
    end

endmodule
