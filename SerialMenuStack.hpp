#pragma once
#include <cppurses/cppurses.hpp>
#include "InputConnectionInfoView.hpp"
#include "InputDisconnectionInfoView.hpp"
#include "ViewController.hpp"

class SerialMenuStack : public cppurses::Menu_stack {

  InputConnectionInfoView& inputConnectionInfoView;
  InputDisconnectionInfoView& inputDisconnectionInfoView;

  public:
  SerialMenuStack(ViewController&);
};
