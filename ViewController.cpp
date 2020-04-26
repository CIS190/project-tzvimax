#include "ViewController.hpp"
// #include "View.hpp"

ViewController::ViewController(const Serial& serial)
: serial{serial}
{}

std::string ViewController::checkForData() const{
    ioMode = ViewController::HEX;
}

void ViewController::disconnect(){
        ioMode = ViewController::HEX;
}