#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialTextInputView.hpp"
#include "SerialSendButtonView.hpp"
#include "ViewController.hpp"
#include "SerialChoiceButtonView.hpp"

class SerialSendView : public cppurses::layout::Horizontal
{

private:
    SerialTextInputView &sendText;
    SerialSendButtonView &sendButton;
    ViewController &vc;

    sig::Signal<void()> &enterShortcut;

    void sendData();

public:
    SerialSendView(ViewController &);
};
