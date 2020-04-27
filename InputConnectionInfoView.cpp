#include "InputConnectionInfoView.hpp"

InputConnectionInfoView::InputConnectionInfoView(ViewController& vc):
  deviceTextbox{this->make_child<cppurses::Textbox>()},
  baudTextbox{this->make_child<cppurses::Textbox>()},
  connectButton{this->make_child<cppurses::Push_button>("Connect")}
  {

  }
