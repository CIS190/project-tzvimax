#pragma once
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"
class StatusBar : public cppurses::Status_bar{

private:
        ViewController& vc;
        bool timer_event() override;


public:

StatusBar(ViewController&);

};