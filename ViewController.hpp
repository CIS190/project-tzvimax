#pragma once
#include "Serial.hpp"
// #include "View.hpp"
#include<map>
#include "SerialHandler.hpp"
#include<vector>

class ViewController {

private: 
    // const View& view;
    SerialHandler& serial;

    //TODO should we make all of these refs const????
        //Answer-NO

    enum ioModes {HEX, ASCII}ioMode;
    int activeDevice;
    std::vector<std::string> devices;
    
    public :
        
    void connect(const std::string&, int);
    void disconnect();

    void sendData(const std::string&);
    std::map<std::string,std::string> checkForData(ioModes) const;

    void setIOMode(ioModes);
    ioModes getIOMode() const;

    void setActiveDevice(int);
    std::string nextDevice();
    
    ViewController(SerialHandler&);


};