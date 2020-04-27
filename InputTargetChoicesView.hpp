#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialChoiceButtonView.hpp"
#include "SerialTypeButtonView.hpp"

class InputTargetChoicesView : public cppurses::layout::Horizontal {


    private:
    SerialChoiceButtonView& serialChoiceButtonView;
    SerialTypeButtonView& serialTypeButtonView;
    cppurses::Push_button& autoScrollToggle;
    cppurses::Push_button& saveButton;
    cppurses::Push_button& echoButton;
    

    ViewController&  vc;

    public:
    InputTargetChoicesView(ViewController&);
};
