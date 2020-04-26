#pragma once
#include "ViewController.hpp"
#include "SerialView.hpp"
#include "MenuView.hpp"
#include <cppurses/cppurses.hpp>
#include <cppurses/system/detail/fps_to_period.hpp>

class View : public cppurses::layout::Vertical{

    MenuView& menuView;
    SerialView& serialView;

    ViewController& vc;

    public:
    View(ViewController&);

};
