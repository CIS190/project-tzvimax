#include "SerialSendView.hpp"
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"
#include "SerialTextInputView.hpp"
#include "SerialSendButtonView.hpp"

SerialSendView::SerialSendView(ViewController& vc) :
    vc{vc},
    sendButton{this->make_child<SerialSendButtonView>()},
    sendText{this->make_child<SerialTextInputView>()},
    enterShortcut{cppurses::Shortcuts::add_shortcut(cppurses::Key::Enter)}

{

        //TODO make this a function?
        //Set Visuals
        this->border.segments.disable_all();
        this->border.segments.north.enable();
        this->border.segments.south.enable();
        this->border.enable();
      sendButton.brush.set_background(cppurses::Color::White);
      sendButton.brush.set_foreground(cppurses::Color::Blue);
      sendButton.set_brush_paints_wallpaper(false);

        this->height_policy.maximum(4);


        //OnClickFor Button
        //TODO break any of this out into another function?
        sendButton.clicked.connect([this] {
                sendData();
    });


    enterShortcut.connect([this] {

                        sendData();
 });

    //TODO borde can be nicer like this:
      //      left_side.settings.border.segments.south_west = L'╰';


 }

 void SerialSendView::sendData(){
    //TODO send ascii vs text

  if(this->vc.hasActiveDevice()){
      this->vc.sendData(this->sendText.contents().str());
      if(this->vc.getLocalEcho()) {
        this->vc.addBufferData(this->sendText.contents().str());
      }
      this->sendText.clear();

  }
      // sendButton.brush.set_background(cppurses::Color::Black);
      // sendButton.brush.set_foreground(cppurses::Color::White);
          // sendButton.brush.remove_foreground();



 }
