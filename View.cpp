#include "View.hpp"

View::View(const ViewController &vc) : serialView{this->make_child<SerialView>()} 
{}