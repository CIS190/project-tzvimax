#include <cppurses/cppurses.hpp>
using namespace cppurses;

class TestMain : public cppurses::layout::Vertical {
public:
  TestMain() { init(); }

    Glyph_string greeting{"Hello, World! This is where you will get Serial "
                          "data and where you can type",
                          Attribute::Bold};

                          //This could all be made cleaner, broken up into diff classes.


    //make top level a child of myself
    layout::Horizontal &h{this->make_child<layout::Horizontal>()};
    layout::Vertical &v = h.make_child<layout::Vertical>();
    Menu &menu {v.make_child<Menu>("Serial Options")};

    Push_button &button = h.make_child<Push_button>("Button");
    Menu_stack &stack = v.make_child<Menu_stack>("Stack");

    Textbox& t = v.make_child<Textbox>(greeting);
    Status_bar& sb = v.make_child<Status_bar>("status test");
    Textbox& stackTb = stack.make_page<Textbox>("Test Menu in Stack");

  void init() {
    // Create a text string with Attributes, has type Glyph_string.
    this->focus_policy = Focus_policy::Strong;
    this->enable();
    menu.enable();
    stack.enable();
    h.enable();
    v.enable();
    t.enable();
    sb.enable();
    stackTb.enable();

    menu.append_item("A");
    menu.append_item("Disconnect");
    menu.append_item("Connect");
    menu.append_item("Print");
    menu.height_policy.preferred(2);
    

    button.clicked.connect([this] {
        
         stack.goto_menu();
    
    });


  }

};

int main() {
  // Must create this object before any Widgets are created.
  System sys;
    TestMain page;
        System::set_initial_focus(&page.h);

  return sys.run(page);
}
