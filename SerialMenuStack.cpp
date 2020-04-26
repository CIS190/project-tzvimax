#include "SerialMenuStack.hpp"


SerialMenuStack::SerialMenuStack(ViewController& vc) :
  Menu_stack("Serial Menu"),
  inputConnectionInfoView{this->make_page<InputConnectionInfoView>("Add Connection",vc)}
  {}
