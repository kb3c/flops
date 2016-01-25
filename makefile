## flopsss makefile
# 2010-2016, polarysekt


#FLOPSSSARCH=armhf
#FLOPSSSPLAT=x
PLATFORMEXT= .out
#PLATFORMEXT= .exe

PLATFORMLIBS= lib/libgh-armhf-x.a lib/libghpc-armhf-x.a -lX11
#PLATFORMDLIBS=
#PLATFORMVLIBS=
FLAGREL= -DNDEBUG -O2
FLAGDBG= -Wall -g

all: flops_bin
#	@echo -n "    "	
#	@cp -fv ../flops ../../bin/

all_debug: flops_debug
#	@echo -n "    "	
#	@cp -fv ../flopsdbg ../../bin/

all_debug_deep: flops_debug_deep
#	@echo -n "    "	
#	@cp -fv ../flopsdbg_deep ../../bin/

all_debug_deep_verbose: flops_debug_deep_verbose
#	@echo -n "    "
#	@cp -fv ../flopsdbg_deep_v ../../bin/


getdep:
	@make -C dep/


flops_bin:
	@echo -n "    "
	g++ $(FLAGREL) -o flops$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)
	
flops_debug:
	@echo -n "    "
	g++ $(FLAGDBG) -o flopsdbg$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)

#TODO
flops_debug_deep:
	@echo -n "    "
	g++ $(FLAGDBG) -o flopsdbg_deep$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)

#TODO
flops_debug_deep_verbose:
	@echo -n "    "
	g++ $(FLAGDBG) -o flopsdbg_deep_v$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)
	
cleandep:
	@make -C dep/ clean
	