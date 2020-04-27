#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class InputConnectionInfoView : public cppurses::layout::Horizontal {

  public:
  InputConnectionInfoView(ViewController&);
  cppurses::Push_button& connectButton;
  cppurses::Textbox& deviceTextbox;
  cppurses::Textbox& baudTextbox;
  
};
