#include "View.hpp"

View::View(ViewController &vc) :
vc{vc},
menuView{this->make_child<MenuView>()},
serialView{this->make_child<SerialView>(vc)}
{}
