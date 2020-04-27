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

bool SerialReceiveView::timer_event()
{
  
  vc.checkForData(vc.getIOMode());
  set_contents(vc.getBuffer());

  if(vc.getAutoScroll()){
    scroll_down((line_count() - bottom_line()));
  }

  return Widget::timer_event();

 }
