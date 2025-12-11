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
    input  wire                       rready,

    // Test signal: asserted when the pass marker value is written
    output reg                        test_pass
);

    // Simple byte-addressable memory using a behavioral array
    localparam MEM_WORDS = 1024;
    reg [`AXI_DATA_WIDTH-1:0] mem [0:MEM_WORDS-1];

    // Pass marker address and value
    localparam integer PASS_ADDR = 64;               // byte address where program writes marker
    localparam integer PASS_IDX  = (PASS_ADDR >> 4); // same index mapping as used below
    localparam integer PASS_SUB  = (PASS_ADDR >> 2) & 3;
    localparam [31:0]   PASS_VAL = 32'h00000001;

    integer i, j;
    reg [31:0] piece;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Initialize memory with NOP instructions (0x00000013) in all 32-bit slots
            for (i = 0; i < MEM_WORDS; i = i + 1) begin
                mem[i] <= {(`AXI_DATA_WIDTH){1'b0}};
                for (j = 0; j < (`AXI_DATA_WIDTH/32); j = j + 1) begin
                    mem[i][(j*32) +: 32] <= 32'h00000013; // NOP
                end
            end

            // Inject a tiny boot program into mem[0] (first 64 bytes)
            // Instruction encodings (RV32I):
            // ADDI x1, x0, 64   -> 0x04000093
            // ADDI x2, x0, 1    -> 0x00100113
            // SW   x2, 0(x1)    -> 0x0020A023
            // JAL  x0, 0        -> 0x0000006F (loop)
            mem[0][ 0*32 +: 32] <= 32'h04000093; // PC=0
            mem[0][ 1*32 +: 32] <= 32'h00100113; // PC=4
            mem[0][ 2*32 +: 32] <= 32'h0020A023; // PC=8
            mem[0][ 3*32 +: 32] <= 32'h0000006F; // PC=12
            // remaining slots already set to NOP

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
        end else begin
            // Write address handshake
            if (awvalid && !awready) begin
                awready <= 1'b1;
            end else begin
                awready <= 1'b0;
            end

            // Write data handshake and store logic
            if (wvalid && !wready) begin
                wready <= 1'b1;
            end else if (wvalid && wready) begin
                // Determine index and 32-bit subword offset inside the stored wide word.
                // This uses the same index mapping used in the original model (araddr[11:4])
                // and selects 32-bit slot using bits [4:2].
                integer idx;
                integer sub;
                idx = awaddr[11:4];
                sub = awaddr[4:2];

                // If the write covers the whole wide word (all byte lanes), write whole element
                if (wstrb == {(`AXI_DATA_WIDTH/8){1'b1}}) begin
                    mem[idx] <= wdata;
                end else begin
                    // Store only the 32-bit lane (lowest 32 bits of wdata) into the targeted slot
                    mem[idx][(sub*32) +: 32] <= wdata[31:0];
                end

                // Check pass marker after write
                if (idx == PASS_IDX) begin
                    if (mem[idx][(PASS_SUB*32) +: 32] == PASS_VAL) begin
                        test_pass <= 1'b1;
                    end
                end

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
                integer idx_r;
                integer sub_r;
                idx_r = araddr[11:4];
                sub_r = araddr[4:2];

                // Provide read data: extract the requested 32-bit subword and place it in lower bits
                piece = mem[idx_r][(sub_r*32) +: 32];
                rdata <= {{(`AXI_DATA_WIDTH-32){1'b0}}, piece};
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
