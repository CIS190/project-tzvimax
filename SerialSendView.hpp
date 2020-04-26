#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialTextInputView.hpp"
#include "SerialSendButtonView.hpp"

class SerialSendView : public cppurses::layout::Horizontal {

    public:

    SerialSendView();
};
