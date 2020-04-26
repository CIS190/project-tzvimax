#include "View.hpp"

View::View(ViewController &vc) :
vc{vc},
menuStack{this->make_child<SerialMenuStack>(vc)},
serialView{this->make_child<SerialView>(vc)}
{}
