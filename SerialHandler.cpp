#include "SerialHandler.hpp"
#include "Serial.hpp"

//TODO what here is needed
#include <iostream>
#include <sstream>
#include<map>

SerialHandler::SerialHandler() : connections{std::map<std::string,Serial>{}} 
{}

void SerialHandler::openConn(const std::string& device, int baud){

    //TODO does this automatically construct?? I think it does
    connections.emplace(device, Serial{});
    connections.at(device).openConn(device, baud);
}

void SerialHandler::closeConn(const std::string& device){
    connections.at(device).closeConn();
    connections.erase(device);
}

std::string SerialHandler::getASCIIData(const std::string& device){
    //TODO: okay to move? 

    //TODO fix this to move up handlign
try{
    return std::move(connections.at(device).getASCIIData());

    }
    catch(std::out_of_range e) {
        return "";
    }
}
std::string SerialHandler::getHEXData(const std::string& device){
    //TODO: okay to move? 
    return std::move(connections.at(device).getHEXData());
}


void SerialHandler::sendData(const std::string& device, const std::string& data) {

    connections.at(device).sendData(data);

}

void SerialHandler::sendDataAll(const std::string& data) {

    for(auto& [device, serial] : connections)
        serial.sendData(data);
}