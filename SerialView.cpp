#include "SerialView.hpp"
#include "SerialReceiveView.hpp"
#include "SerialSendView.hpp"

SerialView::SerialView(ViewController & vc) 
: vc{vc},
serialReceiveView {this->make_child<SerialReceiveView>(vc)},
serialSendView {this->make_child<SerialSendView>(vc)}
 {}

 