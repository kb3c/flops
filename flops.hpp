#include <iostream>
#include "gh/gh.hpp"
#include "gh/ghpc.h"


class flopsApp : public gh::APPLICATION {
public:
  flopsApp( int* pargc, char*** pargv ) : APPLICATION( pargc, pargv ) {
    dout << "      FLOPS3 init v0.0.1.0 {\n";
    wndFlops_ = new gh::WINDOW();
    wndFlopStatus_ = new gh::WINDOW();
      
    dout  << "FLOPS3::" << "        + position/size main display window.\n";
    wndFlops_->setPosition( 50, 50 );
    wndFlops_->setExtent( 320, 200 );
    wndFlops_->setCaption( "flopsss" );
    
    dout << "FLOPS3::" << "        + Position/Size Status Display\n";
    wndFlopStatus_->setPosition( 10, 180 );
    wndFlopStatus_->setExtent( 300, 10 );
	wndFlopStatus_->setBorderWidth( 1 );

    
    dout  << "FLOPS3::" << "        + init main display window.\n";
    wndFlops_->init();
	
	wndFlopStatus_->setParent( wndFlops_ );
	
    dout  << "FLOPS3::" << "        + init status display\n";
    wndFlopStatus_->init();
    
    dout  << "FLOPS3::" << "        + show main display window.\n";
    wndFlops_->show();
    
    dout  << "FLOPS3::" << "        + show status display window.\n";
    wndFlopStatus_->show();
    
    
  };
  
  ~flopsApp( ) {
    dout  << "FLOPS3::" << "FLOPSSS shutdown\n";
  };
  
protected:
  
private:
  gh::WINDOW* wndFlops_;
  gh::WINDOW* wndFlopStatus_;

};

