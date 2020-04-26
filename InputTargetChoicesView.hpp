#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialChoiceButtonView.hpp"

class InputTargetChoicesView : public cppurses::layout::Horizontal {


    private:
    SerialChoiceButtonView& serialChoiceButtonView;

    ViewController&  vc;
    
    public:
    InputTargetChoicesView(ViewController&);
};
