#include "SerialTypeButtonView.hpp"

SerialTypeButtonView::SerialTypeButtonView(ViewController& vc):
  vc{vc}

{
  this->height_policy.maximum(4);
  this->width_policy.maximum(18);

  this->border.segments.disable_all();
  this->border.segments.west.enable();
  this->border.enable();
  this->brush.set_background(cppurses::Color::Light_blue);
  this->set_brush_paints_wallpaper(false);

  this->set_label("Toggle ASCII/HEX");

  this->clicked.connect([this]{
    this->vc.nextIOMode();
    // this->set_label(this->vc.getIOModeString());
  });
}
