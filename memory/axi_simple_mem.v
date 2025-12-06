`include "../common/config.vh"
`include "../common/defines.vh"

module axi_simple_mem (
    input  wire                     clk,
    input  wire                     rst_n,

    // AXI4 slave interface (connected to axi4_master)
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
    input  wire                       rready
);

    // Simple byte-addressable memory using a behavioral array
    localparam MEM_WORDS = 1024;
    reg [`AXI_DATA_WIDTH-1:0] mem [0:MEM_WORDS-1];

    // Initialize memory with NOPs for instructions (0x00000013 in lower 32 bits)
    integer i;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < MEM_WORDS; i = i + 1) begin
                mem[i] <= {(`AXI_DATA_WIDTH-32){1'b0}} | 32'h00000013;
            end
            awready <= 1'b0;
            wready <= 1'b0;
            bresp <= `AXI_RESP_OKAY;
            bvalid <= 1'b0;
            arready <= 1'b0;
            rdata <= {`AXI_DATA_WIDTH{1'b0}};
            rresp <= `AXI_RESP_OKAY;
            rlast <= 1'b1;
            rvalid <= 1'b0;
        end else begin
            // Write address handshake
            if (awvalid && !awready) begin
                awready <= 1'b1;
            end else begin
                awready <= 1'b0;
            end

            // Write data handshake
            if (wvalid && !wready) begin
                wready <= 1'b1;
            end else if (wvalid && wready) begin
                // write to memory (assume single beat and 512-bit lanes)
                mem[awaddr[11:4]] <= wdata;
                wready <= 1'b0;
                bvalid <= 1'b1;
                bresp <= `AXI_RESP_OKAY;
            end else begin
                wready <= 1'b0;
            end

            if (bready && bvalid) begin
                bvalid <= 1'b0;
            end

            // Read address handshake
            if (arvalid && !arready) begin
                arready <= 1'b1;
            end else if (arvalid && arready) begin
                // provide read data
                rdata <= mem[araddr[11:4]];
                rresp <= `AXI_RESP_OKAY;
                rlast <= 1'b1;
                rvalid <= 1'b1;
                arready <= 1'b0;
            end else begin
                if (rvalid && rready) begin
                    rvalid <= 1'b0;
                end
            end
        end
    end

endmodule
