#include "ViewController.hpp"
// #include "View.hpp"
#include "SerialHandler.hpp"

ViewController::ViewController(SerialHandler& serial)
: serial{serial}
{}

void ViewController::connect(const std::string& device, int baud) const{

    serial.openConn(device,baud);

}

std::string ViewController::checkForData(const std::string& device) const {

    return std::move(serial.getData(device));

}
void ViewController::disconnect(const std::string& device) const {

    serial.closeConn(device);
}