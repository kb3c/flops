#include <iostream>
#include "flops.hpp"

int main( int argc, char** argv ) {
  flopsApp* 	thisInstance;
  ghERROR	errn;
  int		errcd=0, errcx=0;
  try {
    dout << "FLOPS3::" << "ENTRANT MAIN::flopsApp {\n";
    thisInstance = new flopsApp( &argc, &argv );
  /*
    dout << "FLOPS3::"<< "  startup() {\n";
    thisInstance->startup();
    dout << "FLOPS3::" << "  }\n";
  */ 
    dout << "FLOPS3::" << "  run() {\n";
    thisInstance->run();
    dout << "  }\n";
  }
  catch( ... ) {
    dout << "FLOPS3::" << "  !! err x";
    errcx = ghErrorEnum();
    dout << errcx << " !!\n";
    
    dout << "  !!  enum {\n";
    if( errcx > 0 ) {
	  while( ghErrorPeek() ) {
	  //don't combine with a debug statement ;)
	  errn = ghErrorPop();
	  dout << "FLOPS3::" << "  !!    ERR [#" << errn << "] : " << ghErrorGetString( errn ) << "\n";
	  
	  if( errcd > errcx ) {
	    dout << "FLOPS3::" << "  !!      ~EXCEEDING INITIAL ERRORCOUNT. REDUNDANCY?\n";
	  }
	}
    }
    
  }
  
  if( thisInstance ) {
    //thisInstance->shutdown();
    delete thisInstance;
  }
  
  dout << "FLOPS3::"  << "{ // flopsApp\n";
  return 0;
}

