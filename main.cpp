#include <cppurses/cppurses.hpp>
using namespace cppurses;

int main() {
    // Must create this object before any Widgets are created.
    System sys;

    // Create a text string with Attributes, has type Glyph_string.
    Glyph_string greeting{"Hello, World!", Attribute::Underline};

    // Create Textbox Widget with `greeting` as the initial text.
    Textbox tb{greeting};

    // Set the background and foreground colors of the Textbox.
    tb.brush.set_background(Color::Dark_blue);
    tb.brush.set_foreground(Color::Light_blue);

    // Enable a border to be drawn around the Textbox.
    tb.border.enable();

    // Set the Textbox as the head(top-level) Widget, initialize the screen and
    // start the user input event loop.
    return sys.run(tb);
}
