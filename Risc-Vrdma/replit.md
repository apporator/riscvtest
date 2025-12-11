# RISC-V Vector Extension Prototype Processor

## Overview

A RISC-V Vector Extension (RVV 1.0) prototype processor with 32-bit scalar core (RV32I-like), 512-bit vector unit, AXI4 memory interconnect, and integrated RDMA engine. The processor runs in Verilator simulation and successfully completes a boot test.

## User Preferences

Preferred communication style: Simple, everyday language.

## System Architecture

### Processor Design
- **Scalar Core**: FSM-based instruction execution (sequential design, not pipelined)
- **Instruction Fetch**: Memory fetch via AXI interface (states: FETCH_REQ, FETCH_WAIT, DECODE, EXECUTE, WRITEBACK)
- **ISA Support**: RV32I subset (ADDI, SW, JAL implemented for boot test)
- **Memory Model**: 512-bit wide words, byte addressing with word indexing via araddr[11:4]

### Project Structure
```
rtl/
  scalar/scalar_core.v    - 32-bit scalar core with AXI fetch
  axi/axi4_master.v       - AXI4 master interface
  axi/axi_simple_mem.v    - Simple memory model
  rdma/rdma_engine.v      - RDMA engine placeholder
  common/config.vh        - Configuration defines
  common/defines.vh       - Global defines
  soc_top.v               - Top-level SoC integration
tb/
  verilator_tb.cpp        - C++ testbench
```

### Build System
- **Tool**: Verilator 5.034 - converts Verilog to C++ for simulation
- **Commands**: `make` (build), `make run` (simulate), `make clean` (cleanup)
- **Output**: `obj_dir/Vsoc_top` simulator binary

### Simulation Status
**Boot test PASSES** in 34 cycles (81 time units)
- Test program: `ADDI x1,x0,64; ADDI x2,x0,1; SW x2,0(x1); JAL x0,0`
- Pass condition: Value 0x00000001 written to address 64

## External Dependencies

- **Verilator**: Hardware simulator (installed via Nix)
- **Python 3.11**: Required by Verilator build process
- **g++**: C++ compiler for simulation binary

## Recent Changes

- Fixed critical timeout bug: scalar_core now fetches instructions from memory via AXI
- Fixed AXI handshaking in axi4_master.v
- Organized project into rtl/ and tb/ directories
- Boot test now passes instead of timing out