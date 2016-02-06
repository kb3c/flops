## dep/makefile
## dependency makefile for flopsss
##
## Copyright (c) 2016, Geoff Hadler, kb3c

# for now, we hide the clean target
# make the clone unnecessary if we've stashed
# simplify libs copying

LIBGHVER= 1.1.3.1
LIBGHPCVER= 0.1

all: pre_all dep_libgh dep_libghpc

pre_all:
	@echo "  = VERIFY EXIST PATH(s)"
	@mkdir -p ../lib/
	@mkdir -p ../gh/


dep_libgh:
	-git clone https://github.com/kb3c/libgh
	make -C libgh/ prepare
	cp -f libgh/$(LIBGHVER)/*.a ../lib/
	cp -f libgh/$(LIBGHVER)/gh.h* ../gh/
	
dep_libghpc:
	-git clone https://github.com/kb3c/libghpc
	make -C libghpc/ prepare
	cp -f libghpc/$(LIBGHPCVER)/*.a ../lib/
	cp -f libghpc/$(LIBGHPCVER)/ghpc.h* ../gh/
	
#CAREFUL!
#clean:
#	@rm -frv libgh/
#	@rm -frv libghpc/
