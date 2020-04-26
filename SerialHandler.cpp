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

std::string SerialHandler::getData(const std::string& device){
    //TODO: okay to move? 
    return std::move(connections.at(device).getData());
}

void SerialHandler::sendData(const std::string&) const{

}