#include "SerialMenuStack.hpp"


SerialMenuStack::SerialMenuStack(ViewController& vc) :
  Menu_stack("Serial Menu"),
  vc{vc},
  inputConnectionInfoView{this->make_page<InputConnectionInfoView>("Add Connection",vc)},
  inputDisconnectionInfoView{this->make_page<InputDisconnectionInfoView>("Remove Connection",vc)}
  {
    inputConnectionInfoView.connectButton.clicked.connect([this] {
            try{
              this->vc.connect(inputConnectionInfoView.deviceTextbox.contents().str(),
                            std::stoi(inputConnectionInfoView.baudTextbox.contents().str()));
            } catch(std::exception e) {
              // problem getting input
            }
            // throw (std::exception());

            this->goto_menu();

    });

    inputDisconnectionInfoView.disconnectButton.clicked.connect([this] {
            this->goto_menu();
            try{
                this->vc.disconnect();
            } catch(std::exception e) {
              //problem getting disconnect info
            }
    });

    this->border.segments.disable_all();
    this->border.segments.north.enable();
    this->border.segments.south.enable();
    this->border.enable();

    this->height_policy.maximum(8);

  }
