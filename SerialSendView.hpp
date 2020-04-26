#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialTextInputView.hpp"
#include "SerialSendButtonView.hpp"
#include "SerialChoiceButtonView.hpp"

class SerialSendView : public cppurses::layout::Horizontal {

    public:

    SerialSendView();
};
