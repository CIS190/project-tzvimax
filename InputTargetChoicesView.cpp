#include "InputTargetChoicesView.hpp"

InputTargetChoicesView::InputTargetChoicesView(ViewController &vc) : vc{vc},
                                                                     serialChoiceButtonView{this->make_child<SerialChoiceButtonView>(vc)},
                                                                     serialTypeButtonView{this->make_child<SerialTypeButtonView>(vc)},
                                                                     autoScrollToggle(this->make_child<cppurses::Push_button>("Toggle Autoscroll")),
                                                                     saveButton(this->make_child<cppurses::Push_button>("Save Input Buffer")),
                                                                     echoButton(this->make_child<cppurses::Push_button>("Toggle Local Echo"))

{

  autoScrollToggle.height_policy.maximum(4);
  autoScrollToggle.width_policy.maximum(30);
  autoScrollToggle.brush.set_background(cppurses::Color::Light_blue);
  autoScrollToggle.set_brush_paints_wallpaper(false);
  saveButton.height_policy.maximum(4);
  saveButton.width_policy.maximum(30);
  saveButton.brush.set_background(cppurses::Color::Light_blue);
  saveButton.set_brush_paints_wallpaper(false);
  echoButton.height_policy.maximum(4);
  echoButton.width_policy.maximum(30);
  echoButton.brush.set_background(cppurses::Color::Light_blue);
  echoButton.set_brush_paints_wallpaper(false);



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
