#include "InputTargetChoicesView.hpp"

InputTargetChoicesView::InputTargetChoicesView(ViewController& vc) :
  vc{vc},
  serialChoiceButtonView{this->make_child<SerialChoiceButtonView>(vc)},
  serialTypeButtonView{this->make_child<SerialTypeButtonView>(vc)},
  autoScrollToggle(this->make_child<cppurses::Push_button>("Toggle Autoscroll")),
  saveButton(this->make_child<cppurses::Push_button>("Save Input Buffer")),
  echoButton(this->make_child<cppurses::Push_button>("Toggle Local Echo"))


{
  autoScrollToggle.clicked.connect([this] {
    this->vc.toggleAutoScroll();
  });

  saveButton.clicked.connect([this] {
    this->vc.saveFile();
  });

  echoButton.clicked.connect([this] {
    this->vc.toggleLocalEcho();
  });
}
