#include "InputDisconnectionInfoView.hpp"

InputDisconnectionInfoView::InputDisconnectionInfoView(ViewController& vc):

  disconnectButton{this->make_child<cppurses::Push_button>("Disconnect")}
  {

    disconnectButton.brush.set_background(cppurses::Color::Red);

  }
