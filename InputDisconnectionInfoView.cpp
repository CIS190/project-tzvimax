#include "InputDisconnectionInfoView.hpp"

InputDisconnectionInfoView::InputDisconnectionInfoView(ViewController& vc):
  // deviceTextbox{this->make_child<cppurses::Textbox>()},
  disconnectButton{this->make_child<cppurses::Push_button>("Disconnect")}
  {

    disconnectButton.brush.set_background(cppurses::Color::Red);

  }
