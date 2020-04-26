#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialReceiveView.hpp"
#include "SerialSendView.hpp"

class SerialView : public cppurses::layout::Vertical {

private : 
//TODO should we make all these const
    SerialReceiveView& serialReceiveView;
    SerialSendView& serialSendView;

    ViewController & vc;

public :

SerialView(ViewController &vc);

};