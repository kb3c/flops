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

all: flops$(PLATFORMEXT)


all_debug: flops.d$(PLATFORMEXT)


all_debug_deep: flops.dd$(PLATFORMEXT)


all_debug_deep_verbose: flops.ddv$(PLATFORMEXT)


getdep:
	@make -C dep/


flops$(PLATFORMEXT):
	@echo -n "    "
	g++ $(FLAGREL) -o flops$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)
	
flops.d$(PLATFORMEXT):
	@echo -n "    "
	g++ $(FLAGDBG) -o flops.d$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)

#TODO
flops.dd$(PLATFORMEXT):
	@echo -n "    "
	g++ $(FLAGDBG) -o flops.dd$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)

#TODO
flops.ddv$(PLATFORMEXT):
	@echo -n "    "
	g++ $(FLAGDBG) -o flops.ddv$(PLATFORMEXT) flops.cpp $(PLATFORMLIBS)
	
cleandep:
	@make -C dep/ clean
	