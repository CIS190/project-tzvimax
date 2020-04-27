#include "SerialSendButtonView.hpp"

SerialSendButtonView::SerialSendButtonView()
{

  this->height_policy.maximum(4);
  this->width_policy.maximum(8);

  this->border.segments.disable_all();
  this->border.segments.west.enable();
  this->border.enable();

  this->set_label("Send");
}
