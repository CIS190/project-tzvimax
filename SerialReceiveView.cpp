#include "SerialReceiveView.hpp"
#include "ViewController.hpp"
#include <cppurses/system/detail/fps_to_period.hpp>

SerialReceiveView::SerialReceiveView(ViewController &vc) : 
vc{vc}
{

    //TODO this is temporary
    // std::string device{"/dev/cu.usbserial-AI04SV81"};
    // vc.connect(device, 9600);

    //Setup Timer
    enable_animation(cppurses::detail::fps_to_period(60));


}

 bool SerialReceiveView::timer_event()
       {
           //TODO temp
           append(vc.checkForData("/dev/cu.usbserial-AI04SV81", vc.getIOMode()));
               return Widget::timer_event();
    if(display_height() >= height()){
    scroll_down();
    //TODO make this nicer
    }
      }