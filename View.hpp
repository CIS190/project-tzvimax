#pragma once
#include "ViewController.hpp"
#include "SerialView.hpp"
#include "SerialMenuStack.hpp"
#include <cppurses/cppurses.hpp>
#include <cppurses/system/detail/fps_to_period.hpp>

class View : public cppurses::layout::Vertical{

    SerialMenuStack& menuStack;
    SerialView& serialView;
    cppurses::Status_bar& status;

    ViewController& vc;

    public:
    View(ViewController&);

};
