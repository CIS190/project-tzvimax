#pragma once
#include "Serial.hpp"
// #include "View.hpp"
#include<map>
#include "SerialHandler.hpp"
class ViewController {

private: 
    // const View& view;
    SerialHandler& serial;

    //TODO should we make all of these refs const????
        //Answer-NO

    enum ioModes {HEX, ASCII}ioMode;

    public :
        
    void connect(const std::string&, int) const;
    void disconnect(const std::string&) const;

    void sendString(std::string) const;
    std::string checkForData(const std::string&, ioModes) const;

    void setIOMode(ioModes);
    
    ViewController(SerialHandler&);


};