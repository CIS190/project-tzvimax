#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialChoiceButtonView.hpp"
#include "SerialTypeButtonView.hpp"

class InputTargetChoicesView : public cppurses::layout::Horizontal {


    private:
    SerialChoiceButtonView& serialChoiceButtonView;
    SerialTypeButtonView& serialTypeButtonView;

    ViewController&  vc;

    public:
    InputTargetChoicesView(ViewController&);
};
