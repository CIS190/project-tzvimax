#include "SerialReceiveView.hpp"
#include "ViewController.hpp"

SerialReceiveView::SerialReceiveView(const ViewController &vc) : 
vc{vc}
{}

 bool SerialReceiveView::timer_event()
       {

           std::string receivedStr = vc.checkForData();
           this->append(receivedStr);
      }