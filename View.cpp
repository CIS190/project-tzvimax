#include "View.hpp"

View::View(ViewController &vc) : 
vc{vc},
serialView{this->make_child<SerialView>(vc)} 
{}