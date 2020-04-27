#include "SerialSendView.hpp"
#include <cppurses/cppurses.hpp>
#include "ViewController.hpp"
#include "SerialTextInputView.hpp"
#include "SerialSendButtonView.hpp"

SerialSendView::SerialSendView(ViewController &vc) : vc{vc},
                                                     sendButton{this->make_child<SerialSendButtonView>()},
                                                     sendText{this->make_child<SerialTextInputView>()},
                                                     enterShortcut{cppurses::Shortcuts::add_shortcut(cppurses::Key::Enter)}

{

  this->border.segments.disable_all();
  this->border.segments.north.enable();
  this->border.segments.south.enable();
  this->border.enable();
  sendButton.brush.set_background(cppurses::Color::White);
  sendButton.brush.set_foreground(cppurses::Color::Blue);
  sendButton.set_brush_paints_wallpaper(false);

  this->height_policy.maximum(4);

  sendButton.clicked.connect([this] {
    sendData();
  });

  enterShortcut.connect([this] {
    sendData();
  });
}

void SerialSendView::sendData()
{

  if (this->vc.hasActiveDevice())
  {
    this->vc.sendData(this->sendText.contents().str() + "\n");
    if (this->vc.getLocalEcho())
    {
      this->vc.addBufferData("> " + this->sendText.contents().str() + "\n");
    }
    this->sendText.clear();
  }
}
