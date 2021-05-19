cmake_minimum_required(VERSION 3.16)
project(asvergin)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp 
                    spaceship.h spaceship.cpp
                    unitests.h unitests.cpp
                    sps_errors.h
                    geometricvector.h geometricvector.cpp
                    pirateship.h pirateship.cpp
                    policeship.h policeship.cpp
                    init.h init.cpp
                    doublecmp.h doublecmp.cpp
                    drawship.h drawship.cpp
                    interface.h interface.cpp
                    menu.h view.h background.h
                    pirates.h pirates.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

target_link_libraries(main sfml-graphics sfml-window sfml-system sfml-audio)
