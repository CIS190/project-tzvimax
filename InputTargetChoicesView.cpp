#include "InputTargetChoicesView.hpp"

InputTargetChoicesView::InputTargetChoicesView(ViewController& vc) :
  vc{vc},
  serialChoiceButtonView{this->make_child<SerialChoiceButtonView>(vc)},
  serialTypeButtonView{this->make_child<SerialTypeButtonView>(vc)}
{}
