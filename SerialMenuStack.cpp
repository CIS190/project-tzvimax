#include "SerialMenuStack.hpp"


SerialMenuStack::SerialMenuStack(ViewController& vc) :
  Menu_stack("Serial Menu"),
  inputConnectionInfoView{this->make_page<InputConnectionInfoView>("Add Connection",vc)},
  inputDisconnectionInfoView{this->make_page<InputDisconnectionInfoView>("Remove Connection",vc)}
  {
    inputConnectionInfoView.connectButton.clicked.connect([this] {
            this->goto_menu();
    });

    inputDisconnectionInfoView.disconnectButton.clicked.connect([this] {
            this->goto_menu();
    });

    this->border.segments.disable_all();
    this->border.segments.north.enable();
    this->border.segments.south.enable();
    this->border.enable();

    this->height_policy.maximum(8);
  }
