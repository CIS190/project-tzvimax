#pragma once
#include "ViewController.hpp"
#include <cppurses/cppurses.hpp>

class SerialReceiveView : public cppurses::Textbox {


    private:

    const ViewController & vc;

    bool timer_event() override;
    // void updateBuffer();

    public:
    SerialReceiveView(const ViewController&);


    
};