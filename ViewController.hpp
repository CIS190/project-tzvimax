#pragma once
#include "Serial.hpp"
// #include "View.hpp"
#include<map>

class ViewController {

private: 
    // const View& view;
    Serial& serial;
    const std::string dataIn;

    //TODO should we make all of these refs const????
        //Answer-NO

    enum ioModes {HEX, ASCII}ioMode;

    public :
        
    void connect(std::string&, int) const;
    void disconnect() const;

    void sendString(std::string) const;
    //TODO copying strings==bad???!
    //Better is to decide who owns the pointer to data, 
    //and pass that around 
    //For nwo serial just returns a new string
    std::string checkForData() const;

    void setIOMode(ioModes);
    
    ViewController(Serial&);


};