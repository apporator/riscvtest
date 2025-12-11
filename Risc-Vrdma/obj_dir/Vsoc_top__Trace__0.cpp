// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsoc_top__Syms.h"


void Vsoc_top___024root__trace_chg_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsoc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_0\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsoc_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsoc_top___024root__trace_chg_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_0_sub_0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.soc_top__DOT__scalar_addr),32);
        bufp->chgIData(oldp+1,(vlSelfRef.soc_top__DOT__scalar_wdata),32);
        bufp->chgCData(oldp+2,(vlSelfRef.soc_top__DOT__scalar_wstrb),4);
        bufp->chgBit(oldp+3,(vlSelfRef.soc_top__DOT__scalar_valid));
        bufp->chgBit(oldp+4,(vlSelfRef.soc_top__DOT__scalar_wen));
        bufp->chgIData(oldp+5,(vlSelfRef.soc_top__DOT__scalar_rdata),32);
        bufp->chgBit(oldp+6,(vlSelfRef.soc_top__DOT__scalar_ready));
        bufp->chgIData(oldp+7,(vlSelfRef.soc_top__DOT__vector_addr),32);
        bufp->chgWData(oldp+8,(vlSelfRef.soc_top__DOT__vector_wdata),512);
        bufp->chgQData(oldp+24,(vlSelfRef.soc_top__DOT__vector_wstrb),64);
        bufp->chgBit(oldp+26,(vlSelfRef.soc_top__DOT__vector_valid));
        bufp->chgBit(oldp+27,(vlSelfRef.soc_top__DOT__vector_wen));
        bufp->chgWData(oldp+28,(vlSelfRef.soc_top__DOT__vector_rdata),512);
        bufp->chgBit(oldp+44,(vlSelfRef.soc_top__DOT__vector_ready));
        bufp->chgIData(oldp+45,(vlSelfRef.soc_top__DOT__axi_awaddr),32);
        bufp->chgCData(oldp+46,(vlSelfRef.soc_top__DOT__axi_awlen),8);
        bufp->chgCData(oldp+47,(vlSelfRef.soc_top__DOT__axi_awsize),3);
        bufp->chgCData(oldp+48,(vlSelfRef.soc_top__DOT__axi_awburst),2);
        bufp->chgBit(oldp+49,(vlSelfRef.soc_top__DOT__axi_awvalid));
        bufp->chgBit(oldp+50,(vlSelfRef.soc_top__DOT__axi_awready));
        bufp->chgWData(oldp+51,(vlSelfRef.soc_top__DOT__axi_wdata),512);
        bufp->chgQData(oldp+67,(vlSelfRef.soc_top__DOT__axi_wstrb),64);
        bufp->chgBit(oldp+69,(vlSelfRef.soc_top__DOT__axi_wlast));
        bufp->chgBit(oldp+70,(vlSelfRef.soc_top__DOT__axi_wvalid));
        bufp->chgBit(oldp+71,(vlSelfRef.soc_top__DOT__axi_wready));
        bufp->chgCData(oldp+72,(vlSelfRef.soc_top__DOT__axi_bresp),2);
        bufp->chgBit(oldp+73,(vlSelfRef.soc_top__DOT__axi_bvalid));
        bufp->chgBit(oldp+74,(vlSelfRef.soc_top__DOT__axi_bready));
        bufp->chgIData(oldp+75,(vlSelfRef.soc_top__DOT__axi_araddr),32);
        bufp->chgCData(oldp+76,(vlSelfRef.soc_top__DOT__axi_arlen),8);
        bufp->chgCData(oldp+77,(vlSelfRef.soc_top__DOT__axi_arsize),3);
        bufp->chgCData(oldp+78,(vlSelfRef.soc_top__DOT__axi_arburst),2);
        bufp->chgBit(oldp+79,(vlSelfRef.soc_top__DOT__axi_arvalid));
        bufp->chgBit(oldp+80,(vlSelfRef.soc_top__DOT__axi_arready));
        bufp->chgWData(oldp+81,(vlSelfRef.soc_top__DOT__axi_rdata),512);
        bufp->chgCData(oldp+97,(vlSelfRef.soc_top__DOT__axi_rresp),2);
        bufp->chgBit(oldp+98,(vlSelfRef.soc_top__DOT__axi_rlast));
        bufp->chgBit(oldp+99,(vlSelfRef.soc_top__DOT__axi_rvalid));
        bufp->chgBit(oldp+100,(vlSelfRef.soc_top__DOT__axi_rready));
        bufp->chgCData(oldp+101,(vlSelfRef.soc_top__DOT__u_axi__DOT__state),4);
        bufp->chgCData(oldp+102,(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count),8);
        bufp->chgCData(oldp+103,(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len),8);
        bufp->chgIData(oldp+104,(vlSelfRef.soc_top__DOT__u_axi__DOT__saved_scalar_addr),32);
        bufp->chgBit(oldp+105,(((~ (IData)(vlSelfRef.soc_top__DOT__vector_valid)) 
                                & (IData)(vlSelfRef.soc_top__DOT__scalar_valid))));
        bufp->chgIData(oldp+106,(vlSelfRef.soc_top__DOT__u_mem__DOT__write_addr),32);
        bufp->chgCData(oldp+107,(vlSelfRef.soc_top__DOT__u_mem__DOT__wstate),2);
        bufp->chgIData(oldp+108,(vlSelfRef.soc_top__DOT__u_mem__DOT__i),32);
        bufp->chgIData(oldp+109,(vlSelfRef.soc_top__DOT__u_mem__DOT__j),32);
        bufp->chgIData(oldp+110,(vlSelfRef.soc_top__DOT__u_mem__DOT__piece),32);
        bufp->chgIData(oldp+111,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx),32);
        bufp->chgIData(oldp+112,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub),32);
        bufp->chgIData(oldp+113,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r),32);
        bufp->chgIData(oldp+114,(vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r),32);
        bufp->chgWData(oldp+115,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0]),128);
        bufp->chgWData(oldp+119,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[1]),128);
        bufp->chgWData(oldp+123,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[2]),128);
        bufp->chgWData(oldp+127,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[3]),128);
        bufp->chgWData(oldp+131,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[4]),128);
        bufp->chgWData(oldp+135,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[5]),128);
        bufp->chgWData(oldp+139,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[6]),128);
        bufp->chgWData(oldp+143,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[7]),128);
        bufp->chgWData(oldp+147,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[8]),128);
        bufp->chgWData(oldp+151,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[9]),128);
        bufp->chgWData(oldp+155,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[10]),128);
        bufp->chgWData(oldp+159,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[11]),128);
        bufp->chgWData(oldp+163,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[12]),128);
        bufp->chgWData(oldp+167,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[13]),128);
        bufp->chgWData(oldp+171,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[14]),128);
        bufp->chgWData(oldp+175,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[15]),128);
        bufp->chgWData(oldp+179,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[16]),128);
        bufp->chgWData(oldp+183,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[17]),128);
        bufp->chgWData(oldp+187,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[18]),128);
        bufp->chgWData(oldp+191,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[19]),128);
        bufp->chgWData(oldp+195,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[20]),128);
        bufp->chgWData(oldp+199,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[21]),128);
        bufp->chgWData(oldp+203,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[22]),128);
        bufp->chgWData(oldp+207,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[23]),128);
        bufp->chgWData(oldp+211,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[24]),128);
        bufp->chgWData(oldp+215,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[25]),128);
        bufp->chgWData(oldp+219,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[26]),128);
        bufp->chgWData(oldp+223,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[27]),128);
        bufp->chgWData(oldp+227,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[28]),128);
        bufp->chgWData(oldp+231,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[29]),128);
        bufp->chgWData(oldp+235,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[30]),128);
        bufp->chgWData(oldp+239,(vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[31]),128);
        bufp->chgCData(oldp+243,(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head),5);
        bufp->chgCData(oldp+244,(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_tail),5);
        bufp->chgCData(oldp+245,(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count),5);
        bufp->chgWData(oldp+246,(vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc),128);
        bufp->chgIData(oldp+250,(vlSelfRef.soc_top__DOT__u_rdma__DOT__transfer_count),32);
        bufp->chgIData(oldp+251,(vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr),32);
        bufp->chgIData(oldp+252,(vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr),32);
        bufp->chgCData(oldp+253,(vlSelfRef.soc_top__DOT__u_rdma__DOT__state),3);
        bufp->chgIData(oldp+254,(vlSelfRef.soc_top__DOT__u_rdma__DOT__i),32);
        bufp->chgCData(oldp+255,(vlSelfRef.soc_top__DOT__u_scalar__DOT__state),3);
        bufp->chgIData(oldp+256,(vlSelfRef.soc_top__DOT__u_scalar__DOT__pc),32);
        bufp->chgIData(oldp+257,(vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc),32);
        bufp->chgIData(oldp+258,(vlSelfRef.soc_top__DOT__u_scalar__DOT__inst),32);
        bufp->chgIData(oldp+259,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0]),32);
        bufp->chgIData(oldp+260,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[1]),32);
        bufp->chgIData(oldp+261,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[2]),32);
        bufp->chgIData(oldp+262,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[3]),32);
        bufp->chgIData(oldp+263,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[4]),32);
        bufp->chgIData(oldp+264,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[5]),32);
        bufp->chgIData(oldp+265,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[6]),32);
        bufp->chgIData(oldp+266,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[7]),32);
        bufp->chgIData(oldp+267,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[8]),32);
        bufp->chgIData(oldp+268,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[9]),32);
        bufp->chgIData(oldp+269,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[10]),32);
        bufp->chgIData(oldp+270,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[11]),32);
        bufp->chgIData(oldp+271,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[12]),32);
        bufp->chgIData(oldp+272,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[13]),32);
        bufp->chgIData(oldp+273,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[14]),32);
        bufp->chgIData(oldp+274,(vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[15]),32);
        bufp->chgCData(oldp+275,((0x7fU & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst)),7);
        bufp->chgCData(oldp+276,((0x1fU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                           >> 7U))),5);
        bufp->chgCData(oldp+277,((7U & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+278,((0x1fU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+279,((0x1fU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+280,((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                  >> 0x19U)),7);
        bufp->chgIData(oldp+281,(vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i),32);
        bufp->chgIData(oldp+282,((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                     >> 7U))))),32);
        bufp->chgIData(oldp+283,((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
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
        bufp->chgIData(oldp+284,((0xfffff000U & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst)),32);
        bufp->chgIData(oldp+285,(((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                >> 0x1fU))) 
                                    << 0x15U) | (0x100000U 
                                                 & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                    >> 0xbU))) 
                                  | (((0xff000U & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst) 
                                      | (0x800U & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                   >> 9U))) 
                                     | (0x7feU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                  >> 0x14U))))),32);
        bufp->chgIData(oldp+286,(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val),32);
        bufp->chgIData(oldp+287,(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val),32);
        bufp->chgIData(oldp+288,(vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result),32);
        bufp->chgBit(oldp+289,(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write));
        bufp->chgBit(oldp+290,(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_read));
        bufp->chgBit(oldp+291,(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_write));
        bufp->chgIData(oldp+292,(vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_addr_reg),32);
        bufp->chgIData(oldp+293,(vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_wdata_reg),32);
        bufp->chgIData(oldp+294,(vlSelfRef.soc_top__DOT__u_scalar__DOT__i),32);
        bufp->chgBit(oldp+295,(vlSelfRef.soc_top__DOT__u_scalar__DOT__unnamedblk1__DOT__branch_taken));
    }
    bufp->chgBit(oldp+296,(vlSelfRef.clk));
    bufp->chgBit(oldp+297,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+298,(vlSelfRef.desc_addr),32);
    bufp->chgBit(oldp+299,(vlSelfRef.desc_valid));
    bufp->chgBit(oldp+300,(vlSelfRef.desc_ready));
    bufp->chgBit(oldp+301,(vlSelfRef.rdma_done));
    bufp->chgBit(oldp+302,(vlSelfRef.rdma_error));
    bufp->chgBit(oldp+303,(vlSelfRef.mem_test_pass));
}

void Vsoc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_cleanup\n"); );
    // Init
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
