#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"
class MenuView: public cppurses::Menu {
  private:
  ViewController & vc;
  public:
  MenuView(ViewController &);
};
