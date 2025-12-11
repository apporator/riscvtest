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

    // Test signal from SoC indicating pass
    wire        mem_test_pass;

    // Instantiate SoC top
    soc_top uut (
        .clk(clk),
        .rst_n(rst_n),
        .desc_addr(32'b0),
        .desc_valid(1'b0),
        .desc_ready(desc_ready),
        .rdma_done(rdma_done),
        .rdma_error(rdma_error),
        .mem_test_pass(mem_test_pass)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz -> 10ns period
    end

    // Test sequence: wait for mem_test_pass or timeout
    initial begin
        rst_n = 0;
        #20;
        rst_n = 1;

        // Wait for a pass signal for up to e.g. 10000 cycles
        integer i;
        integer timeout_cycles;
        timeout_cycles = 10000;
        for (i = 0; i < timeout_cycles; i = i + 1) begin
            #10;
            if (mem_test_pass) begin
                $display("TEST PASSED: memory pass marker observed at time %0t", $time);
                $finish;
            end
        end

        $display("TEST FAILED: timeout waiting for memory pass marker");
        $finish;
    end

    // Simple waveform dump
    initial begin
        $dumpfile("sim/top_tb.vcd");
        $dumpvars(0, top_tb);
    end

endmodule
