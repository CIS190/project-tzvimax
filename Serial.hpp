#pragma once
#include<string>

class Serial {

    public:
    Serial();
    bool openConn(std::string&, int const);

    //TODO close
    //TODO instead of open/close use construcgor and destructor
    // void appendBufferIn();
    // void overwriteBufferIn(); //resetBuffer 

    char getChar();
    // void clearBufferIn();
    void closeConn();

    std::string bufferIn;
// 
    // std::string& getBufferIn();
    private:
    //TODO maybe use a raw pointer?

    //TODO protect buffer with a mutex?
    //This really shouldn't be a string, it should just be bytes maybe
    // std::string& bufferIn;

    int fd;
    

};