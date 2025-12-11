`include "../common/config.vh"
`include "../common/defines.vh"

module axi_simple_mem (
    input  wire                     clk,
    input  wire                     rst_n,

    input  wire [`AXI_ADDR_WIDTH-1:0] awaddr,
    input  wire [7:0]                 awlen,
    input  wire [2:0]                 awsize,
    input  wire [1:0]                 awburst,
    input  wire                       awvalid,
    output reg                        awready,

    input  wire [`AXI_DATA_WIDTH-1:0] wdata,
    input  wire [`AXI_DATA_WIDTH/8-1:0] wstrb,
    input  wire                       wlast,
    input  wire                       wvalid,
    output reg                        wready,

    output reg [1:0]                  bresp,
    output reg                         bvalid,
    input  wire                        bready,

    input  wire [`AXI_ADDR_WIDTH-1:0] araddr,
    input  wire [7:0]                 arlen,
    input  wire [2:0]                 arsize,
    input  wire [1:0]                 arburst,
    input  wire                       arvalid,
    output reg                        arready,

    output reg [`AXI_DATA_WIDTH-1:0]  rdata,
    output reg [1:0]                  rresp,
    output reg                        rlast,
    output reg                        rvalid,
    input  wire                       rready,

    output reg                        test_pass
);

    localparam MEM_WORDS = 1024;
    reg [`AXI_DATA_WIDTH-1:0] mem [0:MEM_WORDS-1];

    localparam integer PASS_ADDR = 64;
    localparam integer PASS_IDX  = (PASS_ADDR >> 6);
    localparam integer PASS_SUB  = (PASS_ADDR >> 2) & 4'hF;
    localparam [31:0]   PASS_VAL = 32'h00000001;

    reg [`AXI_ADDR_WIDTH-1:0] write_addr;
    reg [1:0] wstate;
    localparam WS_IDLE = 2'd0;
    localparam WS_ADDR = 2'd1;
    localparam WS_DATA = 2'd2;
    localparam WS_RESP = 2'd3;

    integer i, j;
    reg [31:0] piece;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < MEM_WORDS; i = i + 1) begin
                mem[i] <= {(`AXI_DATA_WIDTH){1'b0}};
                for (j = 0; j < (`AXI_DATA_WIDTH/32); j = j + 1) begin
                    mem[i][(j*32) +: 32] <= 32'h00000013;
                end
            end

            mem[0][ 0*32 +: 32] <= 32'h04000093;
            mem[0][ 1*32 +: 32] <= 32'h00100113;
            mem[0][ 2*32 +: 32] <= 32'h0020A023;
            mem[0][ 3*32 +: 32] <= 32'h0000006F;

            awready <= 1'b0;
            wready <= 1'b0;
            bresp <= `AXI_RESP_OKAY;
            bvalid <= 1'b0;
            arready <= 1'b0;
            rdata <= {`AXI_DATA_WIDTH{1'b0}};
            rresp <= `AXI_RESP_OKAY;
            rlast <= 1'b1;
            rvalid <= 1'b0;

            test_pass <= 1'b0;
            wstate <= WS_IDLE;
            write_addr <= 32'b0;
        end else begin
            case (wstate)
                WS_IDLE: begin
                    awready <= 1'b1;
                    wready <= 1'b0;
                    bvalid <= 1'b0;
                    if (awvalid && awready) begin
                        write_addr <= awaddr;
                        awready <= 1'b0;
                        wstate <= WS_DATA;
                    end
                end
                
                WS_DATA: begin
                    wready <= 1'b1;
                    if (wvalid && wready) begin
                        integer idx;
                        integer sub;
                        idx = write_addr[11:6];
                        sub = write_addr[5:2];

                        if (wstrb == {(`AXI_DATA_WIDTH/8){1'b1}}) begin
                            mem[idx] <= wdata;
                        end else begin
                            mem[idx][(sub*32) +: 32] <= wdata[31:0];
                        end

                        if (idx == PASS_IDX) begin
                            if (wdata[31:0] == PASS_VAL && sub == PASS_SUB) begin
                                test_pass <= 1'b1;
                            end
                        end

                        wready <= 1'b0;
                        wstate <= WS_RESP;
                    end
                end
                
                WS_RESP: begin
                    bvalid <= 1'b1;
                    bresp <= `AXI_RESP_OKAY;
                    if (bready && bvalid) begin
                        bvalid <= 1'b0;
                        wstate <= WS_IDLE;
                    end
                end
                
                default: wstate <= WS_IDLE;
            endcase

            if (arvalid && !arready && !rvalid) begin
                arready <= 1'b1;
            end else if (arvalid && arready) begin
                integer idx_r;
                integer sub_r;
                idx_r = araddr[11:6];
                sub_r = araddr[5:2];

                piece = mem[idx_r][(sub_r*32) +: 32];
                rdata <= {{(`AXI_DATA_WIDTH-32){1'b0}}, piece};
                rresp <= `AXI_RESP_OKAY;
                rlast <= 1'b1;
                rvalid <= 1'b1;
                arready <= 1'b0;
            end else begin
                arready <= 1'b0;
                if (rvalid && rready) begin
                    rvalid <= 1'b0;
                end
            end
        end
    end

endmodule
