//==============================================================================
// AXI4 Master Interface
// Arbitrates between scalar and vector memory requests
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module axi4_master (
    input wire clk,
    input wire rst_n,
    
    // Scalar memory requests
    input wire [31:0]  scalar_addr,
    input wire [31:0]  scalar_wdata,
    input wire [3:0]   scalar_wstrb,
    input wire         scalar_valid,
    input wire         scalar_wen,
    output reg [31:0]  scalar_rdata,
    output reg         scalar_ready,
    
    // Vector memory requests
    input wire [31:0]        vector_addr,
    input wire [`VLEN-1:0]   vector_wdata,
    input wire [`VLEN/8-1:0] vector_wstrb,
    input wire               vector_valid,
    input wire               vector_wen,
    output reg [`VLEN-1:0]   vector_rdata,
    output reg               vector_ready,
    
    // AXI4 Write Address Channel
    output reg [`AXI_ADDR_WIDTH-1:0] axi_awaddr,
    output reg [7:0]                  axi_awlen,
    output reg [2:0]                  axi_awsize,
    output reg [1:0]                  axi_awburst,
    output reg                        axi_awvalid,
    input  wire                       axi_awready,
    
    // AXI4 Write Data Channel
    output reg [`AXI_DATA_WIDTH-1:0]      axi_wdata,
    output reg [`AXI_DATA_WIDTH/8-1:0]    axi_wstrb,
    output reg                             axi_wlast,
    output reg                             axi_wvalid,
    input  wire                            axi_wready,
    
    // AXI4 Write Response Channel
    input  wire [1:0]                 axi_bresp,
    input  wire                       axi_bvalid,
    output reg                        axi_bready,
    
    // AXI4 Read Address Channel
    output reg [`AXI_ADDR_WIDTH-1:0] axi_araddr,
    output reg [7:0]                  axi_arlen,
    output reg [2:0]                  axi_arsize,
    output reg [1:0]                  axi_arburst,
    output reg                        axi_arvalid,
    input  wire                       axi_arready,
    
    // AXI4 Read Data Channel
    input  wire [`AXI_DATA_WIDTH-1:0] axi_rdata,
    input  wire [1:0]                  axi_rresp,
    input  wire                        axi_rlast,
    input  wire                        axi_rvalid,
    output reg                         axi_rready
);

    // State machine
    reg [3:0] state;
    localparam IDLE = 4'b0000;
    localparam SCALAR_READ_ADDR = 4'b0001;
    localparam SCALAR_READ_DATA = 4'b0010;
    localparam SCALAR_WRITE_ADDR = 4'b0011;
    localparam SCALAR_WRITE_DATA = 4'b0100;
    localparam SCALAR_WRITE_RESP = 4'b0101;
    localparam VECTOR_READ_ADDR = 4'b0110;
    localparam VECTOR_READ_DATA = 4'b0111;
    localparam VECTOR_WRITE_ADDR = 4'b1000;
    localparam VECTOR_WRITE_DATA = 4'b1001;
    localparam VECTOR_WRITE_RESP = 4'b1010;
    
    // Burst counter for multi-beat transactions
    reg [7:0] burst_count;
    reg [7:0] burst_len;
    
    // Arbitration: vector has priority
    wire service_vector = vector_valid;
    wire service_scalar = scalar_valid && !vector_valid;
    
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            scalar_ready <= 1'b0;
            vector_ready <= 1'b0;
            axi_awvalid <= 1'b0;
            axi_wvalid <= 1'b0;
            axi_bready <= 1'b1;
            axi_arvalid <= 1'b0;
            axi_rready <= 1'b1;
            burst_count <= 8'b0;
            burst_len <= 8'b0;
        end else begin
            case (state)
                IDLE: begin
                    scalar_ready <= 1'b0;
                    vector_ready <= 1'b0;
                    burst_count <= 8'b0;
                    axi_awvalid <= 1'b0;
                    axi_wvalid <= 1'b0;
                    axi_arvalid <= 1'b0;
                    
                    if (service_vector) begin
                        if (vector_wen) begin
                            state <= VECTOR_WRITE_ADDR;
                            burst_len <= 8'b0; // Single beat for now
                        end else begin
                            state <= VECTOR_READ_ADDR;
                            burst_len <= 8'b0;
                        end
                    end else if (service_scalar) begin
                        if (scalar_wen) begin
                            state <= SCALAR_WRITE_ADDR;
                            burst_len <= 8'b0;
                        end else begin
                            state <= SCALAR_READ_ADDR;
                            burst_len <= 8'b0;
                        end
                    end
                end
                
                // ===== Scalar Read Transaction =====
                SCALAR_READ_ADDR: begin
                    axi_araddr <= scalar_addr;
                    axi_arlen <= burst_len;
                    axi_arsize <= 3'b010; // 4 bytes (32-bit)
                    axi_arburst <= `AXI_BURST_INCR;
                    axi_arvalid <= 1'b1;
                    
                    if (axi_arready && axi_arvalid) begin
                        axi_arvalid <= 1'b0;
                        state <= SCALAR_READ_DATA;
                    end
                end
                
                SCALAR_READ_DATA: begin
                    axi_rready <= 1'b1;
                    
                    if (axi_rvalid && axi_rready) begin
                        scalar_rdata <= axi_rdata[31:0];
                        
                        if (axi_rlast) begin
                            scalar_ready <= 1'b1;
                            state <= IDLE;
                        end else begin
                            burst_count <= burst_count + 1;
                        end
                    end
                end
                
                // ===== Scalar Write Transaction =====
                SCALAR_WRITE_ADDR: begin
                    axi_awaddr <= scalar_addr;
                    axi_awlen <= burst_len;
                    axi_awsize <= 3'b010; // 4 bytes
                    axi_awburst <= `AXI_BURST_INCR;
                    axi_awvalid <= 1'b1;
                    
                    if (axi_awready && axi_awvalid) begin
                        axi_awvalid <= 1'b0;
                        state <= SCALAR_WRITE_DATA;
                    end
                end
                
                SCALAR_WRITE_DATA: begin
                    axi_wdata <= {{(`AXI_DATA_WIDTH-32){1'b0}}, scalar_wdata};
                    axi_wstrb <= {{(`AXI_DATA_WIDTH/8-4){1'b0}}, scalar_wstrb};
                    axi_wlast <= (burst_count == burst_len);
                    axi_wvalid <= 1'b1;
                    
                    if (axi_wready && axi_wvalid) begin
                        if (axi_wlast) begin
                            axi_wvalid <= 1'b0;
                            state <= SCALAR_WRITE_RESP;
                        end else begin
                            burst_count <= burst_count + 1;
                        end
                    end
                end
                
                SCALAR_WRITE_RESP: begin
                    axi_bready <= 1'b1;
                    
                    if (axi_bvalid && axi_bready) begin
                        // Check response code
                        if (axi_bresp == `AXI_RESP_OKAY || axi_bresp == `AXI_RESP_EXOKAY) begin
                            scalar_ready <= 1'b1;
                        end
                        state <= IDLE;
                    end
                end
                
                // ===== Vector Read Transaction =====
                VECTOR_READ_ADDR: begin
                    axi_araddr <= vector_addr;
                    axi_arlen <= burst_len;
                    axi_arsize <= 3'b110; // 64 bytes (512-bit)
                    axi_arburst <= `AXI_BURST_INCR;
                    axi_arvalid <= 1'b1;
                    
                    if (axi_arready && axi_arvalid) begin
                        axi_arvalid <= 1'b0;
                        state <= VECTOR_READ_DATA;
                    end
                end
                
                VECTOR_READ_DATA: begin
                    axi_rready <= 1'b1;
                    
                    if (axi_rvalid && axi_rready) begin
                        vector_rdata <= axi_rdata;
                        
                        if (axi_rlast) begin
                            vector_ready <= 1'b1;
                            state <= IDLE;
                        end else begin
                            burst_count <= burst_count + 1;
                        end
                    end
                end
                
                // ===== Vector Write Transaction =====
                VECTOR_WRITE_ADDR: begin
                    axi_awaddr <= vector_addr;
                    axi_awlen <= burst_len;
                    axi_awsize <= 3'b110; // 64 bytes (512-bit)
                    axi_awburst <= `AXI_BURST_INCR;
                    axi_awvalid <= 1'b1;
                    
                    if (axi_awready && axi_awvalid) begin
                        axi_awvalid <= 1'b0;
                        state <= VECTOR_WRITE_DATA;
                    end
                end
                
                VECTOR_WRITE_DATA: begin
                    axi_wdata <= vector_wdata;
                    axi_wstrb <= vector_wstrb;
                    axi_wlast <= (burst_count == burst_len);
                    axi_wvalid <= 1'b1;
                    
                    if (axi_wready && axi_wvalid) begin
                        if (axi_wlast) begin
                            axi_wvalid <= 1'b0;
                            state <= VECTOR_WRITE_RESP;
                        end else begin
                            burst_count <= burst_count + 1;
                        end
                    end
                end
                
                VECTOR_WRITE_RESP: begin
                    axi_bready <= 1'b1;
                    
                    if (axi_bvalid && axi_bready) begin
                        // Check response code
                        if (axi_bresp == `AXI_RESP_OKAY || axi_bresp == `AXI_RESP_EXOKAY) begin
                            vector_ready <= 1'b1;
                        end
                        state <= IDLE;
                    end
                end
                
                default: state <= IDLE;
            endcase
        end
    end

endmodule
