#include "Serial.hpp"
#include <cppurses/cppurses.hpp>
#include <cppurses/system/detail/fps_to_period.hpp>
#include <iostream>
#include <unistd.h>
#include "View.hpp"
#include "SerialHandler.hpp"
using namespace cppurses;

//TODO ReadMe with build instructions
//2 side by side buffers
//split screen, file, and serial is minmum to make it complex enough
//Mode to display as Hex, binary
//extend to TCP connection....
//Local Echo
//implement StreamBuff class as Serial--then you can create an ioStream.


// class TestMain : public cppurses::layout::Vertical {
// public:
//   TestMain() { init(); }

//   Glyph_string greeting{"Hello, World! This is where you will get Serial "
//                         "data and where you can type",
//                         Attribute::Bold};

//   // This could all be made cleaner, broken up into diff classes.

//   // make top level a child of myself
//   layout::Horizontal &h{this->make_child<layout::Horizontal>()};
//   layout::Vertical &v = h.make_child<layout::Vertical>();
//   Menu &menu{v.make_child<Menu>("Serial Options")};

//   Push_button &button = h.make_child<Push_button>("Button");
//   Menu_stack &stack = v.make_child<Menu_stack>("Stack");

//   Textbox &t = v.make_child<Textbox>(greeting);
//   Status_bar &sb = v.make_child<Status_bar>("status test");
//   Textbox &stackTb = stack.make_page<Textbox>("Test Menu in Stack");

//   std::string bufferIn;
//   // Serial serial{bufferIn};
//   Serial serial{};
//   bool timer_event()
//       override { // TODO encapsulate this in an "animated terminal"
//                  // TODO also this feeels like such a bad way to do this
//     // serial.getChar();
//     // t.append(serial.getBufferIn());
//     if(t.display_height() >= t.height()){
//     t.scroll_down();
//     //TODO make this nicer
//     }
//     // serial.clearBufferIn();
//     // std::cerr << serial.getBufferIn();
//     return Widget::timer_event();
//   }
//   void init() {
//     // Create a text string with Attributes, has type Glyph_string.
//     this->focus_policy = Focus_policy::Strong;
//     this->enable();
//     menu.enable();
//     stack.enable();
//     h.enable();
//     v.enable();
//     t.enable();
//     sb.enable();
//     stackTb.enable();


//   //TODO: print, save contents of screen
//     this->enable_animation(detail::fps_to_period(60));
//     t.enable_word_wrap();

//     menu.append_item("A");
//     menu.append_item("Disconnect").connect([this]{
//       serial.closeConn();
//       sb.set_contents("DISCONNECTED");
//     });
//     menu.append_item("Connect").connect([this]{
//                   std::string device{"/dev/cu.usbserial-AI04SV81"};
//       if( serial.openConn(device, 9600)){
//         sb.set_contents("CONNECTED");
//       } else { sb.set_contents("DISCONNECTED");}

//     });
//     menu.append_item("Print");
//     menu.height_policy.preferred(2);

//     button.clicked.connect([this] {
//       stack.goto_menu();
//       button.brush.set_background(Color::White);
//       button.brush.set_foreground(Color::Blue);
//       button.set_brush_paints_wallpaper(false);
//     });
//   }
// };

int main() {
  // Must create this object before any Widgets are created.
  System sys;
  // TestMain page;

  //TODO Main list of things to do
  //Fix Serial to not need a buffer passed in at creation?
  //Make the "main view" a stack so we can turn on of off the split screeen,
  //each one taking a new serial, and vc for their view....its a bit of a mess
  SerialHandler sh{};
  ViewController vc{sh};
  View view{vc};
  //TODO make this the serialSendWindow....
  System::set_initial_focus(&view);

  return sys.run(view);

  // std::cout << serial.getChar();
  // std::cout << serial.getChar();
  // std::cout << serial.getChar();
  // std::cout << serial.getChar();
  // std::cout << serial.getChar();

  // while(true){
  //  serial.getChar();
  //  std::cerr << serial.getBufferIn();
  //  serial.clearBufferIn();
  //  sleep(4);
  // }
}
