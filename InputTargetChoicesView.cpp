#include "InputTargetChoicesView.hpp"

InputTargetChoicesView::InputTargetChoicesView(ViewController& vc) :
  vc{vc},
  serialChoiceButtonView{this->make_child<SerialChoiceButtonView>(vc)}
  {}
