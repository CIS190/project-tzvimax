#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialTextInputView.hpp"
#include "SerialSendButtonView.hpp"
#include "ViewController.hpp"
class SerialSendView : public cppurses::layout::Horizontal {


    private:
    SerialSendButtonView& sendButton;
    SerialTextInputView& sendText;
    ViewController&  vc;

    sig::Signal<void ()> & enterShortcut;

     void sendData(SerialSendView *);

    public:

    SerialSendView(ViewController&);
};
