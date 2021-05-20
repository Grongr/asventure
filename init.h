#ifndef INIT_H
#define INIT_H


#include <memory>

#include "spaceship.h"
#include "pirateship.h"
#include "geometricvector.h"

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
std::shared_ptr<PirateShip> InitPS(std::list<Vector> trajectory, int head_cost, Vector velocity, Vector radius_vector);

#endif //INIT_H
