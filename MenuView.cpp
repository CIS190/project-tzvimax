#include "MenuView.hpp"
#include "ViewController.hpp"


MenuView::MenuView(ViewController &vc):
vc{vc},
Menu("Serial Display") {
  this->append_item("Connect").connect([this]{
        std::string device{"/dev/cu.usbserial-AI04SV81"};

    this->vc.connect(device, 9600);

  });
  this->append_item("Disconnect").connect([this]{
            std::string device{"/dev/cu.usbserial-AI04SV81"};
    this->vc.disconnect(device);
  });

  this->height_policy.maximum(8);

  this->border.segments.east.disable();
  this->border.segments.west.disable();
  this->border.enable();
}
