`timescale 1ns/1ps
`include "../common/config.vh"
`include "../common/defines.vh"

module top_tb;
    reg clk;
    reg rst_n;

    // RDMA descriptor signals (unused in this basic test)
    wire [31:0] desc_addr;
    wire        desc_valid;
    wire        desc_ready;
    wire        rdma_done;
    wire        rdma_error;

    // Instantiate SoC top
    soc_top uut (
        .clk(clk),
        .rst_n(rst_n),
        .desc_addr(32'b0),
        .desc_valid(1'b0),
        .desc_ready(desc_ready),
        .rdma_done(rdma_done),
        .rdma_error(rdma_error)
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
        #5000;
        $display("SoC testbench finished");
        $finish;
    end

    // Simple waveform dump
    initial begin
        $dumpfile("sim/top_tb.vcd");
        $dumpvars(0, top_tb);
    end

endmodule
