cmake_minimum_required(VERSION 3.0.0)
project(190 VERSION 0.1.0)

add_executable(190.out main.cpp SerialReceiveView.cpp SerialSendView.cpp SerialView.cpp View.cpp ViewController.cpp
Serial.cpp SerialTextInputView.cpp SerialTextInputView.hpp SerialSendButtonView.hpp SerialSendButtonView.cpp
SerialHandler.cpp SerialChoiceButtonView.hpp SerialChoiceButtonView.cpp
InputTargetChoicesView.cpp InputTargetChoicesView.hpp
WholeSerialInputView.cpp WholeSerialInputView.hpp
SerialMenuStack.cpp SerialMenuStack.hpp
InputConnectionInfoView.cpp InputConnectionInfoView.hpp
SerialTypeButtonView.cpp SerialTypeButtonView.hpp
InputDisconnectionInfoView.cpp InputDisconnectionInfoView.hpp
StatusBar.cpp
)

# CPPurses is cloned into a directory named external/
add_subdirectory(external/CPPurses)
target_link_libraries(190.out cppurses)
add_compile_options(-Wextra -pedantic -Wall -std=c++17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
