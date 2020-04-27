#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class InputDisconnectionInfoView : public cppurses::layout::Horizontal {
  private:
  cppurses::Textbox& deviceTextbox;


  public:
  InputDisconnectionInfoView(ViewController&);
  cppurses::Push_button& disconnectButton;
};
