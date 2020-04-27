#include "ViewController.hpp"
// #include "View.hpp"
#include "SerialHandler.hpp"
#include <vector>

ViewController::ViewController(SerialHandler& serial)
: serial{serial},
    devices{std::vector<std::string>()},
    //TODO devices should maube be a map from devices to data to show
    ioMode{ASCII},
    activeDevice{-1},
    lastConnectionSuccessful{false},
    buffers{std::vector<std::string>()}
{
}

void ViewController::connect(const std::string& device, int baud){
    try{
    serial.openConn(device,baud);
    devices.push_back(device);
    buffers.push_back("");
    activeDevice++; //Connecting sets it as active??? Maybe we don't want that...
    lastConnectionSuccessful = true;
    } catch (std::exception e){
        lastConnectionSuccessful = false;
        //TODO I dont think this is set correctly
    }
    
}

std::string ViewController::getBuffer(){

    if(buffers.size() < 1 || activeDevice == -1){
        return "";
    } else{
    return buffers[activeDevice];
    }
}
void ViewController::checkForData(ioModes mode) {
   

   if(devices.size() < 1){
       return;
   } else{
    for(int i = 0; i < devices.size(); i++){
                switch (mode)
                {
                case ASCII:
                    buffers[i].append(serial.getASCIIData(devices[i]));
                    break;
                case HEX:
                    buffers[i].append(serial.getHEXData(devices[i]));

                        break;
                default:
                    break;
                }

    }
   }
   
}
void ViewController::disconnect() {
    try{
    if(devices.size() < 1 || activeDevice == -1) {
        //Nothing to disconnect from
        return;
    }
    serial.closeConn(devices.at(activeDevice));
    //TODO this won't do anything right now, but is to handle if disconnect fails
    
    } catch (std::exception e){
        //Status disconnect failed
    }
    devices.erase(devices.begin() + activeDevice);
    buffers.erase(buffers.begin() + activeDevice);
    //TODO: activeDevice--??
}
void ViewController::setActiveDevice(int device){
    activeDevice = device;
}

void ViewController::sendData(const std::string& data){
    if(activeDevice < devices.size()){
        std::stringstream ss{};
        std::stringstream ssBuffer{data};

    unsigned long long hexVal;

        switch (ioMode)
        {
        case ASCII:
        serial.sendData(devices[activeDevice], data);
            break;
        case HEX:
            for (int i =0; i < data.size(); i++){

                ssBuffer >> std::hex >> hexVal;

                ss << std::hex << hexVal;

            }
            serial.sendData(devices[activeDevice], ss.str());

        default:
            break;
        }

    }

    //TODO going to be a big problem using int for activeDevice--how to change it when you disconnect?
}


//TODO actually handle exception where no devices yet
std::string ViewController::nextDevice() {
    if(devices.size() < 1) {
        return "No Connections";
    }
    if(++activeDevice == devices.size()) {
        activeDevice = 0;
    }

    return devices[activeDevice];
}

std::string ViewController::getActiveDevice() {
    if(devices.size() > 0 && activeDevice != -1) {
            return devices[activeDevice];
    }
    return "No Connections";
}

bool ViewController::hasActiveDevice() {
    if(devices.size() > 0 && activeDevice != -1) {
            return true;
    }
    return false;
}

std::string ViewController::getLastConnectionStatus() {
    return lastConnectionSuccessful ? "Success" : "Failure";
}

//TODO
ViewController::ioModes ViewController::getIOMode() const{
return ioMode;
}

std::string ViewController::getIOModeString() const{
        switch (ioMode)
    {
    case ASCII:
        return "ASCII";
        break;
    case HEX:
        return "Hex";
        break;
    default:
        break;
    }
}
void ViewController::nextIOMode(){
    switch (ioMode)
    {
    case ASCII:
        ioMode = HEX;
        break;
    case HEX:
        ioMode = ASCII;
        break;
    default:
        break;
    }

}