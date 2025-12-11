// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsoc_top.h for the primary calling header

#ifndef VERILATED_VSOC_TOP___024ROOT_H_
#define VERILATED_VSOC_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vsoc_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsoc_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(desc_valid,0,0);
        VL_OUT8(desc_ready,0,0);
        VL_OUT8(rdma_done,0,0);
        VL_OUT8(rdma_error,0,0);
        VL_OUT8(mem_test_pass,0,0);
        CData/*3:0*/ soc_top__DOT__scalar_wstrb;
        CData/*0:0*/ soc_top__DOT__scalar_valid;
        CData/*0:0*/ soc_top__DOT__scalar_wen;
        CData/*0:0*/ soc_top__DOT__scalar_ready;
        CData/*0:0*/ soc_top__DOT__vector_valid;
        CData/*0:0*/ soc_top__DOT__vector_wen;
        CData/*0:0*/ soc_top__DOT__vector_ready;
        CData/*7:0*/ soc_top__DOT__axi_awlen;
        CData/*2:0*/ soc_top__DOT__axi_awsize;
        CData/*1:0*/ soc_top__DOT__axi_awburst;
        CData/*0:0*/ soc_top__DOT__axi_awvalid;
        CData/*0:0*/ soc_top__DOT__axi_awready;
        CData/*0:0*/ soc_top__DOT__axi_wlast;
        CData/*0:0*/ soc_top__DOT__axi_wvalid;
        CData/*0:0*/ soc_top__DOT__axi_wready;
        CData/*1:0*/ soc_top__DOT__axi_bresp;
        CData/*0:0*/ soc_top__DOT__axi_bvalid;
        CData/*0:0*/ soc_top__DOT__axi_bready;
        CData/*7:0*/ soc_top__DOT__axi_arlen;
        CData/*2:0*/ soc_top__DOT__axi_arsize;
        CData/*1:0*/ soc_top__DOT__axi_arburst;
        CData/*0:0*/ soc_top__DOT__axi_arvalid;
        CData/*0:0*/ soc_top__DOT__axi_arready;
        CData/*1:0*/ soc_top__DOT__axi_rresp;
        CData/*0:0*/ soc_top__DOT__axi_rlast;
        CData/*0:0*/ soc_top__DOT__axi_rvalid;
        CData/*0:0*/ soc_top__DOT__axi_rready;
        CData/*2:0*/ soc_top__DOT__u_scalar__DOT__state;
        CData/*6:0*/ soc_top__DOT__u_scalar__DOT__opcode;
        CData/*4:0*/ soc_top__DOT__u_scalar__DOT__rd;
        CData/*2:0*/ soc_top__DOT__u_scalar__DOT__funct3;
        CData/*4:0*/ soc_top__DOT__u_scalar__DOT__rs1;
        CData/*4:0*/ soc_top__DOT__u_scalar__DOT__rs2;
        CData/*6:0*/ soc_top__DOT__u_scalar__DOT__funct7;
        CData/*0:0*/ soc_top__DOT__u_scalar__DOT__do_reg_write;
        CData/*0:0*/ soc_top__DOT__u_scalar__DOT__do_mem_read;
        CData/*0:0*/ soc_top__DOT__u_scalar__DOT__do_mem_write;
        CData/*0:0*/ soc_top__DOT__u_scalar__DOT__unnamedblk1__DOT__branch_taken;
        CData/*4:0*/ soc_top__DOT__u_rdma__DOT__queue_head;
        CData/*4:0*/ soc_top__DOT__u_rdma__DOT__queue_tail;
        CData/*4:0*/ soc_top__DOT__u_rdma__DOT__queue_count;
        CData/*2:0*/ soc_top__DOT__u_rdma__DOT__state;
        CData/*3:0*/ soc_top__DOT__u_axi__DOT__state;
        CData/*7:0*/ soc_top__DOT__u_axi__DOT__burst_count;
        CData/*7:0*/ soc_top__DOT__u_axi__DOT__burst_len;
        CData/*1:0*/ soc_top__DOT__u_mem__DOT__wstate;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_IN(desc_addr,31,0);
        IData/*31:0*/ soc_top__DOT__scalar_addr;
        IData/*31:0*/ soc_top__DOT__scalar_wdata;
        IData/*31:0*/ soc_top__DOT__scalar_rdata;
        IData/*31:0*/ soc_top__DOT__vector_addr;
        VlWide<16>/*511:0*/ soc_top__DOT__vector_wdata;
        VlWide<16>/*511:0*/ soc_top__DOT__vector_rdata;
    };
    struct {
        IData/*31:0*/ soc_top__DOT__axi_awaddr;
        VlWide<16>/*511:0*/ soc_top__DOT__axi_wdata;
        IData/*31:0*/ soc_top__DOT__axi_araddr;
        VlWide<16>/*511:0*/ soc_top__DOT__axi_rdata;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__pc;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__next_pc;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__inst;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__imm_i;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__imm_s;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__imm_b;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__imm_u;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__imm_j;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__rs1_val;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__rs2_val;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__alu_result;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__mem_addr_reg;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__mem_wdata_reg;
        IData/*31:0*/ soc_top__DOT__u_scalar__DOT__i;
        VlWide<4>/*127:0*/ soc_top__DOT__u_rdma__DOT__current_desc;
        IData/*31:0*/ soc_top__DOT__u_rdma__DOT__transfer_count;
        IData/*31:0*/ soc_top__DOT__u_rdma__DOT__src_addr;
        IData/*31:0*/ soc_top__DOT__u_rdma__DOT__dst_addr;
        IData/*31:0*/ soc_top__DOT__u_rdma__DOT__i;
        IData/*31:0*/ soc_top__DOT__u_axi__DOT__saved_scalar_addr;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__write_addr;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__i;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__j;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__piece;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__idx;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__unnamedblk1__DOT__sub;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__idx_r;
        IData/*31:0*/ soc_top__DOT__u_mem__DOT__unnamedblk2__DOT__sub_r;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ soc_top__DOT__vector_wstrb;
        QData/*63:0*/ soc_top__DOT__axi_wstrb;
        VlUnpacked<IData/*31:0*/, 16> soc_top__DOT__u_scalar__DOT__regs;
        VlUnpacked<VlWide<4>/*127:0*/, 32> soc_top__DOT__u_rdma__DOT__desc_queue;
        VlUnpacked<VlWide<16>/*511:0*/, 1024> soc_top__DOT__u_mem__DOT__mem;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlNBACommitQueue<VlUnpacked<VlWide<16>/*511:0*/, 1024>, true, VlWide<16>/*511:0*/, 1> __VdlyCommitQueuesoc_top__DOT__u_mem__DOT__mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsoc_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsoc_top___024root(Vsoc_top__Syms* symsp, const char* v__name);
    ~Vsoc_top___024root();
    VL_UNCOPYABLE(Vsoc_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
