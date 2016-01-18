## flopsss makefile
# 2010-2016, polarysekt

all: flops_bin
	@echo -n "    "	
	@cp -fv ../flops ../../bin/

all_debug: flops_debug
	@echo -n "    "	
	@cp -fv ../flopsdbg ../../bin/

all_debug_deep: flops_debug_deep
	@echo -n "    "	
	@cp -fv ../flopsdbg_deep ../../bin/

all_debug_deep_verbose: flops_debug_deep_verbose
	@echo -n "    "
	@cp -fv ../flopsdbg_deep_v ../../bin/

#deep: libgh_rebuild libghpoker_rebuild

flops_bin:
	@echo -n "    "
	g++ -DNDEBUG -O2 -o ../flops flops.cpp  -lX11 lib/libgh.a
	
flops_debug:
	@echo -n "    "
	g++ -Wall -g -o ../flopsdbg flops.cpp lib/libgh.a -lX11
	
flops_debug_deep:
	@echo -n "    "
	g++ -Wall -g -o ../flopsdbg_deep flops.cpp lib/libgh_debug.a -lX11
	
flops_debug_deep_verbose:
	@echo -n "    "
	g++ -Wall -g -o ../flopsdbg_deep_v flops.cpp lib/libgh_debug_v.a -lX11	