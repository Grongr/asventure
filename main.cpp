#include "doublecmp.h"
#include "pirateship.h"
#include "policeship.h"
#include "spaceship.h"
#include "unitests.h"

#include <iostream>

int main() {
    sps_move_unit_test();
    std::cout << std::endl;
    pirate_ship_move_unit_test();
    std::cout << std::endl;
    police_ship_move_unit_test();
    std::cout << std::endl;
    std::cout << "Size of SpaceShip class:  " << sizeof(SpaceShip) << std::endl;
    std::cout << "Size of PoliceShip class: " << sizeof(PoliceShip) << std::endl;
    std::cout << "Size of PirateShip class: " << sizeof(PirateShip) << std::endl;
    std::cout << "That's why we have to control things like count of ships in memory :(" << std::endl;
    return 0;
}
