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
    std::vector<std::string> buffers;

    bool lastConnectionSuccessful;
    
    public :
        
    void connect(const std::string&, int);
    void disconnect();

    void sendData(const std::string&);
    void checkForData(ioModes);
    std::string getBuffer();
    void nextIOMode();
    ioModes getIOMode() const;
    std::string getIOModeString() const;

    void setActiveDevice(int);
    std::string nextDevice();
    bool hasActiveDevice();
    
    std::string getActiveDevice();
    std::string getLastConnectionStatus();


    
    ViewController(SerialHandler&);


};