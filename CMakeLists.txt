cmake_minimum_required(VERSION 3.16)

project(main)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp spaceship.h unitests.h spaceship.cpp unitests.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

#include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(main sfml-graphics sfml-window sfml-system sfml-audio)
