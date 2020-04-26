#pragma once
#include "ViewController.hpp"
#include "SerialView.hpp"
#include <cppurses/cppurses.hpp>
#include <cppurses/system/detail/fps_to_period.hpp>

class View : public cppurses::layout::Vertical{

    SerialView& serialView;

    const ViewController& vc;

    public:
    View(const ViewController&);

};