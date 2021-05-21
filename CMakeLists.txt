cmake_minimum_required(VERSION 3.16)
project(asvergin)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-O2)

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
                    planets.h planets.cpp
                    pirates.h pirates.cpp
                    character.h character.cpp
                    menu.h view.h background.h
                    drawstats.h drawstats.cpp
                    dialogue.h dialogue.cpp
                    police.h police.cpp
                    fight.h fight.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

target_link_libraries(main sfml-graphics sfml-window sfml-system sfml-audio)
