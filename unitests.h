//
// Created by grongr on 2/20/21.
//

#ifndef SPACESHIP_UNITESTS_H
#define SPACESHIP_UNITESTS_H

#include "spaceship.h"
#include "pirateship.h"

#include <iostream>

/*!
 * Function that checks if test passed and writes if not
 * @param test_num  number of test
 * @param R0        resulting radius vector
 * @param R         correct resulting vector
 * @return          true if test is passed and false if not
 */
bool sps_move_check_unit_test(int test_num, Vector const& R0, Vector const& R);

/*!
 * Testing move_ship() func of SpaceShip class
 */
void sps_move_unit_test();

/*!
 * Checks if unit test is passed correctly
 * @param tn
 * @param time
 * @param RRes
 * @return
 */
bool pirate_ship_move_check_unit_test(int tn, double time, Vector const& RRes);

/*!
 * Sets params of pbl to default value
 * @param pbl
 */
void make_default_psh(PirateShipBuilder& pbl);

/*!
 * Testing move_ship() func of PirateShip class
 */
void pirate_ship_move_unit_test();

#endif //SPACESHIP_UNITESTS_H
