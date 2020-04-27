#pragma once
#include <cppurses/cppurses.hpp>
#include "InputConnectionInfoView.hpp"
#include "InputDisconnectionInfoView.hpp"
#include "ViewController.hpp"

class SerialMenuStack : public cppurses::Menu_stack
{

private:
  sig::Signal<void()> &escShortcut;
  InputConnectionInfoView &inputConnectionInfoView;
  InputDisconnectionInfoView &inputDisconnectionInfoView;

  ViewController &vc;

public:
  SerialMenuStack(ViewController &);
};
