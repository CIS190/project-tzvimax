#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class InputConnectionInfoView : public cppurses::layout::Horizontal {
  private:
  cppurses::Textbox& deviceTextbox;
  cppurses::Textbox& baudTextbox;


  public:
  InputConnectionInfoView(ViewController&);
  cppurses::Push_button& connectButton;
};
