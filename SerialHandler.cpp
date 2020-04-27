#include "SerialHandler.hpp"
#include "Serial.hpp"

//TODO what here is needed
#include <iostream>
#include <sstream>
#include<map>

SerialHandler::SerialHandler() : connections{std::map<std::string,Serial>{}} 
{}

void SerialHandler::openConn(const std::string& device, int baud){

    connections.emplace(device, Serial{});
    if (!connections.at(device).openConn(device, baud)){
        throw std::exception();
    }
}

void SerialHandler::closeConn(const std::string& device){
    connections.at(device).closeConn();
    connections.erase(device);
}

std::string SerialHandler::getASCIIData(const std::string& device){
try{
    return std::move(connections.at(device).getASCIIData());
        
    }   
    catch(std::out_of_range e) {
        return "ERROR";
    }
}
std::string SerialHandler::getHEXData(const std::string& device){
    return std::move(connections.at(device).getHEXData());
}


void SerialHandler::sendData(const std::string& device, const std::string& data) {

    connections.at(device).sendData(data);

}

void SerialHandler::sendDataHex(const std::string& device, unsigned char * bytes, int len) {

    connections.at(device).sendDataHex(bytes, len);

}

void SerialHandler::sendDataAll(const std::string& data) {

    for(auto& [device, serial] : connections)
        serial.sendData(data);
}