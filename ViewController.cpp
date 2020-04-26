#include "ViewController.hpp"
// #include "View.hpp"
#include "SerialHandler.hpp"

ViewController::ViewController(SerialHandler& serial)
: serial{serial}
{}

void ViewController::connect(const std::string& device, int baud) const{

    serial.openConn(device,baud);

}

std::string ViewController::checkForData(const std::string& device, ioModes mode) const {
   
   switch (mode)
   {
   case ASCII:
    return std::move(serial.getASCIIData(device));
       break;
   case HEX:
       return std::move(serial.getHEXData(device));

        break;
   default:
       break;
   }
   
}
void ViewController::disconnect(const std::string& device) const {

    serial.closeConn(device);
}

void ViewController::sendData(const std::string& device, const std::string& data){

    serial.sendData(device,data);
}

//TODO
ViewController::ioModes ViewController::getIOMode() const{
return ASCII;
}