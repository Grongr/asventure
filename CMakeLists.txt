cmake_minimum_required(VERSION 3.16)
project(asvergin)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp spaceship.h spaceship.cpp
                    unitests unitests.cpp
                    sps_errors.h
                    geometricvector.h geometricvector.cpp
                    pirateship.cpp pirateship.h
                    doublecmp.h doublecmp.cpp)