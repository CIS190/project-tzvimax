#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class InputConnectionInfoView : public cppurses::layout::Horizontal {
  private:
  cppurses::Textbox& deviceTextbox;
  cppurses::Textbox& baudTextbox;
  cppurses::Push_button& connectButton;

  public:
  InputConnectionInfoView(ViewController&);
};
