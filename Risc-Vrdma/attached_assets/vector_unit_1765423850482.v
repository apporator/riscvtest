//==============================================================================
// Vector Unit - Integrates vector register file, ALU, and LSU
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module vector_unit (
    input wire clk,
    input wire rst_n,
    
    // Configuration from scalar
    input wire [31:0] vl_in,
    input wire        vl_we,
    input wire [31:0] vtype_in,
    input wire        vtype_we,
    
    // Memory interface
    output reg [31:0]        mem_addr,
    output reg [`VLEN-1:0]   mem_wdata,
    output reg [`VLEN/8-1:0] mem_wstrb,
    output reg               mem_valid,
    output reg               mem_wen,
    input  wire [`VLEN-1:0]  mem_rdata,
    input  wire              mem_ready
);

    // Vector CSRs
    reg [31:0] vl;
    reg [31:0] vtype;
    reg [31:0] vstart;
    
    // Extract vtype fields
    wire [2:0] vsew = vtype[5:3];
    wire [2:0] vlmul = vtype[2:0];
    wire       vta = vtype[6];
    wire       vma = vtype[7];
    
    // Vector register file ports
    wire [4:0]             vrf_ra_addr;
    wire [`VLEN-1:0]       vrf_ra_data;
    wire [4:0]             vrf_rb_addr;
    wire [`VLEN-1:0]       vrf_rb_data;
    wire [4:0]             vrf_rc_addr;
    wire [`VLEN-1:0]       vrf_rc_data;
    wire [4:0]             vrf_w_addr;
    wire [`VLEN-1:0]       vrf_w_data;
    wire                   vrf_w_en;
    
    wire [2:0]             mask_addr;
    wire [`VLEN/8-1:0]     mask_data;
    
    // ALU ports
    wire [`VLEN-1:0]       alu_op_a;
    wire [`VLEN-1:0]       alu_op_b;
    wire [`VLEN-1:0]       alu_op_c;
    wire [5:0]             alu_op;
    wire                   alu_valid;
    wire [`VLEN-1:0]       alu_result;
    
    // CSR update
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            vl <= 32'b0;
            vtype <= 32'b0;
            vstart <= 32'b0;
        end else begin
            if (vl_we) vl <= vl_in;
            if (vtype_we) vtype <= vtype_in;
        end
    end
    
    // Instantiate vector register file
    vector_regfile u_regfile (
        .clk(clk),
        .rst_n(rst_n),
        .ra_addr(vrf_ra_addr),
        .ra_data(vrf_ra_data),
        .rb_addr(vrf_rb_addr),
        .rb_data(vrf_rb_data),
        .rc_addr(vrf_rc_addr),
        .rc_data(vrf_rc_data),
        .w_addr(vrf_w_addr),
        .w_data(vrf_w_data),
        .w_en(vrf_w_en),
        .mask_addr(mask_addr),
        .mask_data(mask_data),
        .mask_w_addr(3'b0),
        .mask_w_data(64'b0),
        .mask_w_en(1'b0)
    );
    
    // Instantiate vector ALU
    vector_alu u_alu (
        .clk(clk),
        .rst_n(rst_n),
        .op_a(alu_op_a),
        .op_b(alu_op_b),
        .op_c(alu_op_c),
        .alu_op(alu_op),
        .sew(vsew),
        .vl(vl),
        .mask(mask_data),
        .mask_en(1'b0),
        .result(alu_result),
        .valid(alu_valid)
    );
    
    // Simple connections for basic operation
    assign vrf_ra_addr = 5'b0;
    assign vrf_rb_addr = 5'b0;
    assign vrf_rc_addr = 5'b0;
    assign vrf_w_addr = 5'b0;
    assign vrf_w_data = alu_result;
    assign vrf_w_en = alu_valid;
    assign mask_addr = 3'b0;
    assign alu_op_a = vrf_ra_data;
    assign alu_op_b = vrf_rb_data;
    assign alu_op_c = vrf_rc_data;
    assign alu_op = `VALU_OP_ADD;
    
    // Memory interface (placeholder)
    always @(*) begin
        mem_addr = 32'b0;
        mem_wdata = {`VLEN{1'b0}};
        mem_wstrb = {(`VLEN/8){1'b0}};
        mem_valid = 1'b0;
        mem_wen = 1'b0;
    end

endmodule
