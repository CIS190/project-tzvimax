#include "SerialChoiceButtonView.hpp"
#include <cppurses/system/detail/fps_to_period.hpp>

SerialChoiceButtonView::SerialChoiceButtonView(ViewController& vc):
  vc{vc}

{
  this->height_policy.maximum(4);
  this->width_policy.maximum(40);

  this->border.segments.disable_all();
  this->border.segments.west.enable();
  this->border.enable();
  
    enable_animation(cppurses::detail::fps_to_period(60));

  this->set_label("Toggle Active Device");
  this->brush.set_background(cppurses::Color::Light_blue);
  this->set_brush_paints_wallpaper(false);


      

  this->clicked.connect([this]{
  this->vc.nextDevice();
  });

}

 bool SerialChoiceButtonView::timer_event()
       {
           //TODO temp
    // this->set_label(vc.getActiveDevice());
    return Widget::timer_event();

    }


