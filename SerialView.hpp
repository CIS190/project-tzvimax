#pragma once
#include <cppurses/cppurses.hpp>
#include "SerialReceiveView.hpp"
#include "WholeSerialInputView.hpp"

class SerialView : public cppurses::layout::Vertical {

private :
//TODO should we make all these const
    SerialReceiveView& serialReceiveView;
    WholeSerialInputView& wholeSerialInputView;

    ViewController & vc;

public :

SerialView(ViewController &vc);

};
