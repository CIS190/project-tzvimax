#pragma once
#include "Serial.hpp"
// #include "View.hpp"
#include<map>

class ViewController {

private: 
    // const View& view;
    const Serial& serial;
    const std::string dataIn;

    //TODO should we make all of these refs const????

    enum ioModes {HEX, ASCII}ioMode;

    public :
        
    void connect(std::string&, int);
    void disconnect();

    void sendString(std::string);
    std::string checkForData();
    
    ViewController(const Serial&);


};