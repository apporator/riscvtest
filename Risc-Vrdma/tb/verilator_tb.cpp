#include "Vsoc_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

static void tick(Vsoc_top* top, VerilatedVcdC* tfp) {
    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::debug(0);
    Verilated::traceEverOn(true);

    Vsoc_top* top = new Vsoc_top;

    VerilatedVcdC* tfp = nullptr;
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("verilator.vcd");

    top->rst_n = 0;
    top->clk = 0;
    top->desc_addr = 0;
    top->desc_valid = 0;

    for (int i = 0; i < 5; ++i) tick(top, tfp);
    top->rst_n = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    const int max_cycles = 100000;
    bool passed = false;

    for (int cyc = 0; cyc < max_cycles; ++cyc) {
        tick(top, tfp);

        if (top->mem_test_pass) {
            std::cout << "TEST PASSED at cycle " << cyc << " (time " << main_time << ")" << std::endl;
            passed = true;
            break;
        }
    }

    if (!passed) {
        std::cout << "TEST TIMED OUT after " << main_time << " ticks" << std::endl;
    }

    for (int i = 0; i < 3; ++i) tick(top, tfp);

    if (tfp) {
        tfp->close();
        delete tfp;
    }
    top->final();
    delete top;
    return (passed ? 0 : 1);
}
