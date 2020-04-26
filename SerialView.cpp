#include "SerialView.hpp"
#include "SerialReceiveView.hpp"
#include "SerialSendView.hpp"

SerialView::SerialView(ViewController & vc)
: vc{vc},
serialReceiveView {this->make_child<SerialReceiveView>(vc)},
wholeSerialInputView {this->make_child<WholeSerialInputView>(vc)}
 {}
