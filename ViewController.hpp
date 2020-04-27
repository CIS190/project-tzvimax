#pragma once
#include "Serial.hpp"
// #include "View.hpp"
#include<map>
#include "SerialHandler.hpp"
#include<vector>

#define SAVE_FILE "buffer"


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
    bool autoScroll;

    std::string saveFileName;
    int saveIncr;
    
    bool localEcho;

    public :
        
    void connect(const std::string&, int);
    void disconnect();

    void sendData(const std::string&);
    void checkForData(ioModes);
    std::string getBuffer();

    void addBufferData(const std::string &);

    void nextIOMode();
    ioModes getIOMode() const;
    std::string getIOModeString() const;

    void setActiveDevice(int);
    std::string nextDevice();
    bool hasActiveDevice();
    
    std::string getActiveDevice();
    std::string getLastConnectionStatus();

    std::string getSaveFile();

    void saveFile();

    bool getAutoScroll();
    void toggleAutoScroll();

    void toggleLocalEcho();
    bool getLocalEcho();



    
    ViewController(SerialHandler&);


};