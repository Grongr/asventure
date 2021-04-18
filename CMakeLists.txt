cmake_minimum_required(VERSION 3.16)
project(asvergin)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp spaceship.h unitests.h spaceship.cpp unitests.cpp)