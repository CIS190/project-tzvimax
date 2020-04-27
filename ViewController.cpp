#include "ViewController.hpp"
// #include "View.hpp"
#include "SerialHandler.hpp"
#include <vector>

ViewController::ViewController(SerialHandler& serial)
: serial{serial},
    devices{std::vector<std::string>()},
    //TODO devices should maube be a map from devices to data to show
    ioMode{ASCII},
    activeDevice{-1}
{
}

void ViewController::connect(const std::string& device, int baud){
    try{
    serial.openConn(device,baud);
    } catch (std::exception e){
        //TODO open failed
    }
    devices.push_back(device);
    if(devices.size() < 1) {
        activeDevice = -1;
    } else{
        activeDevice++; //Connecting sets it as active??? Maybe we don't want that...
    }
    //TODO handling activeDevice properly

}

std::map<std::string,std::string> ViewController::checkForData(ioModes mode) const {
   
   auto result{std::map<std::string, std::string>()};

   if(devices.size() < 1){
       return result;
   } else{
    for(auto device : devices){
                switch (mode)
                {
                case ASCII:
                    result.emplace(device,serial.getASCIIData(device));
                    break;
                case HEX:
                    result.emplace(device,serial.getHEXData(device));

                        break;
                default:
                    break;
                }

    }
    return result;
   }
   //TODO we should be able to tell if connected here without having to rely on exception from getData();
   
}
void ViewController::disconnect() {
    try{
    serial.closeConn(devices.at(activeDevice));

    } catch (std::exception e){
        //TODO handle
    }
    // auto deviceIt = std::find(devices.begin(), devices.end(), device);
    // if(deviceIt != devices.end()){
        devices.erase(devices.begin() + activeDevice);
    // } else{
        //TODO yuo have a problem
    // }
    //TODO reset activeDEvice

}
void ViewController::setActiveDevice(int device){
    activeDevice = device;
}

void ViewController::sendData(const std::string& data){
    if(activeDevice < devices.size()){
    serial.sendData(devices[activeDevice], data);

    }

    //TODO going to be a big problem using int for activeDevice--how to change it when you disconnect?
}


//TODO actually handle exception where no devices yet
std::string ViewController::nextDevice() {
    if(devices.size() < 1) {
        return "";
    }
    if(++activeDevice == devices.size()) {
        activeDevice = 0;
    }

    return devices[activeDevice];
}

//TODO
ViewController::ioModes ViewController::getIOMode() const{
return ioMode;
}