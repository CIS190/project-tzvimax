#pragma once
#include <cppurses/cppurses.hpp>
#include "InputConnectionInfoView.hpp"
#include "ViewController.hpp"

class SerialMenuStack : public cppurses::Menu_stack {

  InputConnectionInfoView& inputConnectionInfoView;
  public:
  SerialMenuStack(ViewController&);
};
