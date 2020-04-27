#pragma once
#include<string>
#include<sstream>

class Serial {


private:
    std::stringstream bufferIn;
    int fd;

public:
    Serial();
    bool openConn(const std::string&, int const);
    void closeConn();

    //Gets data and clears current buffer
    std::string getASCIIData();
    std::string getHEXData();
    void sendData(const std::string& );
    void sendDataHex(unsigned char *, int);

};