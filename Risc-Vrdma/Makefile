VERILATOR = verilator
VERILATOR_FLAGS = --cc --trace --exe -Irtl -Irtl/common --Mdir obj_dir -Wno-fatal -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC

RTL_SRCS = rtl/soc_top.v \
           rtl/scalar/scalar_core.v \
           rtl/axi/axi4_master.v \
           rtl/axi/axi_simple_mem.v \
           rtl/rdma/rdma_engine.v

TB_SRC = tb/verilator_tb.cpp

TOP = soc_top

.PHONY: all clean run

all: obj_dir/V$(TOP)

obj_dir/V$(TOP): $(RTL_SRCS) $(TB_SRC)
	$(VERILATOR) $(VERILATOR_FLAGS) --top-module $(TOP) $(RTL_SRCS) $(TB_SRC) -o V$(TOP)
	$(MAKE) -C obj_dir -f V$(TOP).mk V$(TOP)

run: obj_dir/V$(TOP)
	./obj_dir/V$(TOP)

clean:
	rm -rf obj_dir verilator.vcd
