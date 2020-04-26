#pragma once
#include<string>

class Serial {


private:
    std::string bufferIn;
    int fd;


public:
    Serial();
    bool openConn(const std::string&, int const);
    void closeConn();

    //Gets data and clears current buffer
    std::string getData();

    

};