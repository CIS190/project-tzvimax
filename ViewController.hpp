#pragma once
#include "Serial.hpp"
#include "View.hpp"
#include<map>

class ViewController {

    View& view;
    
    Serial& serial;

    public :
        
    void connect(std::string&, int);
    void disconnect();

    void sendString(std::string);
    std::string checkForData();
    
    


};