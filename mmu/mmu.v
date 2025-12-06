//==============================================================================
// Memory Management Unit (MMU)
// Single-stage address translation with TLB
//==============================================================================

`include "../common/config.vh"
`include "../common/defines.vh"

module mmu (
    input wire clk,
    input wire rst_n,
    
    // Translation request
    input wire [`VADDR_WIDTH-1:0]  vaddr,
    output reg [`PADDR_WIDTH-1:0]  paddr,
    input wire                     req,
    input wire                     wen,
    output reg                     ready,
    output reg                     fault,
    
    // Page table walker memory interface
    output reg [31:0]              ptw_mem_addr,
    output reg                     ptw_mem_valid,
    input wire [31:0]              ptw_mem_rdata,
    input wire                     ptw_mem_ready
);

    // TLB storage
    reg [`VADDR_WIDTH-`PAGE_OFFSET_BITS-1:0] tlb_vpn [`TLB_ENTRIES-1:0];
    reg [`PADDR_WIDTH-`PAGE_OFFSET_BITS-1:0] tlb_ppn [`TLB_ENTRIES-1:0];
    reg [7:0]                                  tlb_flags [`TLB_ENTRIES-1:0];
    reg                                        tlb_valid [`TLB_ENTRIES-1:0];
    reg [`TLB_INDEX_BITS-1:0]                 tlb_lru [`TLB_ENTRIES-1:0];
    
    // Current request VPN and offset
    wire [`VADDR_WIDTH-`PAGE_OFFSET_BITS-1:0] req_vpn = vaddr[`VADDR_WIDTH-1:`PAGE_OFFSET_BITS];
    wire [`PAGE_OFFSET_BITS-1:0]               req_offset = vaddr[`PAGE_OFFSET_BITS-1:0];
    
    // TLB lookup
    reg                     tlb_hit;
    reg [`TLB_INDEX_BITS-1:0] tlb_hit_idx;
    reg [`PADDR_WIDTH-`PAGE_OFFSET_BITS-1:0] tlb_hit_ppn;
    reg [7:0]               tlb_hit_flags;
    
    integer i, j;
    
    // State machine
    reg [2:0] state;
    
    // TLB lookup logic
    always @(*) begin
        tlb_hit = 1'b0;
        tlb_hit_idx = {`TLB_INDEX_BITS{1'b0}};
        tlb_hit_ppn = {(`PADDR_WIDTH-`PAGE_OFFSET_BITS){1'b0}};
        tlb_hit_flags = 8'b0;
        
        for (i = 0; i < `TLB_ENTRIES; i = i + 1) begin
            if (tlb_valid[i] && (tlb_vpn[i] == req_vpn)) begin
                tlb_hit = 1'b1;
                tlb_hit_idx = i;
                tlb_hit_ppn = tlb_ppn[i];
                tlb_hit_flags = tlb_flags[i];
            end
        end
    end
    
    // State machine
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= `MMU_IDLE;
            paddr <= {`PADDR_WIDTH{1'b0}};
            ready <= 1'b0;
            fault <= 1'b0;
            ptw_mem_valid <= 1'b0;
            
            for (i = 0; i < `TLB_ENTRIES; i = i + 1) begin
                tlb_valid[i] <= 1'b0;
                tlb_lru[i] <= i;
            end
        end else begin
            case (state)
                `MMU_IDLE: begin
                    ready <= 1'b0;
                    fault <= 1'b0;
                    if (req) begin
                        state <= `MMU_TLB_LOOKUP;
                    end
                end
                
                `MMU_TLB_LOOKUP: begin
                    if (tlb_hit) begin
                        // Check permissions
                        if ((wen && !tlb_hit_flags[`PTE_W]) || 
                            (!wen && !tlb_hit_flags[`PTE_R])) begin
                            fault <= 1'b1;
                            state <= `MMU_FAULT;
                        end else begin
                            paddr <= {tlb_hit_ppn, req_offset};
                            ready <= 1'b1;
                            state <= `MMU_IDLE;
                            
                            // Update LRU
                            for (j = 0; j < `TLB_ENTRIES; j = j + 1) begin
                                if (j == tlb_hit_idx) begin
                                    tlb_lru[j] <= `TLB_ENTRIES - 1;
                                end else if (tlb_lru[j] > tlb_lru[tlb_hit_idx]) begin
                                    tlb_lru[j] <= tlb_lru[j] - 1;
                                end
                            end
                        end
                    end else begin
                        // TLB miss - for now, just pass through (identity mapping)
                        paddr <= vaddr;
                        ready <= 1'b1;
                        state <= `MMU_IDLE;
                    end
                end
                
                `MMU_FAULT: begin
                    ready <= 1'b1;
                    state <= `MMU_IDLE;
                end
                
                default: state <= `MMU_IDLE;
            endcase
        end
    end

endmodule
