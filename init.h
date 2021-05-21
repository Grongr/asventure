#ifndef INIT_H
#define INIT_H


#include <memory>

#include "spaceship.h"
#include "pirateship.h"
#include "geometricvector.h"
#include "character.h"
#include "policeship.h"

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

/*!
 * Creates a character
 */
 std::shared_ptr<Character> InitCH(int ac, int armor, int damage, int money, int bfg, int hp);

 /*!
  * Creates a policeship
  */
  std::shared_ptr<PoliceShip> InitPL(Vector cc, double r, double aV);


#endif //INIT_H
