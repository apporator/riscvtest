#include "Vsoc_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

static void tick(Vsoc_top* top, VerilatedVcdC* tfp) {
    // Toggle clock: low->high->low, calling eval around edges and dumping times
    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);
    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::debug(0);

    // Enable VCD tracing
    Verilated::traceEverOn(true);

    // Instantiate top
    Vsoc_top* top = new Vsoc_top;

    // Trace file
    VerilatedVcdC* tfp = nullptr;
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("verilator.vcd");

    // Initialize inputs
    top->rst_n = 0;
    top->clk = 0;

    // Hold reset for a few cycles
    for (int i = 0; i < 5; ++i) tick(top, tfp);
    top->rst_n = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    // Run simulation until mem_test_pass observed or timeout
    const int max_cycles = 200000; // adjust timeout if needed
    bool passed = false;

    for (int cyc = 0; cyc < max_cycles; ++cyc) {
        tick(top, tfp);

        // Check the pass signal (exposed from soc_top as mem_test_pass)
        if (top->mem_test_pass) {
            std::cout << "TEST PASSED at time " << main_time << std::endl;
            passed = true;
            break;
        }
    }

    if (!passed) {
        std::cout << "TEST TIMED OUT after " << main_time << " ticks" << std::endl;
    }

    // Final ticks to flush trace
    for (int i = 0; i < 3; ++i) tick(top, tfp);

    // Close trace and cleanup
    if (tfp) {
        tfp->close();
        delete tfp;
    }
    top->final();
    delete top;
    return (passed ? 0 : 1);
}