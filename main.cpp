#include <cppurses/cppurses.hpp>
using namespace cppurses;

int main() {
    // Must create this object before any Widgets are created.
    System sys;

    // Create a text string with Attributes, has type Glyph_string.
    Glyph_string greeting{"Hello, World!", Attribute::Underline};

    // Create Textbox Widget with `greeting` as the initial text.
    // Textbox tb{greeting};

    // Menu menu{"menu"};
    // menu.append_item("test");
    // Textbox & tb = menu.make_child<Textbox>(greeting);
    layout::Vertical v{};
    v.make_child<Menu>("menu V Test");
    v.make_child<Textbox>(greeting);

    layout::Stack stack{};

    stack.make_page<Menu>("menu Test");
    stack.make_page<Textbox>(greeting);
    stack.set_active_page(1);
    
    v.enable();

    stack.enable();
    // v.enable();
    // tb.enable();
    // menu.enable();


    // Set the background and foreground colors of the Textbox.
    // tb.brush.set_background(Color::Dark_blue);
    // tb.brush.set_foreground(Color::Light_blue);

    // Enable a border to be drawn around the Textbox.
    // tb.border.enable();

    // Set the Textbox as the head(top-level) Widget, initialize the screen and
    // start the user input event loop.
    return sys.run(v);
}
