#include "SerialReceiveView.hpp"
#include "ViewController.hpp"
#include <cppurses/system/detail/fps_to_period.hpp>

SerialReceiveView::SerialReceiveView(ViewController &vc) : 
vc{vc}
{
    this->focus_policy = cppurses::Focus_policy::Strong;

    //Setup Timer
    enable_animation(cppurses::detail::fps_to_period(60));
        // this->enable_scrollwheel();
        this->enable();
        

}

 bool SerialReceiveView::timer_event(){
           //TODO temp
    cppurses::Text_display::scroll_down(1000);

    vc.checkForData(vc.getIOMode());

    
    // if(vc.getAutoScroll()){
    // scroll_down(line_count() - bottom_line());

    // }
        // if(bottom_line() > 1){
        // this->enable_scrollwheel();
        // this->enable();
    // }

    set_contents(vc.getBuffer());

    return Widget::timer_event();

      }