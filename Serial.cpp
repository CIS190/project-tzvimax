#include "Serial.hpp"
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include<sstream>
#include <iomanip>

Serial::Serial() : bufferIn{std::stringstream{}} {}

bool Serial::openConn(const std::string &device, int const baud) {
  // TODO check flags
  fd = open(device.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  // TODO is there a timeout?
  // TODO change to exception
  if (fd == -1) {
    std::cout << "COULD NOT OPEN";
    return false;
  }

  // TODO error handling
  // Asssumes fd opened correctly

  // TODO unsure about these options-experiment
  // Set echo options and stuff?

  // This code taken from
  // https://stackoverflow.com/questions/27609972/open-a-serial-port-with-arduino-using-c-with-xcode-on-mac
  struct termios options;
  fcntl(fd, F_SETFL, FNDELAY);      // Open the device in nonblocking mode
  tcgetattr(fd, &options);          // Get the current options of the port
  bzero(&options, sizeof(options)); // Clear all the options
  speed_t Speed;

  switch (baud) // Set the speed (baudRate)
  {
  case 110:
    Speed = B110;
    break;
  case 300:
    Speed = B300;
    break;
  case 600:
    Speed = B600;
    break;
  case 1200:
    Speed = B1200;
    break;
  case 2400:
    Speed = B2400;
    break;
  case 4800:
    Speed = B4800;
    break;
  case 9600:
    Speed = B9600;
    break;
  case 19200:
    Speed = B19200;
    break;
  case 38400:
    Speed = B38400;
    break;
  case 57600:
    Speed = B57600;
    break;
  case 115200:
    Speed = B115200;
    break;
  default:
    exit(-100); // TODO handle error
  }
  cfsetispeed(&options, Speed); // Set the baud rate at 115200 bauds
  cfsetospeed(&options, Speed);
  options.c_cflag |=
      (CLOCAL | CREAD |
       CS8); // Configure the device : 8 bits, no parity, no control
  options.c_iflag |= (IGNPAR | IGNBRK);
  options.c_cc[VTIME] = 0; // Timer unused
  options.c_cc[VMIN] = 0;  // At least on character before satisfy reading
  tcsetattr(fd, TCSANOW, &options); // Activate the settings
  return true;
}

void Serial::closeConn() { close(fd); }


std::string Serial::getASCIIData() {

   int count;
  ioctl(fd, FIONREAD, &count);
  char readBytes[count];

  if (count > 0) {
    int countRead = read(fd, readBytes, count);
    if (countRead > 0) {

      for (int i = 0; i < countRead; i++) {
        bufferIn << readBytes[i];
      }
    }
  }
  std::string bufferInTemp = bufferIn.str();
  bufferIn.str("");
  bufferIn.clear();
  return std::move(bufferInTemp);
}


std::string Serial::getHEXData() {
int count;
  ioctl(fd, FIONREAD, &count);
  char readBytes[count];

  if (count > 0) {
    int countRead = read(fd, readBytes, count);
    if (countRead > 0) {

      for (int i = 0; i < countRead; i++) {
        bufferIn << "0x" << std::setfill('0') << std::setw(2) << std::hex << 
            (0xff & (unsigned int) readBytes[i]);
      }
    }
  }
  std::string bufferInTemp = bufferIn.str();
  bufferIn.str("");
  bufferIn.clear();
  return std::move(bufferInTemp);
}


void Serial::sendData(const std::string& data){

}