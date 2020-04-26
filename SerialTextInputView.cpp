#include "SerialTextInputView.hpp"

SerialTextInputView::SerialTextInputView() {
  this->border.segments.disable_all();
  this->border.segments.east.enable();
  this->border.segments.south.enable();
  this->border.enable();

  this->height_policy.maximum(4);
}
