#include "MenuView.hpp"


MenuView::MenuView(): Menu("Serial Menu") {
  this->append_item("Connect");
  this->append_item("Disconnect");
}
