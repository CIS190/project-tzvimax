#include "WholeSerialInputView.hpp"

WholeSerialInputView::WholeSerialInputView(ViewController &vc) : vc{vc},
                                                                 serialSendView{this->make_child<SerialSendView>(vc)},
                                                                 inputTargetChoicesView{this->make_child<InputTargetChoicesView>(vc)}
{
}
