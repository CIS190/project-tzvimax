#include "SerialReceiveView.hpp"
#include "ViewController.hpp"
#include <cppurses/system/detail/fps_to_period.hpp>

SerialReceiveView::SerialReceiveView(ViewController &vc) : 
vc{vc}
{

    //Setup Timer
    enable_animation(cppurses::detail::fps_to_period(60));


}

 bool SerialReceiveView::timer_event()
       {
           //TODO temp
    vc.checkForData(vc.getIOMode());

    
    if(vc.getAutoScroll()){
    scroll_down(line_count() - bottom_line());
                   return Widget::timer_event();

    }
    set_contents(vc.getBuffer());
      }