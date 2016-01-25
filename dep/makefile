## dependency makefile for flopsss


all: pre_all dep_libgh dep_libghpc

pre_all:
	@mkdir -p ../lib/
	@mkdir -p ../gh/


dep_libgh:
	@git clone https://github.com/kb3c/libgh
	@make -C libgh/ prepare
	@cp -f libgh/1.1/*.a ../lib/
	@cp -f libgh/gh.h ../gh/
	@cp -f libgh/gh.hpp ../gh/
	
dep_libghpc:
	@git clone https://github.com/kb3c/libghpc
	@make -C libghpc/ prepare
	@cp -f libghpc/0.1/*.a ../lib/
	@cp -f libghpc/ghpc.h ../gh/
	@cp -f libghpc/ghpc.hpp ../gh/

	
#CAREFUL!
clean:
	@rm -frv libgh/
	@rm -frv libghpc/