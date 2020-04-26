#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialSendView.hpp"
#include "InputTargetChoicesView.hpp"

class WholeSerialInputView : public cppurses::layout::Vertical {


    private:
    SerialSendView& serialSendView;
    InputTargetChoicesView& inputTargetChoicesView;

    ViewController&  vc;

    public:
    WholeSerialInputView(ViewController&);
};
