#include <iostream>
#include "flops.hpp"

const char g_appname[] = "FLOPSSS";

int main( int argc, char** argv ) {
  flopsApp* 	thisInstance;
  ghERROR	errn;
  int		errcd=0, errcx=0;
  try {
	dout << g_appname << ":: BEGIN!\n";
	dout << g_appname << ":: flopsApp() create\n";
    thisInstance = new flopsApp( &argc, &argv );
	
	if ( !thisInstance ) throw ghErrorPush( ghERROR_INVALID_RUNNABLE );

    dout << g_appname << ":: flopsApp.run()\n";
    thisInstance->run();
	
  }
  catch( ... ) {
    dout << "FLOPS3::" << "  !! err x";
    errcx = ghErrorEnum();
    dout << errcx << " !!\n";
    
    dout << "  !!  enum {\n";
    if( errcx > 0 )
	  while( ghErrorPeek() ) {
		//don't combine with a debug statement ;)
		errn = ghErrorPop();
		dout << "FLOPS3::" << "  !!    ERR [#" << errn << "] : " << ghErrorGetString( errn ) << "\n";
/*
		if( errcd > errcx ) {
		  dout << "FLOPS3::" << "  !!      ~EXCEEDING INITIAL ERRORCOUNT. REDUNDANCY?\n";
		}
*/
	  }
    
  }
  
  if( thisInstance ) {
	dout << g_appname << ":: flopsApp.shutdown()\n";
    delete thisInstance;
  }
  
  dout << g_appname  << ":: END!\n";
  return 0;
}
