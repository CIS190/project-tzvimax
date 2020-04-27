#include "InputConnectionInfoView.hpp"
#include <cppurses/cppurses.hpp>

InputConnectionInfoView::InputConnectionInfoView(ViewController& vc):
  deviceTextbox{this->make_child<cppurses::Textbox>()},
  baudTextbox{this->make_child<cppurses::Textbox>()},
  connectButton{this->make_child<cppurses::Push_button>("Connect")}
{

  connectButton.brush.set_background(cppurses::Color::Green);

  connectButton.height_policy.maximum(8);
  baudTextbox.height_policy.preferred(8);
  deviceTextbox.height_policy.maximum(8);

  baudTextbox.set_contents("9600");
  deviceTextbox.set_contents("/dev/ttys000");
}