#include "StatusBar.hpp"
#include "ViewController.hpp"
#include <cppurses/system/detail/fps_to_period.hpp>
#include <sstream>

StatusBar::StatusBar(ViewController& vc) : vc{vc}
{

    enable_animation(cppurses::detail::fps_to_period(60));


}
bool StatusBar::timer_event() {

    auto statusString = std::stringstream{};

    statusString << "Active Device: " << vc.getActiveDevice();
    statusString << "  Last Connection: " << vc.getLastConnectionStatus();
    statusString << "  Data Mode: " << vc.getIOModeString();
    statusString << "  AutoScroll: " << (vc.getAutoScroll() ? "YES" : "NO");
    statusString << "  Local Echo: " << (vc.getLocalEcho() ? "ON" : "OFF");
    statusString << "  Save File: " << vc.getSaveFile();


    this->update_status(statusString.str());

    return Widget::timer_event(); 
}
