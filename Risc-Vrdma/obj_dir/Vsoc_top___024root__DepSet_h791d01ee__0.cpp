// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"
#include "Vsoc_top___024root.h"

void Vsoc_top___024root___eval_act(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_act\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vsoc_top___024root___nba_sequent__TOP__0(Vsoc_top___024root* vlSelf);

void Vsoc_top___024root___eval_nba(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_nba\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsoc_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h8b2d9f06_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e1b771_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hefbb25e7_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h40491c01_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93336994_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hb84d919e_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hd9381db9_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hea0efeb1_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h399d9c28_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h6fefe57d_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h0e779e2a_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_he6c3131e_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h0a9ca1d6_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hcf30df67_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h15af2998_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h08153678_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h257b7284_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_ha64d4b06_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h75185552_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h9ac63125_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hddbe6847_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h8cb30d64_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hb70dfaae_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_hfd234d13_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h71cdc6c1_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_ha88b41ed_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h9d5133ca_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h9c15c756_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e0faf6_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e02660_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e02d45_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e1b730_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e1b782_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h93e1b776_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h89ebbfe7_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h96dde71d_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h194264f6_0;
extern const VlWide<16>/*511:0*/ Vsoc_top__ConstPool__CONST_h4fed1da4_0;

VL_INLINE_OPT void Vsoc_top___024root___nba_sequent__TOP__0(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___nba_sequent__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__soc_top__DOT__u_scalar__DOT__state;
    __Vdly__soc_top__DOT__u_scalar__DOT__state = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__u_scalar__DOT__pc;
    __Vdly__soc_top__DOT__u_scalar__DOT__pc = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read;
    __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write;
    __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write = 0;
    CData/*2:0*/ __Vdly__soc_top__DOT__u_rdma__DOT__state;
    __Vdly__soc_top__DOT__u_rdma__DOT__state = 0;
    CData/*4:0*/ __Vdly__soc_top__DOT__u_rdma__DOT__queue_head;
    __Vdly__soc_top__DOT__u_rdma__DOT__queue_head = 0;
    CData/*4:0*/ __Vdly__soc_top__DOT__u_rdma__DOT__queue_count;
    __Vdly__soc_top__DOT__u_rdma__DOT__queue_count = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count;
    __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__u_rdma__DOT__src_addr;
    __Vdly__soc_top__DOT__u_rdma__DOT__src_addr = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr;
    __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr = 0;
    CData/*3:0*/ __Vdly__soc_top__DOT__u_axi__DOT__state;
    __Vdly__soc_top__DOT__u_axi__DOT__state = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__vector_ready;
    __Vdly__soc_top__DOT__vector_ready = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_bready;
    __Vdly__soc_top__DOT__axi_bready = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_wlast;
    __Vdly__soc_top__DOT__axi_wlast = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_wvalid;
    __Vdly__soc_top__DOT__axi_wvalid = 0;
    CData/*7:0*/ __Vdly__soc_top__DOT__u_axi__DOT__burst_count;
    __Vdly__soc_top__DOT__u_axi__DOT__burst_count = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_awvalid;
    __Vdly__soc_top__DOT__axi_awvalid = 0;
    VlWide<16>/*511:0*/ __Vdly__soc_top__DOT__vector_rdata;
    VL_ZERO_W(512, __Vdly__soc_top__DOT__vector_rdata);
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_rready;
    __Vdly__soc_top__DOT__axi_rready = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_arvalid;
    __Vdly__soc_top__DOT__axi_arvalid = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__axi_araddr;
    __Vdly__soc_top__DOT__axi_araddr = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__scalar_ready;
    __Vdly__soc_top__DOT__scalar_ready = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__scalar_rdata;
    __Vdly__soc_top__DOT__scalar_rdata = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_awready;
    __Vdly__soc_top__DOT__axi_awready = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_wready;
    __Vdly__soc_top__DOT__axi_wready = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_bvalid;
    __Vdly__soc_top__DOT__axi_bvalid = 0;
    IData/*31:0*/ __Vdly__soc_top__DOT__u_mem__DOT__write_addr;
    __Vdly__soc_top__DOT__u_mem__DOT__write_addr = 0;
    CData/*1:0*/ __Vdly__soc_top__DOT__u_mem__DOT__wstate;
    __Vdly__soc_top__DOT__u_mem__DOT__wstate = 0;
    CData/*1:0*/ __Vdly__soc_top__DOT__axi_bresp;
    __Vdly__soc_top__DOT__axi_bresp = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_arready;
    __Vdly__soc_top__DOT__axi_arready = 0;
    CData/*0:0*/ __Vdly__soc_top__DOT__axi_rvalid;
    __Vdly__soc_top__DOT__axi_rvalid = 0;
    IData/*31:0*/ __VdlyVal__soc_top__DOT__u_scalar__DOT__regs__v0;
    __VdlyVal__soc_top__DOT__u_scalar__DOT__regs__v0 = 0;
    CData/*3:0*/ __VdlyDim0__soc_top__DOT__u_scalar__DOT__regs__v0;
    __VdlyDim0__soc_top__DOT__u_scalar__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v0;
    __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v1;
    __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v1 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0;
    VL_ZERO_W(128, __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0);
    CData/*4:0*/ __VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0;
    __VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v0;
    __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v1;
    __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v1 = 0;
    VlWide<16>/*511:0*/ __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0;
    VL_ZERO_W(512, __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0);
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v0;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v1;
    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v1 = 0;
    SData/*8:0*/ __VdlyLsb__soc_top__DOT__u_mem__DOT__mem__v1;
    __VdlyLsb__soc_top__DOT__u_mem__DOT__mem__v1 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v1;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v1 = 0;
    VlWide<16>/*511:0*/ __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1;
    VL_ZERO_W(512, __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1);
    VlWide<16>/*511:0*/ __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1;
    VL_ZERO_W(512, __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1);
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v2;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v2 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v3;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v3 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v4;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v4 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v5;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v5 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v6;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v6 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v7;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v7 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v8;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v8 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v9;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v9 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v10;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v10 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v11;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v11 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v12;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v12 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v13;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v13 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v14;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v14 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v15;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v15 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v16;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v16 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v17;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v17 = 0;
    SData/*9:0*/ __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v18;
    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v18 = 0;
    // Body
    __Vdly__soc_top__DOT__axi_arready = vlSelfRef.soc_top__DOT__axi_arready;
    __Vdly__soc_top__DOT__axi_rvalid = vlSelfRef.soc_top__DOT__axi_rvalid;
    __Vdly__soc_top__DOT__u_rdma__DOT__state = vlSelfRef.soc_top__DOT__u_rdma__DOT__state;
    __Vdly__soc_top__DOT__u_rdma__DOT__queue_head = vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head;
    __Vdly__soc_top__DOT__u_rdma__DOT__queue_count 
        = vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count;
    __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count 
        = vlSelfRef.soc_top__DOT__u_rdma__DOT__transfer_count;
    __Vdly__soc_top__DOT__u_rdma__DOT__src_addr = vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr;
    __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr = vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr;
    __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v0 = 0U;
    __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v1 = 0U;
    __Vdly__soc_top__DOT__u_scalar__DOT__state = vlSelfRef.soc_top__DOT__u_scalar__DOT__state;
    __Vdly__soc_top__DOT__u_scalar__DOT__pc = vlSelfRef.soc_top__DOT__u_scalar__DOT__pc;
    __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read 
        = vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_read;
    __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write 
        = vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_write;
    __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v0 = 0U;
    __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v1 = 0U;
    __Vdly__soc_top__DOT__u_axi__DOT__state = vlSelfRef.soc_top__DOT__u_axi__DOT__state;
    __Vdly__soc_top__DOT__vector_ready = vlSelfRef.soc_top__DOT__vector_ready;
    __Vdly__soc_top__DOT__axi_bready = vlSelfRef.soc_top__DOT__axi_bready;
    __Vdly__soc_top__DOT__axi_wlast = vlSelfRef.soc_top__DOT__axi_wlast;
    __Vdly__soc_top__DOT__axi_wvalid = vlSelfRef.soc_top__DOT__axi_wvalid;
    __Vdly__soc_top__DOT__u_axi__DOT__burst_count = vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count;
    __Vdly__soc_top__DOT__axi_awvalid = vlSelfRef.soc_top__DOT__axi_awvalid;
    __Vdly__soc_top__DOT__vector_rdata[0U] = vlSelfRef.soc_top__DOT__vector_rdata[0U];
    __Vdly__soc_top__DOT__vector_rdata[1U] = vlSelfRef.soc_top__DOT__vector_rdata[1U];
    __Vdly__soc_top__DOT__vector_rdata[2U] = vlSelfRef.soc_top__DOT__vector_rdata[2U];
    __Vdly__soc_top__DOT__vector_rdata[3U] = vlSelfRef.soc_top__DOT__vector_rdata[3U];
    __Vdly__soc_top__DOT__vector_rdata[4U] = vlSelfRef.soc_top__DOT__vector_rdata[4U];
    __Vdly__soc_top__DOT__vector_rdata[5U] = vlSelfRef.soc_top__DOT__vector_rdata[5U];
    __Vdly__soc_top__DOT__vector_rdata[6U] = vlSelfRef.soc_top__DOT__vector_rdata[6U];
    __Vdly__soc_top__DOT__vector_rdata[7U] = vlSelfRef.soc_top__DOT__vector_rdata[7U];
    __Vdly__soc_top__DOT__vector_rdata[8U] = vlSelfRef.soc_top__DOT__vector_rdata[8U];
    __Vdly__soc_top__DOT__vector_rdata[9U] = vlSelfRef.soc_top__DOT__vector_rdata[9U];
    __Vdly__soc_top__DOT__vector_rdata[0xaU] = vlSelfRef.soc_top__DOT__vector_rdata[0xaU];
    __Vdly__soc_top__DOT__vector_rdata[0xbU] = vlSelfRef.soc_top__DOT__vector_rdata[0xbU];
    __Vdly__soc_top__DOT__vector_rdata[0xcU] = vlSelfRef.soc_top__DOT__vector_rdata[0xcU];
    __Vdly__soc_top__DOT__vector_rdata[0xdU] = vlSelfRef.soc_top__DOT__vector_rdata[0xdU];
    __Vdly__soc_top__DOT__vector_rdata[0xeU] = vlSelfRef.soc_top__DOT__vector_rdata[0xeU];
    __Vdly__soc_top__DOT__vector_rdata[0xfU] = vlSelfRef.soc_top__DOT__vector_rdata[0xfU];
    __Vdly__soc_top__DOT__axi_rready = vlSelfRef.soc_top__DOT__axi_rready;
    __Vdly__soc_top__DOT__axi_arvalid = vlSelfRef.soc_top__DOT__axi_arvalid;
    __Vdly__soc_top__DOT__axi_araddr = vlSelfRef.soc_top__DOT__axi_araddr;
    __Vdly__soc_top__DOT__scalar_ready = vlSelfRef.soc_top__DOT__scalar_ready;
    __Vdly__soc_top__DOT__scalar_rdata = vlSelfRef.soc_top__DOT__scalar_rdata;
    __Vdly__soc_top__DOT__axi_awready = vlSelfRef.soc_top__DOT__axi_awready;
    __Vdly__soc_top__DOT__axi_wready = vlSelfRef.soc_top__DOT__axi_wready;
    __Vdly__soc_top__DOT__axi_bvalid = vlSelfRef.soc_top__DOT__axi_bvalid;
    __Vdly__soc_top__DOT__u_mem__DOT__write_addr = vlSelfRef.soc_top__DOT__u_mem__DOT__write_addr;
    __Vdly__soc_top__DOT__u_mem__DOT__wstate = vlSelfRef.soc_top__DOT__u_mem__DOT__wstate;
    __Vdly__soc_top__DOT__axi_bresp = vlSelfRef.soc_top__DOT__axi_bresp;
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.soc_top__DOT__u_scalar__DOT__i = 0x10U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__i = 0x20U;
    }
    if (vlSelfRef.rst_n) {
        if ((0U == (IData)(vlSelfRef.soc_top__DOT__u_mem__DOT__wstate))) {
            __Vdly__soc_top__DOT__axi_awready = 1U;
            __Vdly__soc_top__DOT__axi_wready = 0U;
            __Vdly__soc_top__DOT__axi_bvalid = 0U;
            if (((IData)(vlSelfRef.soc_top__DOT__axi_awvalid) 
                 & (IData)(vlSelfRef.soc_top__DOT__axi_awready))) {
                __Vdly__soc_top__DOT__u_mem__DOT__write_addr 
                    = vlSelfRef.soc_top__DOT__axi_awaddr;
                __Vdly__soc_top__DOT__axi_awready = 0U;
                __Vdly__soc_top__DOT__u_mem__DOT__wstate = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.soc_top__DOT__u_mem__DOT__wstate))) {
            __Vdly__soc_top__DOT__axi_wready = 1U;
            if (((IData)(vlSelfRef.soc_top__DOT__axi_wvalid) 
                 & (IData)(vlSelfRef.soc_top__DOT__axi_wready))) {
                vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx 
                    = (0x3fU & (vlSelfRef.soc_top__DOT__u_mem__DOT__write_addr 
                                >> 6U));
                vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub 
                    = (0xfU & (vlSelfRef.soc_top__DOT__u_mem__DOT__write_addr 
                               >> 2U));
                __Vdly__soc_top__DOT__axi_wready = 0U;
                __Vdly__soc_top__DOT__u_mem__DOT__wstate = 3U;
                if ((0xffffffffffffffffULL == vlSelfRef.soc_top__DOT__axi_wstrb)) {
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[1U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[1U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[2U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[2U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[3U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[3U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[4U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[4U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[5U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[5U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[6U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[6U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[7U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[7U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[8U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[8U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[9U] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[9U];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0xaU] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0xaU];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0xbU] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0xbU];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0xcU] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0xcU];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0xdU] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0xdU];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0xeU] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0xeU];
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0[0xfU] 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0xfU];
                    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v0 
                        = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx);
                    vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(__VdlyVal__soc_top__DOT__u_mem__DOT__mem__v0, Vsoc_top__ConstPool__CONST_h8b2d9f06_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v0));
                } else {
                    __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v1 
                        = vlSelfRef.soc_top__DOT__axi_wdata[0U];
                    __VdlyLsb__soc_top__DOT__u_mem__DOT__mem__v1 
                        = (0x1ffU & VL_MULS_III(32, (IData)(0x20U), vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub));
                    __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v1 
                        = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx);
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[1U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[1U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[2U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[2U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[3U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[3U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[4U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[4U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[5U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[5U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[6U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[6U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[7U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[7U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[8U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[8U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[9U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[9U];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0xaU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xaU];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0xbU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xbU];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0xcU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xcU];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0xdU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xdU];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0xeU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xeU];
                    __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1[0xfU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xfU];
                    VL_ASSIGNSEL_WI(512,32,(IData)(__VdlyLsb__soc_top__DOT__u_mem__DOT__mem__v1), __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1, 0xffffffffU);
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[1U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[1U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[2U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[2U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[3U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[3U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[4U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[4U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[5U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[5U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[6U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[6U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[7U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[7U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[8U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[8U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[9U] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[9U];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0xaU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xaU];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0xbU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xbU];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0xcU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xcU];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0xdU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xdU];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0xeU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xeU];
                    __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1[0xfU] 
                        = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xfU];
                    VL_ASSIGNSEL_WI(512,32,(IData)(__VdlyLsb__soc_top__DOT__u_mem__DOT__mem__v1), __VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1, __VdlyVal__soc_top__DOT__u_mem__DOT__mem__v1);
                    vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(__VdlyElem__soc_top__DOT__u_mem__DOT__mem__v1, __VdlyMask__soc_top__DOT__u_mem__DOT__mem__v1, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v1));
                }
                if ((1U == vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx)) {
                    if (((1U == vlSelfRef.soc_top__DOT__axi_wdata[0U]) 
                         & (0U == vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub))) {
                        vlSelfRef.mem_test_pass = 1U;
                    }
                }
            }
        } else if ((3U == (IData)(vlSelfRef.soc_top__DOT__u_mem__DOT__wstate))) {
            __Vdly__soc_top__DOT__axi_bvalid = 1U;
            __Vdly__soc_top__DOT__axi_bresp = 0U;
            if (((IData)(vlSelfRef.soc_top__DOT__axi_bready) 
                 & (IData)(vlSelfRef.soc_top__DOT__axi_bvalid))) {
                __Vdly__soc_top__DOT__axi_bvalid = 0U;
                __Vdly__soc_top__DOT__u_mem__DOT__wstate = 0U;
            }
        } else {
            __Vdly__soc_top__DOT__u_mem__DOT__wstate = 0U;
        }
    } else {
        vlSelfRef.soc_top__DOT__u_mem__DOT__i = 0U;
        __Vdly__soc_top__DOT__axi_awready = 0U;
        __Vdly__soc_top__DOT__axi_wready = 0U;
        __Vdly__soc_top__DOT__axi_bvalid = 0U;
        while (VL_GTS_III(32, 0x400U, vlSelfRef.soc_top__DOT__u_mem__DOT__i)) {
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v2 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h93e1b771_0, Vsoc_top__ConstPool__CONST_h8b2d9f06_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v2));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v3 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_hefbb25e7_0, Vsoc_top__ConstPool__CONST_h40491c01_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v3));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v4 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h93336994_0, Vsoc_top__ConstPool__CONST_hb84d919e_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v4));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v5 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_hd9381db9_0, Vsoc_top__ConstPool__CONST_hea0efeb1_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v5));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v6 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h399d9c28_0, Vsoc_top__ConstPool__CONST_h6fefe57d_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v6));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v7 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h0e779e2a_0, Vsoc_top__ConstPool__CONST_he6c3131e_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v7));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v8 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h0a9ca1d6_0, Vsoc_top__ConstPool__CONST_hcf30df67_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v8));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v9 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h15af2998_0, Vsoc_top__ConstPool__CONST_h08153678_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v9));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v10 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h257b7284_0, Vsoc_top__ConstPool__CONST_ha64d4b06_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v10));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v11 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h75185552_0, Vsoc_top__ConstPool__CONST_h9ac63125_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v11));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v12 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_hddbe6847_0, Vsoc_top__ConstPool__CONST_h8cb30d64_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v12));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v13 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_hb70dfaae_0, Vsoc_top__ConstPool__CONST_hfd234d13_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v13));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v14 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h71cdc6c1_0, Vsoc_top__ConstPool__CONST_ha88b41ed_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v14));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v15 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h9d5133ca_0, Vsoc_top__ConstPool__CONST_h9c15c756_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v15));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v16 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h93e0faf6_0, Vsoc_top__ConstPool__CONST_h93e02660_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v16));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v17 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h93e02d45_0, Vsoc_top__ConstPool__CONST_h93e1b730_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v17));
            __VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v18 
                = (0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__i);
            vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h93e1b782_0, Vsoc_top__ConstPool__CONST_h93e1b776_0, (IData)(__VdlyDim0__soc_top__DOT__u_mem__DOT__mem__v18));
            vlSelfRef.soc_top__DOT__u_mem__DOT__j = 0x10U;
            vlSelfRef.soc_top__DOT__u_mem__DOT__i = 
                ((IData)(1U) + vlSelfRef.soc_top__DOT__u_mem__DOT__i);
        }
        __Vdly__soc_top__DOT__axi_bresp = 0U;
        vlSelfRef.mem_test_pass = 0U;
        __Vdly__soc_top__DOT__u_mem__DOT__wstate = 0U;
        __Vdly__soc_top__DOT__u_mem__DOT__write_addr = 0U;
        vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h89ebbfe7_0, Vsoc_top__ConstPool__CONST_h40491c01_0, 0U);
        vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h96dde71d_0, Vsoc_top__ConstPool__CONST_hb84d919e_0, 0U);
        vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h194264f6_0, Vsoc_top__ConstPool__CONST_hea0efeb1_0, 0U);
        vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.enqueue(Vsoc_top__ConstPool__CONST_h4fed1da4_0, Vsoc_top__ConstPool__CONST_h6fefe57d_0, 0U);
    }
    if (vlSelfRef.rst_n) {
        if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
                } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
                } else {
                    if (((IData)(vlSelfRef.soc_top__DOT__axi_bvalid) 
                         & (IData)(vlSelfRef.soc_top__DOT__axi_bready))) {
                        if (((0U == (IData)(vlSelfRef.soc_top__DOT__axi_bresp)) 
                             | (1U == (IData)(vlSelfRef.soc_top__DOT__axi_bresp)))) {
                            __Vdly__soc_top__DOT__vector_ready = 1U;
                        }
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
                    }
                    __Vdly__soc_top__DOT__axi_bready = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                    __Vdly__soc_top__DOT__axi_wlast 
                        = ((IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count) 
                           == (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len));
                    __Vdly__soc_top__DOT__axi_wvalid = 1U;
                    vlSelfRef.soc_top__DOT__axi_wdata[0U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0U];
                    vlSelfRef.soc_top__DOT__axi_wdata[1U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[1U];
                    vlSelfRef.soc_top__DOT__axi_wdata[2U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[2U];
                    vlSelfRef.soc_top__DOT__axi_wdata[3U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[3U];
                    vlSelfRef.soc_top__DOT__axi_wdata[4U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[4U];
                    vlSelfRef.soc_top__DOT__axi_wdata[5U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[5U];
                    vlSelfRef.soc_top__DOT__axi_wdata[6U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[6U];
                    vlSelfRef.soc_top__DOT__axi_wdata[7U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[7U];
                    vlSelfRef.soc_top__DOT__axi_wdata[8U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[8U];
                    vlSelfRef.soc_top__DOT__axi_wdata[9U] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[9U];
                    vlSelfRef.soc_top__DOT__axi_wdata[0xaU] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0xaU];
                    vlSelfRef.soc_top__DOT__axi_wdata[0xbU] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0xbU];
                    vlSelfRef.soc_top__DOT__axi_wdata[0xcU] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0xcU];
                    vlSelfRef.soc_top__DOT__axi_wdata[0xdU] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0xdU];
                    vlSelfRef.soc_top__DOT__axi_wdata[0xeU] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0xeU];
                    vlSelfRef.soc_top__DOT__axi_wdata[0xfU] 
                        = vlSelfRef.soc_top__DOT__vector_wdata[0xfU];
                    vlSelfRef.soc_top__DOT__axi_wstrb 
                        = vlSelfRef.soc_top__DOT__vector_wstrb;
                    if (((IData)(vlSelfRef.soc_top__DOT__axi_wready) 
                         & (IData)(vlSelfRef.soc_top__DOT__axi_wvalid))) {
                        if (vlSelfRef.soc_top__DOT__axi_wlast) {
                            __Vdly__soc_top__DOT__axi_wvalid = 0U;
                            __Vdly__soc_top__DOT__u_axi__DOT__state = 0xcU;
                        } else {
                            __Vdly__soc_top__DOT__u_axi__DOT__burst_count 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count)));
                        }
                    }
                } else {
                    __Vdly__soc_top__DOT__axi_awvalid = 1U;
                    vlSelfRef.soc_top__DOT__axi_awaddr 
                        = vlSelfRef.soc_top__DOT__vector_addr;
                    vlSelfRef.soc_top__DOT__axi_awlen 
                        = vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len;
                    vlSelfRef.soc_top__DOT__axi_awsize = 6U;
                    vlSelfRef.soc_top__DOT__axi_awburst = 1U;
                    if (((IData)(vlSelfRef.soc_top__DOT__axi_awready) 
                         & (IData)(vlSelfRef.soc_top__DOT__axi_awvalid))) {
                        __Vdly__soc_top__DOT__axi_awvalid = 0U;
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 0xbU;
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                if (((IData)(vlSelfRef.soc_top__DOT__axi_rvalid) 
                     & (IData)(vlSelfRef.soc_top__DOT__axi_rready))) {
                    __Vdly__soc_top__DOT__vector_rdata[0U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0U];
                    __Vdly__soc_top__DOT__vector_rdata[1U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[1U];
                    __Vdly__soc_top__DOT__vector_rdata[2U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[2U];
                    __Vdly__soc_top__DOT__vector_rdata[3U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[3U];
                    __Vdly__soc_top__DOT__vector_rdata[4U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[4U];
                    __Vdly__soc_top__DOT__vector_rdata[5U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[5U];
                    __Vdly__soc_top__DOT__vector_rdata[6U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[6U];
                    __Vdly__soc_top__DOT__vector_rdata[7U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[7U];
                    __Vdly__soc_top__DOT__vector_rdata[8U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[8U];
                    __Vdly__soc_top__DOT__vector_rdata[9U] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[9U];
                    __Vdly__soc_top__DOT__vector_rdata[0xaU] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0xaU];
                    __Vdly__soc_top__DOT__vector_rdata[0xbU] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0xbU];
                    __Vdly__soc_top__DOT__vector_rdata[0xcU] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0xcU];
                    __Vdly__soc_top__DOT__vector_rdata[0xdU] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0xdU];
                    __Vdly__soc_top__DOT__vector_rdata[0xeU] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0xeU];
                    __Vdly__soc_top__DOT__vector_rdata[0xfU] 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0xfU];
                    if (vlSelfRef.soc_top__DOT__axi_rlast) {
                        __Vdly__soc_top__DOT__vector_ready = 1U;
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
                    } else {
                        __Vdly__soc_top__DOT__u_axi__DOT__burst_count 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count)));
                    }
                }
                __Vdly__soc_top__DOT__axi_rready = 1U;
            } else {
                __Vdly__soc_top__DOT__axi_arvalid = 1U;
                __Vdly__soc_top__DOT__axi_araddr = vlSelfRef.soc_top__DOT__vector_addr;
                vlSelfRef.soc_top__DOT__axi_arlen = vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len;
                vlSelfRef.soc_top__DOT__axi_arsize = 6U;
                vlSelfRef.soc_top__DOT__axi_arburst = 1U;
                if (((IData)(vlSelfRef.soc_top__DOT__axi_arready) 
                     & (IData)(vlSelfRef.soc_top__DOT__axi_arvalid))) {
                    __Vdly__soc_top__DOT__axi_arvalid = 0U;
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 9U;
                }
            }
        } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.soc_top__DOT__scalar_valid)))) {
                        __Vdly__soc_top__DOT__scalar_ready = 0U;
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
                    }
                } else {
                    if (((IData)(vlSelfRef.soc_top__DOT__axi_bvalid) 
                         & (IData)(vlSelfRef.soc_top__DOT__axi_bready))) {
                        if (((0U == (IData)(vlSelfRef.soc_top__DOT__axi_bresp)) 
                             | (1U == (IData)(vlSelfRef.soc_top__DOT__axi_bresp)))) {
                            __Vdly__soc_top__DOT__scalar_ready = 1U;
                        }
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 7U;
                    }
                    __Vdly__soc_top__DOT__axi_bready = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                __Vdly__soc_top__DOT__axi_wlast = ((IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count) 
                                                   == (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len));
                __Vdly__soc_top__DOT__axi_wvalid = 1U;
                vlSelfRef.soc_top__DOT__axi_wdata[0U] 
                    = vlSelfRef.soc_top__DOT__scalar_wdata;
                vlSelfRef.soc_top__DOT__axi_wdata[1U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[2U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[3U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[4U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[5U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[6U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[7U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[8U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[9U] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[0xaU] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[0xbU] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[0xcU] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[0xdU] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[0xeU] = 0U;
                vlSelfRef.soc_top__DOT__axi_wdata[0xfU] = 0U;
                vlSelfRef.soc_top__DOT__axi_wstrb = (QData)((IData)(vlSelfRef.soc_top__DOT__scalar_wstrb));
                if (((IData)(vlSelfRef.soc_top__DOT__axi_wready) 
                     & (IData)(vlSelfRef.soc_top__DOT__axi_wvalid))) {
                    if (vlSelfRef.soc_top__DOT__axi_wlast) {
                        __Vdly__soc_top__DOT__axi_wvalid = 0U;
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 6U;
                    } else {
                        __Vdly__soc_top__DOT__u_axi__DOT__burst_count 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count)));
                    }
                }
            } else {
                __Vdly__soc_top__DOT__axi_awvalid = 1U;
                vlSelfRef.soc_top__DOT__axi_awaddr 
                    = vlSelfRef.soc_top__DOT__u_axi__DOT__saved_scalar_addr;
                vlSelfRef.soc_top__DOT__axi_awlen = vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len;
                vlSelfRef.soc_top__DOT__axi_awsize = 2U;
                vlSelfRef.soc_top__DOT__axi_awburst = 1U;
                if (((IData)(vlSelfRef.soc_top__DOT__axi_awready) 
                     & (IData)(vlSelfRef.soc_top__DOT__axi_awvalid))) {
                    __Vdly__soc_top__DOT__axi_awvalid = 0U;
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 5U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.soc_top__DOT__scalar_valid)))) {
                    __Vdly__soc_top__DOT__scalar_ready = 0U;
                    __Vdly__soc_top__DOT__axi_rready = 1U;
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
                }
            } else {
                __Vdly__soc_top__DOT__axi_rready = 1U;
                if (((IData)(vlSelfRef.soc_top__DOT__axi_rvalid) 
                     & (IData)(vlSelfRef.soc_top__DOT__axi_rready))) {
                    __Vdly__soc_top__DOT__scalar_rdata 
                        = vlSelfRef.soc_top__DOT__axi_rdata[0U];
                    __Vdly__soc_top__DOT__axi_rready = 0U;
                    if (vlSelfRef.soc_top__DOT__axi_rlast) {
                        __Vdly__soc_top__DOT__scalar_ready = 1U;
                        __Vdly__soc_top__DOT__u_axi__DOT__state = 3U;
                    } else {
                        __Vdly__soc_top__DOT__u_axi__DOT__burst_count 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count)));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_axi__DOT__state))) {
            __Vdly__soc_top__DOT__axi_arvalid = 1U;
            __Vdly__soc_top__DOT__axi_araddr = vlSelfRef.soc_top__DOT__u_axi__DOT__saved_scalar_addr;
            vlSelfRef.soc_top__DOT__axi_arlen = vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len;
            vlSelfRef.soc_top__DOT__axi_arsize = 2U;
            vlSelfRef.soc_top__DOT__axi_arburst = 1U;
            if (((IData)(vlSelfRef.soc_top__DOT__axi_arready) 
                 & (IData)(vlSelfRef.soc_top__DOT__axi_arvalid))) {
                __Vdly__soc_top__DOT__axi_arvalid = 0U;
                __Vdly__soc_top__DOT__u_axi__DOT__state = 2U;
            }
        } else {
            __Vdly__soc_top__DOT__axi_awvalid = 0U;
            __Vdly__soc_top__DOT__axi_wvalid = 0U;
            __Vdly__soc_top__DOT__axi_arvalid = 0U;
            __Vdly__soc_top__DOT__scalar_ready = 0U;
            __Vdly__soc_top__DOT__vector_ready = 0U;
            __Vdly__soc_top__DOT__u_axi__DOT__burst_count = 0U;
            if (vlSelfRef.soc_top__DOT__vector_valid) {
                if (vlSelfRef.soc_top__DOT__vector_wen) {
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 0xaU;
                    vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len = 0U;
                } else {
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 8U;
                    vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len = 0U;
                }
            } else if (((~ (IData)(vlSelfRef.soc_top__DOT__vector_valid)) 
                        & (IData)(vlSelfRef.soc_top__DOT__scalar_valid))) {
                vlSelfRef.soc_top__DOT__u_axi__DOT__saved_scalar_addr 
                    = vlSelfRef.soc_top__DOT__scalar_addr;
                if (vlSelfRef.soc_top__DOT__scalar_wen) {
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 4U;
                    vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len = 0U;
                } else {
                    __Vdly__soc_top__DOT__u_axi__DOT__state = 1U;
                    vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len = 0U;
                }
            }
        }
        if ((((IData)(vlSelfRef.soc_top__DOT__axi_arvalid) 
              & (~ (IData)(vlSelfRef.soc_top__DOT__axi_arready))) 
             & (~ (IData)(vlSelfRef.soc_top__DOT__axi_rvalid)))) {
            __Vdly__soc_top__DOT__axi_arready = 1U;
        } else if (((IData)(vlSelfRef.soc_top__DOT__axi_arvalid) 
                    & (IData)(vlSelfRef.soc_top__DOT__axi_arready))) {
            vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r 
                = (0x3fU & (vlSelfRef.soc_top__DOT__axi_araddr 
                            >> 6U));
            vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r 
                = (0xfU & (vlSelfRef.soc_top__DOT__axi_araddr 
                           >> 2U));
            vlSelfRef.soc_top__DOT__u_mem__DOT__piece 
                = (((0U == (0x1fU & VL_MULS_III(32, (IData)(0x20U), vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r)))
                     ? 0U : (vlSelfRef.soc_top__DOT__u_mem__DOT__mem
                             [(0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r)][
                             (((IData)(0x1fU) + (0x1ffU 
                                                 & VL_MULS_III(32, (IData)(0x20U), vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r))) 
                              >> 5U)] << ((IData)(0x20U) 
                                          - (0x1fU 
                                             & VL_MULS_III(32, (IData)(0x20U), vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r))))) 
                   | (vlSelfRef.soc_top__DOT__u_mem__DOT__mem
                      [(0x3ffU & vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r)][
                      (0xfU & (VL_MULS_III(32, (IData)(0x20U), vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r) 
                               >> 5U))] >> (0x1fU & 
                                            VL_MULS_III(32, (IData)(0x20U), vlSelfRef.soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r))));
            vlSelfRef.soc_top__DOT__axi_rresp = 0U;
            vlSelfRef.soc_top__DOT__axi_rlast = 1U;
            __Vdly__soc_top__DOT__axi_rvalid = 1U;
            __Vdly__soc_top__DOT__axi_arready = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0U] = vlSelfRef.soc_top__DOT__u_mem__DOT__piece;
            vlSelfRef.soc_top__DOT__axi_rdata[1U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[2U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[3U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[4U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[5U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[6U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[7U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[8U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[9U] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0xaU] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0xbU] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0xcU] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0xdU] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0xeU] = 0U;
            vlSelfRef.soc_top__DOT__axi_rdata[0xfU] = 0U;
        } else {
            if (((IData)(vlSelfRef.soc_top__DOT__axi_rvalid) 
                 & (IData)(vlSelfRef.soc_top__DOT__axi_rready))) {
                __Vdly__soc_top__DOT__axi_rvalid = 0U;
            }
            __Vdly__soc_top__DOT__axi_arready = 0U;
        }
        if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__state))) {
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__state))) {
                __Vdly__soc_top__DOT__u_rdma__DOT__queue_head 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head)));
                __Vdly__soc_top__DOT__u_rdma__DOT__queue_count 
                    = (0x1fU & ((IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count) 
                                - (IData)(1U)));
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 0U;
            } else {
                vlSelfRef.soc_top__DOT__vector_addr 
                    = vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr;
                vlSelfRef.soc_top__DOT__vector_wdata[0U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0U];
                vlSelfRef.soc_top__DOT__vector_wdata[1U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[1U];
                vlSelfRef.soc_top__DOT__vector_wdata[2U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[2U];
                vlSelfRef.soc_top__DOT__vector_wdata[3U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[3U];
                vlSelfRef.soc_top__DOT__vector_wdata[4U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[4U];
                vlSelfRef.soc_top__DOT__vector_wdata[5U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[5U];
                vlSelfRef.soc_top__DOT__vector_wdata[6U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[6U];
                vlSelfRef.soc_top__DOT__vector_wdata[7U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[7U];
                vlSelfRef.soc_top__DOT__vector_wdata[8U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[8U];
                vlSelfRef.soc_top__DOT__vector_wdata[9U] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[9U];
                vlSelfRef.soc_top__DOT__vector_wdata[0xaU] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0xaU];
                vlSelfRef.soc_top__DOT__vector_wdata[0xbU] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0xbU];
                vlSelfRef.soc_top__DOT__vector_wdata[0xcU] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0xcU];
                vlSelfRef.soc_top__DOT__vector_wdata[0xdU] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0xdU];
                vlSelfRef.soc_top__DOT__vector_wdata[0xeU] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0xeU];
                vlSelfRef.soc_top__DOT__vector_wdata[0xfU] 
                    = vlSelfRef.soc_top__DOT__vector_rdata[0xfU];
                vlSelfRef.soc_top__DOT__vector_wstrb = 0xffffffffffffffffULL;
                vlSelfRef.soc_top__DOT__vector_wen = 1U;
                vlSelfRef.soc_top__DOT__vector_valid = 1U;
                if (vlSelfRef.soc_top__DOT__vector_ready) {
                    __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count 
                        = (vlSelfRef.soc_top__DOT__u_rdma__DOT__transfer_count 
                           - (IData)(0x40U));
                    __Vdly__soc_top__DOT__u_rdma__DOT__src_addr 
                        = ((IData)(0x40U) + vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr);
                    __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr 
                        = ((IData)(0x40U) + vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr);
                    vlSelfRef.soc_top__DOT__vector_valid = 0U;
                    __Vdly__soc_top__DOT__u_rdma__DOT__state = 3U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__state))) {
                if ((0U < vlSelfRef.soc_top__DOT__u_rdma__DOT__transfer_count)) {
                    vlSelfRef.soc_top__DOT__vector_addr 
                        = vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr;
                    vlSelfRef.soc_top__DOT__vector_valid = 1U;
                    vlSelfRef.soc_top__DOT__vector_wen = 0U;
                    if (vlSelfRef.soc_top__DOT__vector_ready) {
                        vlSelfRef.soc_top__DOT__vector_valid = 0U;
                        __Vdly__soc_top__DOT__u_rdma__DOT__state = 4U;
                    }
                } else {
                    __Vdly__soc_top__DOT__u_rdma__DOT__queue_head 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head)));
                    __Vdly__soc_top__DOT__u_rdma__DOT__queue_count 
                        = (0x1fU & ((IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count) 
                                    - (IData)(1U)));
                    vlSelfRef.rdma_done = 1U;
                    __Vdly__soc_top__DOT__u_rdma__DOT__state = 0U;
                }
            } else if (((0U != (0x3fU & vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr)) 
                        | (0U != (0x3fU & vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr)))) {
                vlSelfRef.rdma_error = 1U;
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 5U;
            } else {
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__state))) {
            __Vdly__soc_top__DOT__u_rdma__DOT__src_addr 
                = vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[1U];
            __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr 
                = vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[2U];
            __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count 
                = (vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[0U] 
                   >> 0x10U);
            if ((1U & vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[0U])) {
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 2U;
            } else {
                vlSelfRef.rdma_error = 1U;
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 5U;
            }
        } else {
            if (vlSelfRef.desc_valid) {
                __Vdly__soc_top__DOT__u_rdma__DOT__queue_count 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count)));
                __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[0U] 
                    = vlSelfRef.desc_addr;
                __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[1U] = 0U;
                __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[2U] = 0U;
                __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[3U] = 0U;
                __VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0 
                    = vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_tail;
                __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v0 = 1U;
                vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_tail 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_tail)));
            }
            vlSelfRef.rdma_done = 0U;
            vlSelfRef.rdma_error = 0U;
            vlSelfRef.soc_top__DOT__vector_valid = 0U;
            if ((0U < (IData)(vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count))) {
                vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[0U] 
                    = vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue
                    [vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head][0U];
                vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[1U] 
                    = vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue
                    [vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head][1U];
                vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[2U] 
                    = vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue
                    [vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head][2U];
                vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[3U] 
                    = vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue
                    [vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head][3U];
                __Vdly__soc_top__DOT__u_rdma__DOT__state = 1U;
            }
            vlSelfRef.desc_ready = 1U;
        }
        if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 0U;
                } else {
                    if ((((IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write) 
                          & (0U != (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rd))) 
                         & (0x10U > (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rd)))) {
                        __VdlyVal__soc_top__DOT__u_scalar__DOT__regs__v0 
                            = vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result;
                        __VdlyDim0__soc_top__DOT__u_scalar__DOT__regs__v0 
                            = (0xfU & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rd));
                        __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v0 = 1U;
                    }
                    __Vdly__soc_top__DOT__u_scalar__DOT__pc 
                        = vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc;
                    __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read = 0U;
                    __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write = 0U;
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 0U;
                    vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 0U;
                }
            } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
                if (vlSelfRef.soc_top__DOT__scalar_ready) {
                    if (vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_read) {
                        vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                            = vlSelfRef.soc_top__DOT__scalar_rdata;
                    }
                    vlSelfRef.soc_top__DOT__scalar_valid = 0U;
                    vlSelfRef.soc_top__DOT__scalar_wen = 0U;
                    vlSelfRef.soc_top__DOT__scalar_wstrb = 0U;
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                }
            } else {
                vlSelfRef.soc_top__DOT__scalar_addr 
                    = vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_addr_reg;
                vlSelfRef.soc_top__DOT__scalar_wdata 
                    = vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_wdata_reg;
                if (vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_write) {
                    vlSelfRef.soc_top__DOT__scalar_wstrb = 0xfU;
                    vlSelfRef.soc_top__DOT__scalar_valid = 1U;
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 5U;
                    vlSelfRef.soc_top__DOT__scalar_wen = 1U;
                } else {
                    vlSelfRef.soc_top__DOT__scalar_wstrb = 0U;
                    vlSelfRef.soc_top__DOT__scalar_valid = 1U;
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 5U;
                    vlSelfRef.soc_top__DOT__scalar_wen = 0U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
                if ((0x40U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                    if ((0x20U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        if ((0x10U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        } else if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                    if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                        vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                                            = ((IData)(4U) 
                                               + vlSelfRef.soc_top__DOT__u_scalar__DOT__pc);
                                        vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                        vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc 
                                            = (vlSelfRef.soc_top__DOT__u_scalar__DOT__pc 
                                               + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_j);
                                    } else {
                                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                    }
                                } else {
                                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                }
                            } else {
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            }
                        } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                    vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                                        = ((IData)(4U) 
                                           + vlSelfRef.soc_top__DOT__u_scalar__DOT__pc);
                                    vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc 
                                        = (0xfffffffeU 
                                           & (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                              + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i));
                                    vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                } else {
                                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                }
                            } else {
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            }
                        } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                vlSelfRef.soc_top__DOT__u_scalar__DOT__unnamedblk1__DOT__branch_taken 
                                    = ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                        ? ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   >= vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   < vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val))
                                            : ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                : VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)))
                                        : ((1U & (~ 
                                                  ((IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3) 
                                                   >> 1U))) 
                                           && ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   != vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   == vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val))));
                                if (vlSelfRef.soc_top__DOT__u_scalar__DOT__unnamedblk1__DOT__branch_taken) {
                                    vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc 
                                        = (vlSelfRef.soc_top__DOT__u_scalar__DOT__pc 
                                           + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_b);
                                }
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            } else {
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            }
                        } else {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        }
                    } else {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    }
                } else if ((0x20U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                    if ((0x10U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                    vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                                        = vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_u;
                                    vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                } else {
                                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                                }
                            } else {
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            }
                        } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                                    = ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                        ? ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   & vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   | vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val))
                                            : ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? (
                                                   (0x20U 
                                                    & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct7))
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,5, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val, 
                                                                  (0x1fU 
                                                                   & vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val))
                                                    : 
                                                   (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                    >> 
                                                    (0x1fU 
                                                     & vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)))
                                                : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   ^ vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)))
                                        : ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? (
                                                   (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                    < vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                    ? 1U
                                                    : 0U))
                                            : ((1U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                                ? (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   << 
                                                   (0x1fU 
                                                    & vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val))
                                                : (
                                                   (0x20U 
                                                    & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct7))
                                                    ? 
                                                   (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                    - vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)
                                                    : 
                                                   (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                    + vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val)))));
                                vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            } else {
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            }
                        } else {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        }
                    } else if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_addr_reg 
                                = (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                   + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_s);
                            vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_wdata_reg 
                                = vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val;
                            __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write = 1U;
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 4U;
                        } else {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        }
                    } else {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    }
                } else if ((0x10U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                    if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                                vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                                    = (vlSelfRef.soc_top__DOT__u_scalar__DOT__pc 
                                       + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_u);
                                vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            } else {
                                __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                            }
                        } else {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        }
                    } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                            vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result 
                                = ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                    ? ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                        ? ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                               & vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i)
                                            : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                               | vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i))
                                        : ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? ((0x20U 
                                                & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct7))
                                                ? VL_SHIFTRS_III(32,32,5, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val, 
                                                                 (0x1fU 
                                                                  & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                                     >> 0x14U)))
                                                : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                   >> 
                                                   (0x1fU 
                                                    & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                       >> 0x14U))))
                                            : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                               ^ vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i)))
                                    : ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                        ? ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? ((vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                                < vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i)
                                                ? 1U
                                                : 0U)
                                            : (VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val, vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i)
                                                ? 1U
                                                : 0U))
                                        : ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__funct3))
                                            ? (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                               << (0x1fU 
                                                   & (vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                                                      >> 0x14U)))
                                            : (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                                               + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i))));
                            vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        } else {
                            __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                        }
                    } else {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    }
                } else if ((8U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                } else if ((4U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                } else if ((2U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__opcode))) {
                        vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_addr_reg 
                            = (vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                               + vlSelfRef.soc_top__DOT__u_scalar__DOT__imm_i);
                        __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read = 1U;
                        vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 1U;
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 4U;
                    } else {
                        __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                    }
                } else {
                    __Vdly__soc_top__DOT__u_scalar__DOT__state = 6U;
                }
            } else {
                vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val 
                    = (((0x10U > (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1)) 
                        & (0U != (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1)))
                        ? vlSelfRef.soc_top__DOT__u_scalar__DOT__regs
                       [(0xfU & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1))]
                        : 0U);
                vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 0U;
                __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read = 0U;
                __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write = 0U;
                vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc 
                    = ((IData)(4U) + vlSelfRef.soc_top__DOT__u_scalar__DOT__pc);
                __Vdly__soc_top__DOT__u_scalar__DOT__state = 3U;
                vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val 
                    = (((0x10U > (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2)) 
                        & (0U != (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2)))
                        ? vlSelfRef.soc_top__DOT__u_scalar__DOT__regs
                       [(0xfU & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2))]
                        : 0U);
            }
        } else if ((1U & (IData)(vlSelfRef.soc_top__DOT__u_scalar__DOT__state))) {
            if (vlSelfRef.soc_top__DOT__scalar_ready) {
                vlSelfRef.soc_top__DOT__u_scalar__DOT__inst 
                    = vlSelfRef.soc_top__DOT__scalar_rdata;
                vlSelfRef.soc_top__DOT__scalar_valid = 0U;
                __Vdly__soc_top__DOT__u_scalar__DOT__state = 2U;
            }
        } else {
            vlSelfRef.soc_top__DOT__scalar_addr = vlSelfRef.soc_top__DOT__u_scalar__DOT__pc;
            vlSelfRef.soc_top__DOT__scalar_valid = 1U;
            vlSelfRef.soc_top__DOT__scalar_wen = 0U;
            vlSelfRef.soc_top__DOT__scalar_wstrb = 0U;
            __Vdly__soc_top__DOT__u_scalar__DOT__state = 1U;
        }
    } else {
        __Vdly__soc_top__DOT__axi_awvalid = 0U;
        __Vdly__soc_top__DOT__axi_wvalid = 0U;
        __Vdly__soc_top__DOT__axi_arvalid = 0U;
        __Vdly__soc_top__DOT__axi_rready = 1U;
        __Vdly__soc_top__DOT__u_axi__DOT__state = 0U;
        __Vdly__soc_top__DOT__scalar_ready = 0U;
        __Vdly__soc_top__DOT__scalar_rdata = 0U;
        __Vdly__soc_top__DOT__vector_ready = 0U;
        __Vdly__soc_top__DOT__vector_rdata[0U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0U];
        __Vdly__soc_top__DOT__vector_rdata[1U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[1U];
        __Vdly__soc_top__DOT__vector_rdata[2U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[2U];
        __Vdly__soc_top__DOT__vector_rdata[3U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[3U];
        __Vdly__soc_top__DOT__vector_rdata[4U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[4U];
        __Vdly__soc_top__DOT__vector_rdata[5U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[5U];
        __Vdly__soc_top__DOT__vector_rdata[6U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[6U];
        __Vdly__soc_top__DOT__vector_rdata[7U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[7U];
        __Vdly__soc_top__DOT__vector_rdata[8U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[8U];
        __Vdly__soc_top__DOT__vector_rdata[9U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[9U];
        __Vdly__soc_top__DOT__vector_rdata[0xaU] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0xaU];
        __Vdly__soc_top__DOT__vector_rdata[0xbU] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0xbU];
        __Vdly__soc_top__DOT__vector_rdata[0xcU] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0xcU];
        __Vdly__soc_top__DOT__vector_rdata[0xdU] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0xdU];
        __Vdly__soc_top__DOT__vector_rdata[0xeU] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0xeU];
        __Vdly__soc_top__DOT__vector_rdata[0xfU] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0xfU];
        __Vdly__soc_top__DOT__axi_bready = 1U;
        __Vdly__soc_top__DOT__u_axi__DOT__burst_count = 0U;
        vlSelfRef.soc_top__DOT__u_axi__DOT__burst_len = 0U;
        vlSelfRef.soc_top__DOT__u_axi__DOT__saved_scalar_addr = 0U;
        vlSelfRef.soc_top__DOT__axi_awaddr = 0U;
        vlSelfRef.soc_top__DOT__axi_awlen = 0U;
        vlSelfRef.soc_top__DOT__axi_awsize = 0U;
        vlSelfRef.soc_top__DOT__axi_awburst = 0U;
        vlSelfRef.soc_top__DOT__axi_wdata[0U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0U];
        vlSelfRef.soc_top__DOT__axi_wdata[1U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[1U];
        vlSelfRef.soc_top__DOT__axi_wdata[2U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[2U];
        vlSelfRef.soc_top__DOT__axi_wdata[3U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[3U];
        vlSelfRef.soc_top__DOT__axi_wdata[4U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[4U];
        vlSelfRef.soc_top__DOT__axi_wdata[5U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[5U];
        vlSelfRef.soc_top__DOT__axi_wdata[6U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[6U];
        vlSelfRef.soc_top__DOT__axi_wdata[7U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[7U];
        vlSelfRef.soc_top__DOT__axi_wdata[8U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[8U];
        vlSelfRef.soc_top__DOT__axi_wdata[9U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[9U];
        vlSelfRef.soc_top__DOT__axi_wdata[0xaU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xaU];
        vlSelfRef.soc_top__DOT__axi_wdata[0xbU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xbU];
        vlSelfRef.soc_top__DOT__axi_wdata[0xcU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xcU];
        vlSelfRef.soc_top__DOT__axi_wdata[0xdU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xdU];
        vlSelfRef.soc_top__DOT__axi_wdata[0xeU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xeU];
        vlSelfRef.soc_top__DOT__axi_wdata[0xfU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelfRef.soc_top__DOT__axi_wstrb = 0ULL;
        __Vdly__soc_top__DOT__axi_wlast = 0U;
        __Vdly__soc_top__DOT__axi_araddr = 0U;
        vlSelfRef.soc_top__DOT__axi_arlen = 0U;
        vlSelfRef.soc_top__DOT__axi_arsize = 0U;
        vlSelfRef.soc_top__DOT__axi_arburst = 0U;
        __Vdly__soc_top__DOT__axi_arready = 0U;
        vlSelfRef.soc_top__DOT__axi_rdata[0U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0U];
        vlSelfRef.soc_top__DOT__axi_rdata[1U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[1U];
        vlSelfRef.soc_top__DOT__axi_rdata[2U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[2U];
        vlSelfRef.soc_top__DOT__axi_rdata[3U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[3U];
        vlSelfRef.soc_top__DOT__axi_rdata[4U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[4U];
        vlSelfRef.soc_top__DOT__axi_rdata[5U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[5U];
        vlSelfRef.soc_top__DOT__axi_rdata[6U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[6U];
        vlSelfRef.soc_top__DOT__axi_rdata[7U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[7U];
        vlSelfRef.soc_top__DOT__axi_rdata[8U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[8U];
        vlSelfRef.soc_top__DOT__axi_rdata[9U] = Vsoc_top__ConstPool__CONST_h93e1b771_0[9U];
        vlSelfRef.soc_top__DOT__axi_rdata[0xaU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xaU];
        vlSelfRef.soc_top__DOT__axi_rdata[0xbU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xbU];
        vlSelfRef.soc_top__DOT__axi_rdata[0xcU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xcU];
        vlSelfRef.soc_top__DOT__axi_rdata[0xdU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xdU];
        vlSelfRef.soc_top__DOT__axi_rdata[0xeU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xeU];
        vlSelfRef.soc_top__DOT__axi_rdata[0xfU] = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelfRef.soc_top__DOT__axi_rresp = 0U;
        vlSelfRef.soc_top__DOT__axi_rlast = 1U;
        __Vdly__soc_top__DOT__axi_rvalid = 0U;
        __Vdly__soc_top__DOT__u_rdma__DOT__queue_head = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_tail = 0U;
        __Vdly__soc_top__DOT__u_rdma__DOT__queue_count = 0U;
        __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count = 0U;
        __Vdly__soc_top__DOT__u_rdma__DOT__src_addr = 0U;
        __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr = 0U;
        __Vdly__soc_top__DOT__u_rdma__DOT__state = 0U;
        vlSelfRef.desc_ready = 1U;
        vlSelfRef.rdma_done = 0U;
        vlSelfRef.rdma_error = 0U;
        vlSelfRef.soc_top__DOT__vector_valid = 0U;
        vlSelfRef.soc_top__DOT__vector_addr = 0U;
        vlSelfRef.soc_top__DOT__vector_wdata[0U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[0U];
        vlSelfRef.soc_top__DOT__vector_wdata[1U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[1U];
        vlSelfRef.soc_top__DOT__vector_wdata[2U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[2U];
        vlSelfRef.soc_top__DOT__vector_wdata[3U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[3U];
        vlSelfRef.soc_top__DOT__vector_wdata[4U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[4U];
        vlSelfRef.soc_top__DOT__vector_wdata[5U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[5U];
        vlSelfRef.soc_top__DOT__vector_wdata[6U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[6U];
        vlSelfRef.soc_top__DOT__vector_wdata[7U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[7U];
        vlSelfRef.soc_top__DOT__vector_wdata[8U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[8U];
        vlSelfRef.soc_top__DOT__vector_wdata[9U] = 
            Vsoc_top__ConstPool__CONST_h93e1b771_0[9U];
        vlSelfRef.soc_top__DOT__vector_wdata[0xaU] 
            = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xaU];
        vlSelfRef.soc_top__DOT__vector_wdata[0xbU] 
            = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xbU];
        vlSelfRef.soc_top__DOT__vector_wdata[0xcU] 
            = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xcU];
        vlSelfRef.soc_top__DOT__vector_wdata[0xdU] 
            = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xdU];
        vlSelfRef.soc_top__DOT__vector_wdata[0xeU] 
            = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xeU];
        vlSelfRef.soc_top__DOT__vector_wdata[0xfU] 
            = Vsoc_top__ConstPool__CONST_h93e1b771_0[0xfU];
        vlSelfRef.soc_top__DOT__vector_wstrb = 0ULL;
        vlSelfRef.soc_top__DOT__vector_wen = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__current_desc[3U] = 0U;
        __VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v1 = 1U;
        __Vdly__soc_top__DOT__u_scalar__DOT__state = 0U;
        __Vdly__soc_top__DOT__u_scalar__DOT__pc = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__next_pc = 4U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__inst = 0x13U;
        vlSelfRef.soc_top__DOT__scalar_addr = 0U;
        vlSelfRef.soc_top__DOT__scalar_wdata = 0U;
        vlSelfRef.soc_top__DOT__scalar_wstrb = 0U;
        vlSelfRef.soc_top__DOT__scalar_valid = 0U;
        vlSelfRef.soc_top__DOT__scalar_wen = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__alu_result = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__do_reg_write = 0U;
        __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read = 0U;
        __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_addr_reg = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__mem_wdata_reg = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__rs1_val = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__rs2_val = 0U;
        __VdlySet__soc_top__DOT__u_scalar__DOT__regs__v1 = 1U;
    }
    vlSelfRef.soc_top__DOT__u_mem__DOT__write_addr 
        = __Vdly__soc_top__DOT__u_mem__DOT__write_addr;
    vlSelfRef.soc_top__DOT__u_mem__DOT__wstate = __Vdly__soc_top__DOT__u_mem__DOT__wstate;
    vlSelfRef.soc_top__DOT__axi_bresp = __Vdly__soc_top__DOT__axi_bresp;
    vlSelfRef.soc_top__DOT__u_axi__DOT__state = __Vdly__soc_top__DOT__u_axi__DOT__state;
    vlSelfRef.soc_top__DOT__axi_bvalid = __Vdly__soc_top__DOT__axi_bvalid;
    vlSelfRef.soc_top__DOT__axi_bready = __Vdly__soc_top__DOT__axi_bready;
    vlSelfRef.soc_top__DOT__axi_wlast = __Vdly__soc_top__DOT__axi_wlast;
    vlSelfRef.soc_top__DOT__axi_wready = __Vdly__soc_top__DOT__axi_wready;
    vlSelfRef.soc_top__DOT__axi_wvalid = __Vdly__soc_top__DOT__axi_wvalid;
    vlSelfRef.soc_top__DOT__u_axi__DOT__burst_count 
        = __Vdly__soc_top__DOT__u_axi__DOT__burst_count;
    vlSelfRef.soc_top__DOT__axi_awready = __Vdly__soc_top__DOT__axi_awready;
    vlSelfRef.soc_top__DOT__axi_awvalid = __Vdly__soc_top__DOT__axi_awvalid;
    vlSelfRef.soc_top__DOT__axi_araddr = __Vdly__soc_top__DOT__axi_araddr;
    vlSelfRef.soc_top__DOT__axi_arvalid = __Vdly__soc_top__DOT__axi_arvalid;
    vlSelfRef.soc_top__DOT__axi_arready = __Vdly__soc_top__DOT__axi_arready;
    vlSelfRef.__VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem.commit(vlSelfRef.soc_top__DOT__u_mem__DOT__mem);
    vlSelfRef.soc_top__DOT__axi_rvalid = __Vdly__soc_top__DOT__axi_rvalid;
    vlSelfRef.soc_top__DOT__axi_rready = __Vdly__soc_top__DOT__axi_rready;
    vlSelfRef.soc_top__DOT__vector_rdata[0U] = __Vdly__soc_top__DOT__vector_rdata[0U];
    vlSelfRef.soc_top__DOT__vector_rdata[1U] = __Vdly__soc_top__DOT__vector_rdata[1U];
    vlSelfRef.soc_top__DOT__vector_rdata[2U] = __Vdly__soc_top__DOT__vector_rdata[2U];
    vlSelfRef.soc_top__DOT__vector_rdata[3U] = __Vdly__soc_top__DOT__vector_rdata[3U];
    vlSelfRef.soc_top__DOT__vector_rdata[4U] = __Vdly__soc_top__DOT__vector_rdata[4U];
    vlSelfRef.soc_top__DOT__vector_rdata[5U] = __Vdly__soc_top__DOT__vector_rdata[5U];
    vlSelfRef.soc_top__DOT__vector_rdata[6U] = __Vdly__soc_top__DOT__vector_rdata[6U];
    vlSelfRef.soc_top__DOT__vector_rdata[7U] = __Vdly__soc_top__DOT__vector_rdata[7U];
    vlSelfRef.soc_top__DOT__vector_rdata[8U] = __Vdly__soc_top__DOT__vector_rdata[8U];
    vlSelfRef.soc_top__DOT__vector_rdata[9U] = __Vdly__soc_top__DOT__vector_rdata[9U];
    vlSelfRef.soc_top__DOT__vector_rdata[0xaU] = __Vdly__soc_top__DOT__vector_rdata[0xaU];
    vlSelfRef.soc_top__DOT__vector_rdata[0xbU] = __Vdly__soc_top__DOT__vector_rdata[0xbU];
    vlSelfRef.soc_top__DOT__vector_rdata[0xcU] = __Vdly__soc_top__DOT__vector_rdata[0xcU];
    vlSelfRef.soc_top__DOT__vector_rdata[0xdU] = __Vdly__soc_top__DOT__vector_rdata[0xdU];
    vlSelfRef.soc_top__DOT__vector_rdata[0xeU] = __Vdly__soc_top__DOT__vector_rdata[0xeU];
    vlSelfRef.soc_top__DOT__vector_rdata[0xfU] = __Vdly__soc_top__DOT__vector_rdata[0xfU];
    vlSelfRef.soc_top__DOT__vector_ready = __Vdly__soc_top__DOT__vector_ready;
    vlSelfRef.soc_top__DOT__u_rdma__DOT__state = __Vdly__soc_top__DOT__u_rdma__DOT__state;
    vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_head 
        = __Vdly__soc_top__DOT__u_rdma__DOT__queue_head;
    vlSelfRef.soc_top__DOT__u_rdma__DOT__queue_count 
        = __Vdly__soc_top__DOT__u_rdma__DOT__queue_count;
    vlSelfRef.soc_top__DOT__u_rdma__DOT__transfer_count 
        = __Vdly__soc_top__DOT__u_rdma__DOT__transfer_count;
    vlSelfRef.soc_top__DOT__u_rdma__DOT__src_addr = __Vdly__soc_top__DOT__u_rdma__DOT__src_addr;
    vlSelfRef.soc_top__DOT__u_rdma__DOT__dst_addr = __Vdly__soc_top__DOT__u_rdma__DOT__dst_addr;
    if (__VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v0) {
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[__VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0][0U] 
            = __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[0U];
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[__VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0][1U] 
            = __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[1U];
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[__VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0][2U] 
            = __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[2U];
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[__VdlyDim0__soc_top__DOT__u_rdma__DOT__desc_queue__v0][3U] 
            = __VdlyVal__soc_top__DOT__u_rdma__DOT__desc_queue__v0[3U];
    }
    if (__VdlySet__soc_top__DOT__u_rdma__DOT__desc_queue__v1) {
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[1U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[1U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[1U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[1U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[2U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[2U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[2U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[2U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[3U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[3U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[3U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[3U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[4U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[4U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[4U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[4U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[5U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[5U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[5U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[5U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[6U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[6U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[6U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[6U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[7U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[7U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[7U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[7U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[8U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[8U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[8U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[8U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[9U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[9U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[9U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[9U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xaU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xaU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xaU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xaU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xbU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xbU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xbU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xbU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xcU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xcU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xcU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xcU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xdU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xdU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xdU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xdU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xeU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xeU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xeU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xeU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xfU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xfU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xfU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0xfU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x10U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x10U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x10U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x10U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x11U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x11U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x11U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x11U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x12U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x12U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x12U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x12U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x13U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x13U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x13U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x13U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x14U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x14U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x14U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x14U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x15U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x15U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x15U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x15U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x16U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x16U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x16U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x16U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x17U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x17U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x17U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x17U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x18U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x18U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x18U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x18U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x19U][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x19U][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x19U][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x19U][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1aU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1aU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1aU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1aU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1bU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1bU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1bU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1bU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1cU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1cU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1cU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1cU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1dU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1dU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1dU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1dU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1eU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1eU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1eU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1eU][3U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1fU][0U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1fU][1U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1fU][2U] = 0U;
        vlSelfRef.soc_top__DOT__u_rdma__DOT__desc_queue[0x1fU][3U] = 0U;
    }
    vlSelfRef.soc_top__DOT__scalar_ready = __Vdly__soc_top__DOT__scalar_ready;
    vlSelfRef.soc_top__DOT__scalar_rdata = __Vdly__soc_top__DOT__scalar_rdata;
    vlSelfRef.soc_top__DOT__u_scalar__DOT__state = __Vdly__soc_top__DOT__u_scalar__DOT__state;
    vlSelfRef.soc_top__DOT__u_scalar__DOT__pc = __Vdly__soc_top__DOT__u_scalar__DOT__pc;
    vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_read 
        = __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_read;
    vlSelfRef.soc_top__DOT__u_scalar__DOT__do_mem_write 
        = __Vdly__soc_top__DOT__u_scalar__DOT__do_mem_write;
    if (__VdlySet__soc_top__DOT__u_scalar__DOT__regs__v0) {
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[__VdlyDim0__soc_top__DOT__u_scalar__DOT__regs__v0] 
            = __VdlyVal__soc_top__DOT__u_scalar__DOT__regs__v0;
    }
    if (__VdlySet__soc_top__DOT__u_scalar__DOT__regs__v1) {
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[1U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[2U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[3U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[4U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[5U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[6U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[7U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[8U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[9U] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0xaU] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0xbU] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0xcU] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0xdU] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0xeU] = 0U;
        vlSelfRef.soc_top__DOT__u_scalar__DOT__regs[0xfU] = 0U;
    }
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

void Vsoc_top___024root___eval_triggers__act(Vsoc_top___024root* vlSelf);

bool Vsoc_top___024root___eval_phase__act(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__act\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsoc_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsoc_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsoc_top___024root___eval_phase__nba(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__nba\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsoc_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__nba(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(Vsoc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsoc_top___024root___eval(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/soc_top.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsoc_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/soc_top.v", 4, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsoc_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsoc_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsoc_top___024root___eval_debug_assertions(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_debug_assertions\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.desc_valid & 0xfeU)))) {
        Verilated::overWidthError("desc_valid");}
}
#endif  // VL_DEBUG
