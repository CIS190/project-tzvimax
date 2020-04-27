#include "Serial.hpp"
#include <cppurses/cppurses.hpp>
#include <cppurses/system/detail/fps_to_period.hpp>
#include <iostream>
#include <unistd.h>
#include "View.hpp"
#include "SerialHandler.hpp"
using namespace cppurses;

int main() {
  System sys;
  SerialHandler sh{};
  ViewController vc{sh};
  View view{vc};
  System::set_initial_focus(&view);

  return sys.run(view);
}
