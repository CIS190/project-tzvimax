#include "SerialSendButtonView.hpp"

SerialSendButtonView::SerialSendButtonView() {

  this->height_policy.maximum(4);
  this->width_policy.maximum(8);
  this->set_label("Send");
}
