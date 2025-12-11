//==============================================================================
// Vector Instruction Decoder
// Decodes RVV 1.0 instructions and generates control signals
// Supports all instruction formats: OPIVV, OPFVV, OPMVV, OPIVX, OPFVF, OPMVX,
// OPIVI, OPMVI, OPCFG, LOAD-FP, STORE-FP
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_decoder (
    input wire [31:0] inst,
    input wire        valid,
    
    // Decoded outputs
    output reg        is_vector_inst,
    output reg        is_vector_arith,
    output reg        is_vector_load,
    output reg        is_vector_store,
    output reg        is_vector_config,
    output reg        is_vector_mask_op,
    output reg        is_vector_reduction,
    output reg        is_vector_permute,
    output reg        is_widening,
    output reg        is_narrowing,
    output reg        is_fp_op,
    
    // Operand addresses
    output reg [4:0]  vd,
    output reg [4:0]  vs1,
    output reg [4:0]  vs2,
    output reg [4:0]  rs1,
    output reg [4:0]  rs2,
    
    // Operation encoding
    output reg [5:0]  funct6,
    output reg [5:0]  valu_op,
    output reg [2:0]  width,
    output reg [2:0]  mop,
    output reg [2:0]  nf,
    output reg        vm,
    output reg [10:0] zimm,
    output reg [4:0]  imm5,
    
    // Load/store specific
    output reg [1:0]  lumop,
    output reg [1:0]  sumop,
    output reg        whole_reg,
    output reg        unit_stride,
    output reg        strided,
    output reg        indexed,
    output reg        segment,
    output reg        fault_only_first
);

    wire [6:0] opcode = inst[6:0];
    wire [2:0] funct3 = inst[14:12];
    wire [5:0] funct6_field = inst[31:26];
    wire       funct1 = inst[25];
    wire [4:0] zimm11 = inst[19:15];
    
    always @(*) begin
        // Defaults
        is_vector_inst = 1'b0;
        is_vector_arith = 1'b0;
        is_vector_load = 1'b0;
        is_vector_store = 1'b0;
        is_vector_config = 1'b0;
        is_vector_mask_op = 1'b0;
        is_vector_reduction = 1'b0;
        is_vector_permute = 1'b0;
        is_widening = 1'b0;
        is_narrowing = 1'b0;
        is_fp_op = 1'b0;
        
        vd = inst[11:7];
        vs1 = inst[19:15];
        vs2 = inst[24:20];
        rs1 = inst[19:15];
        rs2 = inst[24:20];
        
        funct6 = funct6_field;
        valu_op = funct6_field;
        width = funct3;
        mop = inst[27:26];
        nf = inst[31:29];
        vm = inst[25];
        zimm = inst[30:20];
        imm5 = inst[19:15];
        
        lumop = inst[24:20];
        sumop = inst[24:20];
        whole_reg = 1'b0;
        unit_stride = 1'b0;
        strided = 1'b0;
        indexed = 1'b0;
        segment = 1'b0;
        fault_only_first = 1'b0;
        
        if (valid && opcode == `OPCODE_VECTOR) begin
            is_vector_inst = 1'b1;
            
            case (funct3)
                //--------------------------------------------------------------
                // Vector-Vector Arithmetic (OPIVV, OPMVV, OPFVV)
                //--------------------------------------------------------------
                3'b000: begin // OPIVV
                    is_vector_arith = 1'b1;
                    case (funct6_field)
                        6'h00: valu_op = 6'h00; // vadd.vv
                        6'h02: valu_op = 6'h02; // vsub.vv
                        6'h04: valu_op = 6'h04; // vminu.vv
                        6'h05: valu_op = 6'h05; // vmin.vv
                        6'h06: valu_op = 6'h06; // vmaxu.vv
                        6'h07: valu_op = 6'h07; // vmax.vv
                        6'h09: valu_op = 6'h09; // vand.vv
                        6'h0A: valu_op = 6'h0A; // vor.vv
                        6'h0B: valu_op = 6'h0B; // vxor.vv
                        6'h0C: valu_op = 6'h0C; // vrgather.vv
                        6'h0E: begin // vrgatherei16.vv
                            valu_op = 6'h0E;
                            is_vector_permute = 1'b1;
                        end
                        6'h10: begin // vadc.vvm
                            valu_op = 6'h10;
                            vm = 1'b0; // Always unmasked for carry ops
                        end
                        6'h11: valu_op = 6'h11; // vmadc.vvm
                        6'h12: valu_op = 6'h12; // vsbc.vvm
                        6'h13: valu_op = 6'h13; // vmsbc.vvm
                        6'h17: begin // vmerge.vvm / vmv.v.v
                            valu_op = 6'h17;
                            is_vector_permute = (vs2 == 5'b0); // vmv.v.v when vs2=0
                        end
                        6'h18: valu_op = 6'h18; // vmseq.vv
                        6'h19: valu_op = 6'h19; // vmsne.vv
                        6'h1A: valu_op = 6'h1A; // vmsltu.vv
                        6'h1B: valu_op = 6'h1B; // vmslt.vv
                        6'h1C: valu_op = 6'h1C; // vmsleu.vv
                        6'h1D: valu_op = 6'h1D; // vmsle.vv
                        6'h1E: valu_op = 6'h1E; // vmsgt.vv (pseudo)
                        6'h1F: valu_op = 6'h1F; // vmsgtu.vv (pseudo)
                        6'h20: valu_op = 6'h20; // vsaddu.vv
                        6'h21: valu_op = 6'h21; // vsadd.vv
                        6'h22: valu_op = 6'h22; // vssubu.vv
                        6'h23: valu_op = 6'h23; // vssub.vv
                        6'h25: valu_op = 6'h25; // vsll.vv
                        6'h26: valu_op = 6'h26; // vsmul.vv
                        6'h27: valu_op = 6'h27; // vmv<nr>r.v (whole register move)
                        6'h28: valu_op = 6'h28; // vsrl.vv
                        6'h29: valu_op = 6'h29; // vsra.vv
                        6'h2A: valu_op = 6'h2A; // vssrl.vv
                        6'h2B: valu_op = 6'h2B; // vssra.vv
                        6'h2C: valu_op = 6'h2C; // vnsrl.wv (narrowing)
                        6'h2D: valu_op = 6'h2D; // vnsra.wv (narrowing)
                        6'h2E: valu_op = 6'h2E; // vnclipu.wv (narrowing clip)
                        6'h2F: valu_op = 6'h2F; // vnclip.wv (narrowing clip)
                        default: valu_op = 6'h00;
                    endcase
                    
                    // Detect widening operations (wv suffix)
                    if (funct6_field[5:4] == 2'b11) begin
                        is_widening = (funct6_field[3:0] >= 4'h0 && funct6_field[3:0] <= 4'h7);
                    end
                    
                    // Detect narrowing operations (w prefix in name)
                    if (funct6_field >= 6'h2C && funct6_field <= 6'h2F) begin
                        is_narrowing = 1'b1;
                    end
                end
                
                3'b001: begin // OPFVV - Floating-point vector-vector
                    is_vector_arith = 1'b1;
                    is_fp_op = 1'b1;
                    case (funct6_field)
                        6'h00: valu_op = 6'h00; // vfadd.vv
                        6'h01: begin // vfredusum.vs
                            valu_op = 6'h01;
                            is_vector_reduction = 1'b1;
                        end
                        6'h02: valu_op = 6'h02; // vfsub.vv
                        6'h03: begin // vfredosum.vs
                            valu_op = 6'h03;
                            is_vector_reduction = 1'b1;
                        end
                        6'h04: valu_op = 6'h04; // vfmin.vv
                        6'h05: begin // vfredmin.vs
                            valu_op = 6'h05;
                            is_vector_reduction = 1'b1;
                        end
                        6'h06: valu_op = 6'h06; // vfmax.vv
                        6'h07: begin // vfredmax.vs
                            valu_op = 6'h07;
                            is_vector_reduction = 1'b1;
                        end
                        6'h08: valu_op = 6'h08; // vfsgnj.vv
                        6'h09: valu_op = 6'h09; // vfsgnjn.vv
                        6'h0A: valu_op = 6'h0A; // vfsgnjx.vv
                        6'h10: valu_op = 6'h10; // vfmv.f.s (vector-scalar move)
                        6'h18: valu_op = 6'h18; // vmfeq.vv
                        6'h19: valu_op = 6'h19; // vmfle.vv
                        6'h1B: valu_op = 6'h1B; // vmflt.vv
                        6'h1C: valu_op = 6'h1C; // vmfne.vv
                        6'h1D: valu_op = 6'h1D; // vmfgt.vv (pseudo)
                        6'h1F: valu_op = 6'h1F; // vmfge.vv (pseudo)
                        6'h20: valu_op = 6'h20; // vfdiv.vv
                        6'h24: valu_op = 6'h24; // vfmul.vv
                        6'h27: valu_op = 6'h27; // vfmerge.vfm
                        6'h28: begin // vfmadd.vv
                            valu_op = 6'h28;
                        end
                        6'h29: valu_op = 6'h29; // vfnmadd.vv
                        6'h2A: valu_op = 6'h2A; // vfmsub.vv
                        6'h2B: valu_op = 6'h2B; // vfnmsub.vv
                        6'h2C: valu_op = 6'h2C; // vfmacc.vv
                        6'h2D: valu_op = 6'h2D; // vfnmacc.vv
                        6'h2E: valu_op = 6'h2E; // vfmsac.vv
                        6'h2F: valu_op = 6'h2F; // vfnmsac.vv
                        6'h30: valu_op = 6'h30; // vfwadd.vv (widening)
                        6'h31: begin // vfwredusum.vs
                            valu_op = 6'h31;
                            is_vector_reduction = 1'b1;
                            is_widening = 1'b1;
                        end
                        6'h32: valu_op = 6'h32; // vfwsub.vv (widening)
                        6'h33: begin // vfwredosum.vs
                            valu_op = 6'h33;
                            is_vector_reduction = 1'b1;
                            is_widening = 1'b1;
                        end
                        6'h34: valu_op = 6'h34; // vfwadd.wv (widening)
                        6'h36: valu_op = 6'h36; // vfwsub.wv (widening)
                        6'h38: valu_op = 6'h38; // vfwmul.vv (widening)
                        6'h3C: valu_op = 6'h3C; // vfwmacc.vv (widening)
                        6'h3D: valu_op = 6'h3D; // vfwnmacc.vv (widening)
                        6'h3E: valu_op = 6'h3E; // vfwmsac.vv (widening)
                        6'h3F: valu_op = 6'h3F; // vfwnmsac.vv (widening)
                        default: valu_op = 6'h00;
                    endcase
                    
                    // Widening FP operations
                    if (funct6_field >= 6'h30 && funct6_field <= 6'h3F) begin
                        is_widening = 1'b1;
                    end
                end
                
                3'b010: begin // OPMVV - Mask/integer ops
                    case (funct6_field)
                        6'h00: begin // vredsum.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h00;
                        end
                        6'h01: begin // vredand.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h01;
                        end
                        6'h02: begin // vredor.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h02;
                        end
                        6'h03: begin // vredxor.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h03;
                        end
                        6'h04: begin // vredminu.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h04;
                        end
                        6'h05: begin // vredmin.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h05;
                        end
                        6'h06: begin // vredmaxu.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h06;
                        end
                        6'h07: begin // vredmax.vs
                            is_vector_reduction = 1'b1;
                            valu_op = 6'h07;
                        end
                        6'h08: begin // vaaddu.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h08;
                        end
                        6'h09: begin // vaadd.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h09;
                        end
                        6'h0A: begin // vasubu.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h0A;
                        end
                        6'h0B: begin // vasub.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h0B;
                        end
                        6'h10: begin // vwxunary0 - Contains vmv.x.s, vcpop.m, vfirst.m
                            is_vector_mask_op = (vs2[4:3] == 2'b10);
                            is_vector_permute = (vs2 == 5'b00000); // vmv.x.s
                            valu_op = {1'b0, vs2};
                        end
                        6'h11: begin // vrxunary0 - Contains vmv.s.x
                            is_vector_permute = 1'b1;
                            valu_op = 6'h11;
                        end
                        6'h12: begin // vmunary0 - Contains mask ops (vmsbf, vmsif, vmsof, viota, vid)
                            is_vector_mask_op = 1'b1;
                            valu_op = {1'b0, vs1};
                        end
                        6'h14: begin // vmunary0 - vpopc, vid, etc
                            is_vector_mask_op = 1'b1;
                            valu_op = {1'b0, vs1};
                        end
                        6'h17: begin // vcompress.vm
                            is_vector_permute = 1'b1;
                            valu_op = 6'h17;
                        end
                        6'h18: begin // vmandnot.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h18;
                        end
                        6'h19: begin // vmand.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h19;
                        end
                        6'h1A: begin // vmor.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h1A;
                        end
                        6'h1B: begin // vmxor.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h1B;
                        end
                        6'h1C: begin // vmornot.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h1C;
                        end
                        6'h1D: begin // vmnand.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h1D;
                        end
                        6'h1E: begin // vmnor.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h1E;
                        end
                        6'h1F: begin // vmxnor.mm
                            is_vector_mask_op = 1'b1;
                            valu_op = 6'h1F;
                        end
                        6'h20: begin // vdivu.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h20;
                        end
                        6'h21: begin // vdiv.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h21;
                        end
                        6'h22: begin // vremu.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h22;
                        end
                        6'h23: begin // vrem.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h23;
                        end
                        6'h24: begin // vmulhu.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h24;
                        end
                        6'h25: begin // vmul.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h25;
                        end
                        6'h26: begin // vmulhsu.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h26;
                        end
                        6'h27: begin // vmulh.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h27;
                        end
                        6'h29: begin // vmadd.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h29;
                        end
                        6'h2B: begin // vnmsub.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h2B;
                        end
                        6'h2D: begin // vmacc.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h2D;
                        end
                        6'h2F: begin // vnmsac.vv
                            is_vector_arith = 1'b1;
                            valu_op = 6'h2F;
                        end
                        6'h30: begin // vwaddu.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h30;
                        end
                        6'h31: begin // vwadd.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h31;
                        end
                        6'h32: begin // vwsubu.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h32;
                        end
                        6'h33: begin // vwsub.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h33;
                        end
                        6'h34: begin // vwaddu.wv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h34;
                        end
                        6'h35: begin // vwadd.wv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h35;
                        end
                        6'h36: begin // vwsubu.wv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h36;
                        end
                        6'h37: begin // vwsub.wv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h37;
                        end
                        6'h38: begin // vwmulu.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h38;
                        end
                        6'h3A: begin // vwmulsu.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3A;
                        end
                        6'h3B: begin // vwmul.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3B;
                        end
                        6'h3C: begin // vwmaccu.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3C;
                        end
                        6'h3D: begin // vwmacc.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3D;
                        end
                        6'h3F: begin // vwmaccsu.vv (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3F;
                        end
                        default: valu_op = 6'h00;
                    endcase
                end
                
                //--------------------------------------------------------------
                // Vector-Scalar and Vector-Immediate ops
                //--------------------------------------------------------------
                3'b011: begin // OPIVI - Vector-immediate
                    is_vector_arith = 1'b1;
                    case (funct6_field)
                        6'h00: valu_op = 6'h00; // vadd.vi
                        6'h02: valu_op = 6'h02; // vrsub.vi
                        6'h03: valu_op = 6'h03; // vnot (pseudo)
                        6'h09: valu_op = 6'h09; // vand.vi
                        6'h0A: valu_op = 6'h0A; // vor.vi
                        6'h0B: valu_op = 6'h0B; // vxor.vi
                        6'h0C: begin // vrgather.vi
                            valu_op = 6'h0C;
                            is_vector_permute = 1'b1;
                        end
                        6'h0E: begin // vslideup.vi
                            valu_op = 6'h0E;
                            is_vector_permute = 1'b1;
                        end
                        6'h0F: begin // vslidedown.vi
                            valu_op = 6'h0F;
                            is_vector_permute = 1'b1;
                        end
                        6'h10: valu_op = 6'h10; // vadc.vim
                        6'h11: valu_op = 6'h11; // vmadc.vim
                        6'h17: begin // vmerge.vim / vmv.v.i
                            valu_op = 6'h17;
                            is_vector_permute = (vm == 1'b1); // vmv.v.i when unmasked
                        end
                        6'h18: valu_op = 6'h18; // vmseq.vi
                        6'h19: valu_op = 6'h19; // vmsne.vi
                        6'h1A: valu_op = 6'h1A; // vmsleu.vi
                        6'h1B: valu_op = 6'h1B; // vmsle.vi
                        6'h1E: valu_op = 6'h1E; // vmsgtu.vi
                        6'h1F: valu_op = 6'h1F; // vmsgt.vi
                        6'h20: valu_op = 6'h20; // vsaddu.vi
                        6'h21: valu_op = 6'h21; // vsadd.vi
                        6'h25: valu_op = 6'h25; // vsll.vi
                        6'h27: begin // vmv1r.v, vmv2r.v, etc (whole reg move)
                            valu_op = 6'h27;
                            is_vector_permute = 1'b1;
                            whole_reg = 1'b1;
                        end
                        6'h28: valu_op = 6'h28; // vsrl.vi
                        6'h29: valu_op = 6'h29; // vsra.vi
                        6'h2A: valu_op = 6'h2A; // vssrl.vi
                        6'h2B: valu_op = 6'h2B; // vssra.vi
                        6'h2C: begin // vnsrl.wi (narrowing)
                            valu_op = 6'h2C;
                            is_narrowing = 1'b1;
                        end
                        6'h2D: begin // vnsra.wi (narrowing)
                            valu_op = 6'h2D;
                            is_narrowing = 1'b1;
                        end
                        6'h2E: begin // vnclipu.wi (narrowing)
                            valu_op = 6'h2E;
                            is_narrowing = 1'b1;
                        end
                        6'h2F: begin // vnclip.wi (narrowing)
                            valu_op = 6'h2F;
                            is_narrowing = 1'b1;
                        end
                        default: valu_op = 6'h00;
                    endcase
                end
                
                3'b100: begin // OPIVX - Vector-scalar
                    is_vector_arith = 1'b1;
                    case (funct6_field)
                        6'h00: valu_op = 6'h00; // vadd.vx
                        6'h02: valu_op = 6'h02; // vsub.vx
                        6'h04: valu_op = 6'h04; // vminu.vx
                        6'h05: valu_op = 6'h05; // vmin.vx
                        6'h06: valu_op = 6'h06; // vmaxu.vx
                        6'h07: valu_op = 6'h07; // vmax.vx
                        6'h09: valu_op = 6'h09; // vand.vx
                        6'h0A: valu_op = 6'h0A; // vor.vx
                        6'h0B: valu_op = 6'h0B; // vxor.vx
                        6'h0C: begin // vrgather.vx
                            valu_op = 6'h0C;
                            is_vector_permute = 1'b1;
                        end
                        6'h0E: begin // vslideup.vx
                            valu_op = 6'h0E;
                            is_vector_permute = 1'b1;
                        end
                        6'h0F: begin // vslidedown.vx
                            valu_op = 6'h0F;
                            is_vector_permute = 1'b1;
                        end
                        6'h10: valu_op = 6'h10; // vadc.vxm
                        6'h11: valu_op = 6'h11; // vmadc.vxm
                        6'h12: valu_op = 6'h12; // vsbc.vxm
                        6'h13: valu_op = 6'h13; // vmsbc.vxm
                        6'h17: begin // vmerge.vxm / vmv.v.x
                            valu_op = 6'h17;
                            is_vector_permute = (vm == 1'b1);
                        end
                        6'h18: valu_op = 6'h18; // vmseq.vx
                        6'h19: valu_op = 6'h19; // vmsne.vx
                        6'h1A: valu_op = 6'h1A; // vmsltu.vx
                        6'h1B: valu_op = 6'h1B; // vmslt.vx
                        6'h1C: valu_op = 6'h1C; // vmsleu.vx
                        6'h1D: valu_op = 6'h1D; // vmsle.vx
                        6'h1E: valu_op = 6'h1E; // vmsgtu.vx
                        6'h1F: valu_op = 6'h1F; // vmsgt.vx
                        6'h20: valu_op = 6'h20; // vsaddu.vx
                        6'h21: valu_op = 6'h21; // vsadd.vx
                        6'h22: valu_op = 6'h22; // vssubu.vx
                        6'h23: valu_op = 6'h23; // vssub.vx
                        6'h25: valu_op = 6'h25; // vsll.vx
                        6'h26: valu_op = 6'h26; // vsmul.vx
                        6'h27: begin // vslide1up.vx
                            valu_op = 6'h27;
                            is_vector_permute = 1'b1;
                        end
                        6'h28: valu_op = 6'h28; // vsrl.vx
                        6'h29: valu_op = 6'h29; // vsra.vx
                        6'h2A: valu_op = 6'h2A; // vssrl.vx
                        6'h2B: valu_op = 6'h2B; // vssra.vx
                        6'h2C: begin // vnsrl.wx (narrowing)
                            valu_op = 6'h2C;
                            is_narrowing = 1'b1;
                        end
                        6'h2D: begin // vnsra.wx (narrowing)
                            valu_op = 6'h2D;
                            is_narrowing = 1'b1;
                        end
                        6'h2E: begin // vnclipu.wx (narrowing)
                            valu_op = 6'h2E;
                            is_narrowing = 1'b1;
                        end
                        6'h2F: begin // vnclip.wx (narrowing)
                            valu_op = 6'h2F;
                            is_narrowing = 1'b1;
                        end
                        6'h39: begin // vslide1down.vx
                            valu_op = 6'h39;
                            is_vector_permute = 1'b1;
                        end
                        default: valu_op = 6'h00;
                    endcase
                end
                
                3'b101: begin // OPFVF - Floating-point vector-scalar
                    is_vector_arith = 1'b1;
                    is_fp_op = 1'b1;
                    case (funct6_field)
                        6'h00: valu_op = 6'h00; // vfadd.vf
                        6'h02: valu_op = 6'h02; // vfsub.vf
                        6'h04: valu_op = 6'h04; // vfmin.vf
                        6'h06: valu_op = 6'h06; // vfmax.vf
                        6'h08: valu_op = 6'h08; // vfsgnj.vf
                        6'h09: valu_op = 6'h09; // vfsgnjn.vf
                        6'h0A: valu_op = 6'h0A; // vfsgnjx.vf
                        6'h0E: begin // vfslide1up.vf
                            valu_op = 6'h0E;
                            is_vector_permute = 1'b1;
                        end
                        6'h0F: begin // vfslide1down.vf
                            valu_op = 6'h0F;
                            is_vector_permute = 1'b1;
                        end
                        6'h10: valu_op = 6'h10; // vfmv.s.f
                        6'h17: begin // vfmerge.vfm
                            valu_op = 6'h17;
                        end
                        6'h18: valu_op = 6'h18; // vmfeq.vf
                        6'h19: valu_op = 6'h19; // vmfle.vf
                        6'h1B: valu_op = 6'h1B; // vmflt.vf
                        6'h1C: valu_op = 6'h1C; // vmfne.vf
                        6'h1D: valu_op = 6'h1D; // vmfgt.vf
                        6'h1F: valu_op = 6'h1F; // vmfge.vf
                        6'h20: valu_op = 6'h20; // vfdiv.vf
                        6'h21: valu_op = 6'h21; // vfrdiv.vf
                        6'h24: valu_op = 6'h24; // vfmul.vf
                        6'h27: valu_op = 6'h27; // vfrsub.vf
                        6'h28: valu_op = 6'h28; // vfmadd.vf
                        6'h29: valu_op = 6'h29; // vfnmadd.vf
                        6'h2A: valu_op = 6'h2A; // vfmsub.vf
                        6'h2B: valu_op = 6'h2B; // vfnmsub.vf
                        6'h2C: valu_op = 6'h2C; // vfmacc.vf
                        6'h2D: valu_op = 6'h2D; // vfnmacc.vf
                        6'h2E: valu_op = 6'h2E; // vfmsac.vf
                        6'h2F: valu_op = 6'h2F; // vfnmsac.vf
                        6'h30: begin // vfwadd.vf (widening)
                            valu_op = 6'h30;
                            is_widening = 1'b1;
                        end
                        6'h32: begin // vfwsub.vf (widening)
                            valu_op = 6'h32;
                            is_widening = 1'b1;
                        end
                        6'h34: begin // vfwadd.wf (widening)
                            valu_op = 6'h34;
                            is_widening = 1'b1;
                        end
                        6'h36: begin // vfwsub.wf (widening)
                            valu_op = 6'h36;
                            is_widening = 1'b1;
                        end
                        6'h38: begin // vfwmul.vf (widening)
                            valu_op = 6'h38;
                            is_widening = 1'b1;
                        end
                        6'h3C: begin // vfwmacc.vf (widening)
                            valu_op = 6'h3C;
                            is_widening = 1'b1;
                        end
                        6'h3D: begin // vfwnmacc.vf (widening)
                            valu_op = 6'h3D;
                            is_widening = 1'b1;
                        end
                        6'h3E: begin // vfwmsac.vf (widening)
                            valu_op = 6'h3E;
                            is_widening = 1'b1;
                        end
                        6'h3F: begin // vfwnmsac.vf (widening)
                            valu_op = 6'h3F;
                            is_widening = 1'b1;
                        end
                        default: valu_op = 6'h00;
                    endcase
                end
                
                3'b110: begin // OPMVX - Integer vector-scalar
                    case (funct6_field)
                        6'h08: begin // vaaddu.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h08;
                        end
                        6'h09: begin // vaadd.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h09;
                        end
                        6'h0A: begin // vasubu.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h0A;
                        end
                        6'h0B: begin // vasub.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h0B;
                        end
                        6'h0E: begin // vslide1up.vx
                            is_vector_permute = 1'b1;
                            valu_op = 6'h0E;
                        end
                        6'h0F: begin // vslide1down.vx
                            is_vector_permute = 1'b1;
                            valu_op = 6'h0F;
                        end
                        6'h10: begin // vwxunary0 (FP conversions, class, etc)
                            is_fp_op = 1'b1;
                            valu_op = {1'b0, vs2};
                        end
                        6'h11: begin // vrxunary0 (FP conversions)
                            is_fp_op = 1'b1;
                            valu_op = {1'b0, vs2};
                        end
                        6'h12: begin // vwfunary0 (FP sqrt, rsqrt, rcp, class)
                            is_fp_op = 1'b1;
                            valu_op = {1'b0, vs1};
                        end
                        6'h13: begin // vrfunary0 (FP conversions)
                            is_fp_op = 1'b1;
                            valu_op = {1'b0, vs1};
                        end
                        6'h14: begin // vwfunary1 (more FP unary ops)
                            is_fp_op = 1'b1;
                            valu_op = {1'b0, vs1};
                        end
                        6'h18: begin // vwfunary0 extension
                            is_fp_op = 1'b1;
                            valu_op = {1'b0, vs1};
                        end
                        6'h20: begin // vdivu.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h20;
                        end
                        6'h21: begin // vdiv.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h21;
                        end
                        6'h22: begin // vremu.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h22;
                        end
                        6'h23: begin // vrem.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h23;
                        end
                        6'h24: begin // vmulhu.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h24;
                        end
                        6'h25: begin // vmul.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h25;
                        end
                        6'h26: begin // vmulhsu.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h26;
                        end
                        6'h27: begin // vmulh.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h27;
                        end
                        6'h29: begin // vmadd.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h29;
                        end
                        6'h2B: begin // vnmsub.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h2B;
                        end
                        6'h2D: begin // vmacc.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h2D;
                        end
                        6'h2F: begin // vnmsac.vx
                            is_vector_arith = 1'b1;
                            valu_op = 6'h2F;
                        end
                        6'h30: begin // vwaddu.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h30;
                        end
                        6'h31: begin // vwadd.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h31;
                        end
                        6'h32: begin // vwsubu.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h32;
                        end
                        6'h33: begin // vwsub.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h33;
                        end
                        6'h34: begin // vwaddu.wx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h34;
                        end
                        6'h35: begin // vwadd.wx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h35;
                        end
                        6'h36: begin // vwsubu.wx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h36;
                        end
                        6'h37: begin // vwsub.wx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h37;
                        end
                        6'h38: begin // vwmulu.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h38;
                        end
                        6'h3A: begin // vwmulsu.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3A;
                        end
                        6'h3B: begin // vwmul.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3B;
                        end
                        6'h3C: begin // vwmaccu.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3C;
                        end
                        6'h3D: begin // vwmacc.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3D;
                        end
                        6'h3E: begin // vwmaccus.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3E;
                        end
                        6'h3F: begin // vwmaccsu.vx (widening)
                            is_vector_arith = 1'b1;
                            is_widening = 1'b1;
                            valu_op = 6'h3F;
                        end
                        default: valu_op = 6'h00;
                    endcase
                end
                
                //--------------------------------------------------------------
                // Vector Configuration and Load/Store
                //--------------------------------------------------------------
                3'b111: begin // OPCFG - vsetvli/vsetivli/vsetvl
                    if (inst[31] == 1'b0 && inst[30] == 1'b0) begin // vsetvli
                        is_vector_config = 1'b1;
                    end else if (inst[31] == 1'b1 && inst[30] == 1'b1) begin // vsetivli
                        is_vector_config = 1'b1;
                    end else if (inst[31] == 1'b1 && inst[30] == 1'b0) begin // vsetvl
                        is_vector_config = 1'b1;
                    end
                end
                
                default: begin
                    // Check for vector loads/stores (LOAD-FP/STORE-FP encoding)
                    // These use different opcodes but with mop, nf, vm fields
                    is_vector_inst = 1'b0;
                end
            endcase
        end else if (valid && (opcode == 7'b0000111 || opcode == 7'b0100111)) begin
            // Vector loads (LOAD-FP opcode) and stores (STORE-FP opcode)
            is_vector_inst = 1'b1;
            mop = inst[27:26];
            nf = inst[31:29];
            vm = inst[25];
            
            // Decode addressing mode
            unit_stride = (mop == 2'b00);
            strided = (mop == 2'b10);
            indexed = (mop == 2'b01 || mop == 2'b11);
            
            // Check for segment loads/stores (nf != 0)
            segment = (nf != 3'b000);
            
            // Check for whole register loads/stores (nf == 0 && lumop/sumop special)
            if (opcode == 7'b0000111) begin // Loads
                is_vector_load = 1'b1;
                lumop = inst[24:20];
                whole_reg = (nf == 3'b000 && mop == 2'b00 && lumop[4:3] == 2'b01);
                fault_only_first = (nf == 3'b000 && mop == 2'b00 && lumop == 5'b10000);
            end else begin // Stores
                is_vector_store = 1'b1;
                sumop = inst[24:20];
                whole_reg = (nf == 3'b000 && mop == 2'b00 && sumop[4:3] == 2'b01);
            end
        end
    end

endmodule
