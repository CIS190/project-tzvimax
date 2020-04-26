#pragma once

#include <iostream>
#include <sstream>
#include<map>

#include "Serial.hpp"

class SerialHandler{

private:

//TODO okay to have this map of ojects?
std::map<std::string, Serial> connections;

public:
//TODO throw exceptions, and handle in UI

SerialHandler();
void openConn(const std::string&, int);

void closeConn(const std::string&);

std::string getData(const std::string&);

void sendData(const std::string&) const;


};