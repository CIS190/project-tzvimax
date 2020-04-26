#include "SerialTypeButtonView.hpp"

SerialTypeButtonView::SerialTypeButtonView(ViewController& vc):
  vc{vc}

{
  this->height_policy.maximum(4);
  this->width_policy.maximum(18);

  this->border.segments.disable_all();
  this->border.segments.west.enable();
  this->border.enable();

  this->set_label("ASCII");
}
