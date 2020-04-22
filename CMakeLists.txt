cmake_minimum_required(VERSION 3.0.0)
project(190 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(190.out main.cpp Serial.cpp)

# CPPurses is cloned into a directory named external/
add_subdirectory(CPPurses)
target_link_libraries(190.out cppurses)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
