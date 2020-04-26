#include "SerialView.hpp"
#include "SerialReceiveView.hpp"
#include "SerialSendView.hpp"

SerialView::SerialView() 
: serialReceiveView {this->make_child<SerialReceiveView>()},
serialSendView {this->make_child<SerialSendView>()}
 {}

 