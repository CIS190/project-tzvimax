#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class InputDisconnectionInfoView : public cppurses::layout::Horizontal {

  public:
  InputDisconnectionInfoView(ViewController&);
  cppurses::Push_button& disconnectButton;
  // cppurses::Textbox& deviceTextbox;
  
};
