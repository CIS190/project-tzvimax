#include "ViewController.hpp"
#include "SerialHandler.hpp"
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

ViewController::ViewController(SerialHandler &serial)
    : serial{serial},
      devices{std::vector<std::string>()},
      ioMode{ASCII},
      activeDevice{-1},
      lastConnectionSuccessful{false},
      buffers{std::vector<std::string>()},
      autoScroll{false},
      saveIncr{0},
      localEcho{false}
{

    saveFileName = std::string{SAVE_FILE};

    std::string incr = std::to_string(saveIncr);
    saveFileName.append(incr);
    saveFileName.append(".log");
}

void ViewController::saveFile()
{
    if (devices.size() > 0)
    {

        std::ofstream fileOut;
        fileOut.open(getSaveFile());
        fileOut << getBuffer();
        fileOut.close();
        saveFileName.erase(remove_if(saveFileName.begin(), saveFileName.end(),
                                     [](char c) { return !isalpha(c); }),
                           saveFileName.end());
        saveFileName.pop_back();
        saveFileName.pop_back();
        saveFileName.pop_back();

        saveFileName.append(std::to_string(++saveIncr));

        saveFileName.append(".log");
    }
}
void ViewController::connect(const std::string &device, int baud)
{
    try
    {
        serial.openConn(device, baud);
        devices.push_back(device);
        buffers.push_back("");

        if (devices.size() == 1)
        {
            activeDevice = 0;
        }
        lastConnectionSuccessful = true;
    }
    catch (std::exception e)
    {
        lastConnectionSuccessful = false;
    }
}

bool ViewController::getAutoScroll()
{
    return autoScroll;
}

std::string ViewController::getSaveFile()
{
    return saveFileName;
}

std::string ViewController::getBuffer()
{

    if (buffers.size() < 1 || activeDevice == -1)
    {
        return "";
    }
    else
    {
        return buffers[activeDevice];
    }
}


void ViewController::checkForData(ioModes mode)
{

    if (devices.size() < 1)
    {
        return;
    }
    else
    {
        for (int i = 0; i < devices.size(); i++)
        {
            switch (mode)
            {
            case ASCII:
                buffers[i].append(serial.getASCIIData(devices[i]));
                break;
            case HEX:
                buffers[i].append(serial.getHEXData(devices[i]));

                break;
            default:
                break;
            }
        }
    }
}
void ViewController::disconnect()
{
    try
    {
        if (devices.size() < 1 || activeDevice == -1)
        {
            //Nothing to disconnect from
            return;
        }

        serial.closeConn(devices.at(activeDevice));

        //handle if disconnect fails
    }
    catch (std::exception e)
    {
        //Status disconnect failed
    }
    devices.erase(devices.begin() + activeDevice);
    buffers.erase(buffers.begin() + activeDevice);

    activeDevice = 0;
}
void ViewController::setActiveDevice(int device)
{
    activeDevice = device;
}

void ViewController::sendData(const std::string &data)
{
    if (activeDevice < devices.size())
    {
      
        std::istringstream hex_chars_stream(data);
        std::vector<unsigned char> bytes;
        unsigned int c;

        switch (ioMode)
        {
        case ASCII:
            serial.sendData(devices[activeDevice], data);
            break;
        case HEX:

            while (hex_chars_stream >> std::hex >> c)
            {
                bytes.push_back(c);
            }

            serial.sendDataHex(devices[activeDevice], bytes.data(), bytes.size());

        default:
            break;
        }
    }

}


std::string ViewController::nextDevice()
{
    if (devices.size() < 1)
    {
        return "No Connections";
    }
    if (++activeDevice == devices.size())
    {
        activeDevice = 0;
    }

    return devices[activeDevice];
}

std::string ViewController::getActiveDevice()
{
    if (devices.size() > 0 && activeDevice != -1)
    {
        return devices[activeDevice];
    }
    return "No Connections";
}

bool ViewController::hasActiveDevice()
{
    if (devices.size() > 0 && activeDevice != -1)
    {
        return true;
    }
    return false;
}

std::string ViewController::getLastConnectionStatus()
{
    return lastConnectionSuccessful ? "Success" : "Failure";
}

//TODO
ViewController::ioModes ViewController::getIOMode() const
{
    return ioMode;
}

void ViewController::toggleAutoScroll()
{
    autoScroll = !autoScroll;
}

std::string ViewController::getIOModeString() const
{
    switch (ioMode)
    {
    case ASCII:
        return "ASCII";
        break;
    case HEX:
        return "Hex";
        break;
    default:
        break;
    }
}
void ViewController::nextIOMode()
{
    switch (ioMode)
    {
    case ASCII:
        ioMode = HEX;
        break;
    case HEX:
        ioMode = ASCII;
        break;
    default:
        break;
    }
}

void ViewController::toggleLocalEcho()
{
    localEcho = localEcho ? false : true;
}
bool ViewController::getLocalEcho()
{
    return localEcho;
}

void ViewController::addBufferData(const std::string &data)
{
    if (buffers.size() < 1 || activeDevice == -1)
    {
        return;
    }
    else
    {
        buffers[activeDevice].append(data);
    }
}
