cmake_minimum_required(VERSION 3.16)

project(main)

set(CMAKE_CXX_STANDARD 20)

add_executable(main Main.cpp spaceship.h unitests.h spaceship.cpp unitests.cpp Drawing.cpp Drawing.h InitShip.h Interface.cpp Interface.h)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

#include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(main sfml-graphics sfml-window sfml-system sfml-audio)
