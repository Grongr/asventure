#ifndef INIT_H
#define INIT_H

#include "spaceship.h"
#include "pirateship.h"
#include <memory>

/*!
 * Creates Energy Fuel System
 * to build a spaceship.
 */
EnergyFuelSystemBuilder InitEFS();

/*!
 * Creates a spaceship.
 */
std::shared_ptr<SpaceShip> InitSS();

/*!
 * Creates a pirate ship
 */
std::shared_ptr<PirateShip> InitPS();

#endif //INIT_H


