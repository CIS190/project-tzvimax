#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"

class SerialTypeButtonView : public cppurses::Push_button
{

private:
  ViewController &vc;

public:
  SerialTypeButtonView(ViewController &);
};
