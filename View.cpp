#include "View.hpp"

View::View(const ViewController &vc) : 
vc{vc},
serialView{this->make_child<SerialView>()} 
{}