// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsoc_top__Syms.h"


VL_ATTR_COLD void Vsoc_top___024root__trace_init_sub__TOP__0(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_sub__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+297,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"desc_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+300,0,"desc_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"desc_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"rdma_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"rdma_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"mem_test_pass",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("soc_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+297,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"desc_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+300,0,"desc_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"desc_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"rdma_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"rdma_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"mem_test_pass",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"scalar_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"scalar_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"scalar_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+4,0,"scalar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"scalar_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"scalar_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"scalar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"vector_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+9,0,"vector_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declQuad(c+25,0,"vector_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+27,0,"vector_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"vector_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+29,0,"vector_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBit(c+45,0,"vector_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"axi_awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"axi_awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+49,0,"axi_awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+50,0,"axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+52,0,"axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declQuad(c+68,0,"axi_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+70,0,"axi_wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"axi_bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+74,0,"axi_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"axi_bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"axi_araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"axi_arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"axi_arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+79,0,"axi_arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+80,0,"axi_arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"axi_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+82,0,"axi_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+98,0,"axi_rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+99,0,"axi_rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"axi_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"axi_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_axi", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+297,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"scalar_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"scalar_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"scalar_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+4,0,"scalar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"scalar_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"scalar_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"scalar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"vector_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+9,0,"vector_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declQuad(c+25,0,"vector_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+27,0,"vector_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"vector_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+29,0,"vector_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBit(c+45,0,"vector_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"axi_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"axi_awlen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"axi_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+49,0,"axi_awburst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+50,0,"axi_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"axi_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+52,0,"axi_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declQuad(c+68,0,"axi_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+70,0,"axi_wlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"axi_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"axi_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"axi_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+74,0,"axi_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"axi_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"axi_arlen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"axi_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+79,0,"axi_arburst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+80,0,"axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+82,0,"axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+98,0,"axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+99,0,"axi_rlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+305,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+306,0,"SCALAR_READ_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+307,0,"SCALAR_READ_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+308,0,"SCALAR_READ_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+309,0,"SCALAR_WRITE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+310,0,"SCALAR_WRITE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+311,0,"SCALAR_WRITE_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+312,0,"SCALAR_WRITE_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+313,0,"VECTOR_READ_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+314,0,"VECTOR_READ_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+315,0,"VECTOR_WRITE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+316,0,"VECTOR_WRITE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+317,0,"VECTOR_WRITE_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+103,0,"burst_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+104,0,"burst_len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"saved_scalar_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+27,0,"service_vector",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"service_scalar",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+297,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"awlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+48,0,"awsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+49,0,"awburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+50,0,"awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+52,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declQuad(c+68,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+70,0,"wlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+74,0,"bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"arlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+79,0,"arburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+80,0,"arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+82,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+98,0,"rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+99,0,"rlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"test_pass",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+318,0,"MEM_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+319,0,"PASS_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+320,0,"PASS_IDX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+321,0,"PASS_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+322,0,"PASS_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"write_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"wstate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+323,0,"WS_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+324,0,"WS_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+325,0,"WS_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+326,0,"WS_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+109,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+110,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+111,0,"piece",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+112,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+113,0,"sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+114,0,"idx_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+115,0,"sub_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rdma", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+297,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+299,0,"desc_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+300,0,"desc_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"desc_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"mem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+9,0,"mem_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declQuad(c+25,0,"mem_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+27,0,"mem_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"mem_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+29,0,"mem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBit(c+45,0,"mem_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("desc_queue", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declArray(c+116+i*4,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 127,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+244,0,"queue_head",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+245,0,"queue_tail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+246,0,"queue_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declArray(c+247,0,"current_desc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+251,0,"transfer_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"src_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+253,0,"dst_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+255,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_scalar", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+297,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"scalar_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"scalar_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"scalar_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+4,0,"scalar_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"scalar_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"scalar_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"scalar_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+305,0,"ALU_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+306,0,"ALU_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+307,0,"ALU_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+308,0,"ALU_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+309,0,"ALU_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+327,0,"STATE_FETCH_REQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+328,0,"STATE_FETCH_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+329,0,"STATE_DECODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+330,0,"STATE_EXECUTE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+331,0,"STATE_MEM_REQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+332,0,"STATE_MEM_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+333,0,"STATE_WRITEBACK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+256,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+257,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+260+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+276,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+277,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+278,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+279,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+280,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+281,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+282,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+283,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+284,0,"imm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+285,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"imm_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"rs1_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"rs2_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+289,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+290,0,"do_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"do_mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"do_mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+293,0,"mem_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+294,0,"mem_wdata_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+295,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+296,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsoc_top___024root__trace_init_top(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_init_top\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsoc_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsoc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsoc_top___024root__trace_register(Vsoc_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_register\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vsoc_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsoc_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsoc_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsoc_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_const_0\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsoc_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_const_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_const_0_sub_0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+305,(0U),4);
    bufp->fullCData(oldp+306,(1U),4);
    bufp->fullCData(oldp+307,(2U),4);
    bufp->fullCData(oldp+308,(3U),4);
    bufp->fullCData(oldp+309,(4U),4);
    bufp->fullCData(oldp+310,(5U),4);
    bufp->fullCData(oldp+311,(6U),4);
    bufp->fullCData(oldp+312,(7U),4);
    bufp->fullCData(oldp+313,(8U),4);
    bufp->fullCData(oldp+314,(9U),4);
    bufp->fullCData(oldp+315,(0xaU),4);
    bufp->fullCData(oldp+316,(0xbU),4);
    bufp->fullCData(oldp+317,(0xcU),4);
    bufp->fullIData(oldp+318,(0x400U),32);
    bufp->fullIData(oldp+319,(0x40U),32);
    bufp->fullIData(oldp+320,(1U),32);
    bufp->fullIData(oldp+321,(0U),32);
    bufp->fullIData(oldp+322,(1U),32);
    bufp->fullCData(oldp+323,(0U),2);
    bufp->fullCData(oldp+324,(1U),2);
    bufp->fullCData(oldp+325,(2U),2);
    bufp->fullCData(oldp+326,(3U),2);
    bufp->fullCData(oldp+327,(0U),3);
    bufp->fullCData(oldp+328,(1U),3);
    bufp->fullCData(oldp+329,(2U),3);
    bufp->fullCData(oldp+330,(3U),3);
    bufp->fullCData(oldp+331,(4U),3);
    bufp->fullCData(oldp+332,(5U),3);
    bufp->fullCData(oldp+333,(6U),3);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_0\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsoc_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc_top___024root__trace_full_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_full_0_sub_0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.soc_top__DOT__scalar_addr),32);
    bufp->fullIData(oldp+2,(vlSelfRef.soc_top__DOT__scalar_wdata),32);
    bufp->fullCData(oldp+3,(vlSelfRef.soc_top__DOT__scalar_wstrb),4);
    bufp->fullBit(oldp+4,(vlSelfRef.soc_top__DOT__scalar_valid));
    bufp->fullBit(oldp+5,(vlSelfRef.soc_top__DOT__scalar_wen));
    bufp->fullIData(oldp+6,(vlSelfRef.soc_top__DOT__scalar_rdata),32);
    bufp->fullBit(oldp+7,(vlSelfRef.soc_top__DOT__scalar_ready));
    bufp->fullIData(oldp+8,(vlSelfRef.soc_top__DOT__vector_addr),32);
    bufp->fullWData(oldp+9,(vlSelfRef.soc_top__DOT__vector_wdata),512);
    bufp->fullQData(oldp+25,(vlSelfRef.soc_top__DOT__vector_wstrb),64);
    bufp->fullBit(oldp+27,(vlSelfRef.soc_top__DOT__vector_valid));
    bufp->fullBit(oldp+28,(vlSelfRef.soc_top__DOT__vector_wen));
    bufp->fullWData(oldp+29,(vlSelfRef.soc_top__DOT__vector_rdata),512);
    bufp->fullBit(oldp+45,(vlSelfRef.soc_top__DOT__vector_ready));
    bufp->fullIData(oldp+46,(vlSelfRef.soc_top__DOT__axi_awaddr),32);
    bufp->fullCData(oldp+47,(vlSelfRef.soc_top__DOT__axi_awlen),8);
    bufp->fullCData(oldp+48,(vlSelfRef.soc_top__DOT__axi_awsize),3);
    bufp->fullCData(oldp+49,(vlSelfRef.soc_top__DOT__axi_awburst),2);
    bufp->fullBit(oldp+50,(vlSelfRef.soc_top__DOT__axi_awvalid));
    bufp->fullBit(oldp+51,(vlSelfRef.soc_top__DOT__axi_awready));
    bufp->fullWData(oldp+52,(vlSelfRef.soc_top__DOT__axi_wdata),512);
    bufp->fullQData(oldp+68,(vlSelfRef.soc_top__DOT__axi_wstrb),64);
    bufp->fullBit(oldp+70,(vlSelfRef.soc_top__DOT__axi_wlast));
    bufp->fullBit(oldp+71,(vlSelfRef.soc_top__DOT__axi_wvalid));
    bufp->fullBit(oldp+72,(vlSelfRef.soc_top__DOT__axi_wready));
    bufp->fullCData(oldp+73,(vlSelfRef.soc_top__DOT__axi_bresp),2);
    bufp->fullBit(oldp+74,(vlSelfRef.soc_top__DOT__axi_bvalid));
    bufp->fullBit(oldp+75,(vlSelfRef.soc_top__DOT__axi_bready));
    bufp->fullIData(oldp+76,(vlSelfRef.soc_top__DOT__axi_araddr),32);
    bufp->fullCData(oldp+77,(vlSelfRef.soc_top__DOT__axi_arlen),8);
    bufp->fullCData(oldp+78,(vlSelfRef.soc_top__DOT__axi_arsize),3);
    bufp->fullCData(oldp+79,(vlSelfRef.soc_top__DOT__axi_arburst),2);
    bufp->fullBit(oldp+80,(vlSelfRef.soc_top__DOT__axi_arvalid));
    bufp->fullBit(oldp+81,(vlSelfRef.soc_top__DOT__axi_arready));
    bufp->fullWData(oldp+82,(vlSelfRef.soc_top__DOT__axi_rdata),512);
    bufp->fullCData(oldp+98,(vlSelfRef.soc_top__DOT__axi_rresp),2);
    bufp->fullBit(oldp+99,(vlSelfRef.soc_top__DOT__axi_rlast));
    bufp->fullBit(oldp+100,(vlSelfRef.soc_top__DOT__axi_rvalid));
    bufp->fullBit(oldp+101,(vlSelfRef.soc_top__DOT__axi_rready));
    bufp->fullCData(oldp+102,(vlSelfRef.soc_top__DOT__u_axi__DOT__state),4);
    bufp->fullCData(oldp+103,(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count),8);
    bufp->fullCData(oldp+104,(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len),8);
    bufp->fullIData(oldp+105,(vlSelfRef.soc_top__DOT__u_axi__DOT__saved_scalar_addr),32);
    bufp->fullBit(oldp+106,(((~ (IData)(vlSelfRef.soc_top__DOT__vector_valid)) 
                             & (IData)(vlSelfRef.soc_top__DOT__scalar_valid))));
    bufp->fullIData(oldp+107,(vlSelfRef.soc_top__DOT__u_mem__DOT__write_addr),32);
    bufp->fullCData(oldp+108,(vlSelfRef.soc_top__DOT__u_mem__DOT__wstate),2);
    bufp->fullIData(oldp+109,(vlSelfRef.soc_top__DOT__u_mem__DOT__i),32);
    bufp->fullIData(oldp+110,(vlSelfRef.soc_top__DOT__u_mem__DOT__j),32);
    bufp->fullIData(oldp+111,(vlSelfRef.soc_top__DOT__u_mem__DOT__piece),32);
    bufp->fullIData(oldp+112,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx),32);
    bufp->fullIData(oldp+113,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub),32);
    bufp->fullIData(oldp+114,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r),32);
    bufp->fullIData(oldp+115,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r),32);
    bufp->fullWData(oldp+116,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0]),128);
    bufp->fullWData(oldp+120,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[1]),128);
    bufp->fullWData(oldp+124,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[2]),128);
    bufp->fullWData(oldp+128,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[3]),128);
    bufp->fullWData(oldp+132,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[4]),128);
    bufp->fullWData(oldp+136,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[5]),128);
    bufp->fullWData(oldp+140,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[6]),128);
    bufp->fullWData(oldp+144,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[7]),128);
    bufp->fullWData(oldp+148,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[8]),128);
    bufp->fullWData(oldp+152,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[9]),128);
    bufp->fullWData(oldp+156,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[10]),128);
    bufp->fullWData(oldp+160,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[11]),128);
    bufp->fullWData(oldp+164,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[12]),128);
    bufp->fullWData(oldp+168,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[13]),128);
    bufp->fullWData(oldp+172,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[14]),128);
    bufp->fullWData(oldp+176,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[15]),128);
    bufp->fullWData(oldp+180,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[16]),128);
    bufp->fullWData(oldp+184,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[17]),128);
    bufp->fullWData(oldp+188,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[18]),128);
    bufp->fullWData(oldp+192,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[19]),128);
    bufp->fullWData(oldp+196,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[20]),128);
    bufp->fullWData(oldp+200,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[21]),128);
    bufp->fullWData(oldp+204,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[22]),128);
    bufp->fullWData(oldp+208,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[23]),128);
    bufp->fullWData(oldp+212,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[24]),128);
    bufp->fullWData(oldp+216,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[25]),128);
    bufp->fullWData(oldp+220,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[26]),128);
    bufp->fullWData(oldp+224,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[27]),128);
    bufp->fullWData(oldp+228,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[28]),128);
    bufp->fullWData(oldp+232,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[29]),128);
    bufp->fullWData(oldp+236,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[30]),128);
    bufp->fullWData(oldp+240,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[31]),128);
    bufp->fullCData(oldp+244,(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head),5);
    bufp->fullCData(oldp+245,(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_tail),5);
    bufp->fullCData(oldp+246,(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count),5);
    bufp->fullWData(oldp+247,(vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc),128);
    bufp->fullIData(oldp+251,(vlSelfRef.soc_top__DOT__u_rdma__DOT__transfer_count),32);
    bufp->fullIData(oldp+252,(vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr),32);
    bufp->fullIData(oldp+253,(vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr),32);
    bufp->fullCData(oldp+254,(vlSelfRef.soc_top__DOT__u_rdma__DOT__state),3);
    bufp->fullIData(oldp+255,(vlSelfRef.soc_top__DOT__u_rdma__DOT__i),32);
    bufp->fullCData(oldp+256,(vlSelfRef.soc_top__DOT__u_scalar__DOT__state),3);
    bufp->fullIData(oldp+257,(vlSelfRef.soc_top__DOT__u_scalar__DOT__pc),32);
    bufp->fullIData(oldp+258,(vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc),32);
    bufp->fullIData(oldp+259,(vlSelfRef.soc_top__DOT__u_scalar__DOT__inst),32);
    bufp->fullIData(oldp+260,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0]),32);
    bufp->fullIData(oldp+261,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[1]),32);
    bufp->fullIData(oldp+262,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[2]),32);
    bufp->fullIData(oldp+263,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[3]),32);
    bufp->fullIData(oldp+264,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[4]),32);
    bufp->fullIData(oldp+265,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[5]),32);
    bufp->fullIData(oldp+266,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[6]),32);
    bufp->fullIData(oldp+267,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[7]),32);
    bufp->fullIData(oldp+268,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[8]),32);
    bufp->fullIData(oldp+269,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[9]),32);
    bufp->fullIData(oldp+270,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[10]),32);
    bufp->fullIData(oldp+271,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[11]),32);
    bufp->fullIData(oldp+272,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[12]),32);
    bufp->fullIData(oldp+273,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[13]),32);
    bufp->fullIData(oldp+274,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[14]),32);
    bufp->fullIData(oldp+275,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[15]),32);
    bufp->fullCData(oldp+276,((0x7fU & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst)),7);
    bufp->fullCData(oldp+277,((0x1fU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                        >> 7U))),5);
    bufp->fullCData(oldp+278,((7U & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+279,((0x1fU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+280,((0x1fU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+281,((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                               >> 0x19U)),7);
    bufp->fullIData(oldp+282,(vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i),32);
    bufp->fullIData(oldp+283,((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+284,((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xdU) | (((0x1000U 
                                              & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                 >> 0x13U)) 
                                             | (0x800U 
                                                & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                   << 4U))) 
                                            | ((0x7e0U 
                                                & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                     >> 7U)))))),32);
    bufp->fullIData(oldp+285,((0xfffff000U & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst)),32);
    bufp->fullIData(oldp+286,(((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                             >> 0x1fU))) 
                                 << 0x15U) | (0x100000U 
                                              & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                 >> 0xbU))) 
                               | (((0xff000U & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst) 
                                   | (0x800U & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                >> 9U))) 
                                  | (0x7feU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                               >> 0x14U))))),32);
    bufp->fullIData(oldp+287,(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val),32);
    bufp->fullIData(oldp+288,(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val),32);
    bufp->fullIData(oldp+289,(vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result),32);
    bufp->fullBit(oldp+290,(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write));
    bufp->fullBit(oldp+291,(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_read));
    bufp->fullBit(oldp+292,(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_write));
    bufp->fullIData(oldp+293,(vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_addr_reg),32);
    bufp->fullIData(oldp+294,(vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_wdata_reg),32);
    bufp->fullIData(oldp+295,(vlSelfRef.soc_top__DOT__u_scalar__DOT__i),32);
    bufp->fullBit(oldp+296,(vlSelfRef.soc_top__DOT__u_scalar__DOT__unnamedblk1__DOT__branch_taken));
    bufp->fullBit(oldp+297,(vlSelfRef.clk));
    bufp->fullBit(oldp+298,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+299,(vlSelfRef.desc_addr),32);
    bufp->fullBit(oldp+300,(vlSelfRef.desc_valid));
    bufp->fullBit(oldp+301,(vlSelfRef.desc_ready));
    bufp->fullBit(oldp+302,(vlSelfRef.rdma_done));
    bufp->fullBit(oldp+303,(vlSelfRef.rdma_error));
    bufp->fullBit(oldp+304,(vlSelfRef.mem_test_pass));
}
