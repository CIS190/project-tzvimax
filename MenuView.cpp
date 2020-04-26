#include "MenuView.hpp"


MenuView::MenuView(): Menu("Serial Display") {
  this->append_item("Connect");
  this->append_item("Disconnect");

  this->height_policy.maximum(8);

  this->border.segments.east.disable();
  this->border.segments.west.disable();
  this->border.enable();
}
