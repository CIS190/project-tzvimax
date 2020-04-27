#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class SerialChoiceButtonView : public cppurses::Push_button
{

private:
  ViewController &vc;
  bool timer_event() override;

public:
  SerialChoiceButtonView(ViewController &);
};
