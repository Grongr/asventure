#include "doublecmp.h"
#include "pirateship.h"
#include "policeship.h"
#include "spaceship.h"
#include "unitests.h"

#include <iostream>

int main() {
    sps_move_unit_test();
    pirate_ship_move_unit_test();
    police_ship_move_unit_test();
    return 0;
}
