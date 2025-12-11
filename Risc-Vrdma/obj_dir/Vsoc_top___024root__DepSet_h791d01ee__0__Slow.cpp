// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top___024root.h"

VL_ATTR_COLD void Vsoc_top___024root___eval_static(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_static\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsoc_top___024root___eval_initial(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_initial\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vsoc_top___024root___eval_final(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_final\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top___024root___eval_settle(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_settle\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/soc_top.v", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsoc_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc_top___024root___stl_sequent__TOP__0(Vsoc_top___024root* vlSelf);
VL_ATTR_COLD void Vsoc_top___024root____Vm_traceActivitySetAll(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD void Vsoc_top___024root___eval_stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vsoc_top___024root___stl_sequent__TOP__0(vlSelf);
        Vsoc_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vsoc_top___024root___stl_sequent__TOP__0(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___stl_sequent__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1 = (0x1fU 
                                                  & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                     >> 0xfU));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2 = (0x1fU 
                                                  & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                     >> 0x14U));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode = 
        (0x7fU & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst);
    vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_u = 
        (0xfffff000U & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst);
    vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_j = 
        ((((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                       >> 0x1fU))) << 0x15U) | (0x100000U 
                                                & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                   >> 0xbU))) 
         | (((0xff000U & vlSelfRef.soc_top__DOT__u_scalar__DOT__inst) 
             | (0x800U & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                          >> 9U))) | (0x7feU & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                >> 0x14U))));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i = 
        (((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                      >> 0x1fU))) << 0xcU) | (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                              >> 0x14U));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3 = 
        (7U & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
               >> 0xcU));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_b = 
        (((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                      >> 0x1fU))) << 0xdU) | (((0x1000U 
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
                                                       >> 7U)))));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_s = 
        (((- (IData)((vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                      >> 0x1fU))) << 0xcU) | ((0xfe0U 
                                               & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                    >> 7U))));
    vlSelfRef.soc_top__DOT__u_scalar__DOT__funct7 = 
        (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
         >> 0x19U);
    vlSelfRef.soc_top__DOT__u_scalar__DOT__rd = (0x1fU 
                                                 & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                    >> 7U));
}

VL_ATTR_COLD void Vsoc_top___024root___eval_triggers__stl(Vsoc_top___024root* vlSelf);

VL_ATTR_COLD bool Vsoc_top___024root___eval_phase__stl(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__stl\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsoc_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vsoc_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__act\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__nba(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___dump_triggers__nba\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc_top___024root____Vm_traceActivitySetAll(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root____Vm_traceActivitySetAll\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vsoc_top___024root___ctor_var_reset(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___ctor_var_reset\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->desc_addr = VL_RAND_RESET_I(32);
    vlSelf->desc_valid = VL_RAND_RESET_I(1);
    vlSelf->desc_ready = VL_RAND_RESET_I(1);
    vlSelf->rdma_done = VL_RAND_RESET_I(1);
    vlSelf->rdma_error = VL_RAND_RESET_I(1);
    vlSelf->mem_test_pass = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__scalar_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__scalar_wdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__scalar_wstrb = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__scalar_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__scalar_wen = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__scalar_rdata = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__scalar_ready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__vector_addr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512, vlSelf->soc_top__DOT__vector_wdata);
    vlSelf->soc_top__DOT__vector_wstrb = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__vector_valid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__vector_wen = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, vlSelf->soc_top__DOT__vector_rdata);
    vlSelf->soc_top__DOT__vector_ready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__axi_awlen = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__axi_awsize = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__axi_awburst = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_awready = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, vlSelf->soc_top__DOT__axi_wdata);
    vlSelf->soc_top__DOT__axi_wstrb = VL_RAND_RESET_Q(64);
    vlSelf->soc_top__DOT__axi_wlast = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_wready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_bready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_arready = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(512, vlSelf->soc_top__DOT__axi_rdata);
    vlSelf->soc_top__DOT__axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__axi_rready = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_scalar__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_scalar__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__inst = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->soc_top__DOT__u_scalar__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->soc_top__DOT__u_scalar__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_scalar__DOT__rd = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_scalar__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_scalar__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_scalar__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_scalar__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->soc_top__DOT__u_scalar__DOT__imm_i = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__imm_s = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__imm_b = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__imm_u = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__imm_j = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__rs1_val = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__rs2_val = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__do_reg_write = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_scalar__DOT__do_mem_read = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_scalar__DOT__do_mem_write = VL_RAND_RESET_I(1);
    vlSelf->soc_top__DOT__u_scalar__DOT__mem_addr_reg = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__mem_wdata_reg = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_scalar__DOT__unnamedblk1__DOT__branch_taken = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->soc_top__DOT__u_rdma__DOT__desc_queue[__Vi0]);
    }
    vlSelf->soc_top__DOT__u_rdma__DOT__queue_head = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_rdma__DOT__queue_tail = VL_RAND_RESET_I(5);
    vlSelf->soc_top__DOT__u_rdma__DOT__queue_count = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(128, vlSelf->soc_top__DOT__u_rdma__DOT__current_desc);
    vlSelf->soc_top__DOT__u_rdma__DOT__transfer_count = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_rdma__DOT__src_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_rdma__DOT__dst_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_rdma__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->soc_top__DOT__u_rdma__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_axi__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->soc_top__DOT__u_axi__DOT__burst_count = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_axi__DOT__burst_len = VL_RAND_RESET_I(8);
    vlSelf->soc_top__DOT__u_axi__DOT__saved_scalar_addr = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        VL_RAND_RESET_W(512, vlSelf->soc_top__DOT__u_mem__DOT__mem[__Vi0]);
    }
    vlSelf->soc_top__DOT__u_mem__DOT__write_addr = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__wstate = VL_RAND_RESET_I(2);
    vlSelf->soc_top__DOT__u_mem__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__piece = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r = VL_RAND_RESET_I(32);
    vlSelf->soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
