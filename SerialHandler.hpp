#pragma once

#include <iostream>
#include <sstream>
#include<map>

#include "Serial.hpp"

class SerialHandler{

private:

std::map<std::string, Serial> connections;

public:

SerialHandler();
void openConn(const std::string&, int);

void closeConn(const std::string&);

std::string getASCIIData(const std::string&);
std::string getHEXData(const std::string&);


void sendData(const std::string&, const std::string&);
void sendDataHex(const std::string&, unsigned char *, int);
void sendDataAll(const std::string&);
};