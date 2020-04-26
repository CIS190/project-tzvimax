#include "ViewController.hpp"
// #include "View.hpp"

ViewController::ViewController(Serial& serial)
: serial{serial}
{}

void ViewController::connect(std::string& device, int baud) const{

    serial.openConn(device,baud);

}

std::string ViewController::checkForData() const {

//TODO fix the way this is handled in Serial
serial.getChar();

std::string bufferCopy {serial.getBufferIn()};
serial.clearBufferIn();
//TODO: Copyting strings is bad
return bufferCopy;

}

void ViewController::disconnect() const {
}