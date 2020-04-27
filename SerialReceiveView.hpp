#pragma once
#include "ViewController.hpp"
#include <cppurses/cppurses.hpp>

class SerialReceiveView : public cppurses::Text_display {


    private:

    ViewController & vc;
    bool timer_event() override;
    // void updateBuffer();

    public:
    SerialReceiveView(ViewController&);


    
};