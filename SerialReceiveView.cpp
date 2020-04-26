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
    for(auto& [device, data] : vc.checkForData(vc.getIOMode())){
        if(data != "" ){
            append(device + ":  " + data);
        }
    }

               return Widget::timer_event();
    if(display_height() >= height()){
    scroll_down();
    //TODO make this nicer
    }
      }