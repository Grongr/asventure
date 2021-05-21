//
// Created by grongr on 2/20/21.
//

#ifndef SPACESHIP_UNITESTS_H
#define SPACESHIP_UNITESTS_H

#include "spaceship.h"
#include "pirateship.h"
#include "policeship.h"

#include <iostream>

/*!
 * Function that checks if test passed and writes if not
 * @param test_num  number of test
 * @param R0        resulting radius vector
 * @param R         correct resulting vector
 * @return          true if test is passed and false if not
 */
bool check_unit_test(int test_num, Vector const& R0, Vector const& R);

/*!
 * Testing move_ship() func of SpaceShip class
 */
void sps_move_unit_test();

/*!
 * Checks if unit test is passed correctly
 * @param tn    test number
 * @param R     result radius vector
 * @param RRes  correct result radius vector
 * @return      true if R == RRes and false if not
 */
bool pirate_ship_move_check_unit_test(int tn, Vector const& R, Vector const& RRes);

/*!
 * Sets params of pbl to default value
 * @param pbl
 */
void make_default_psh(PirateShipBuilder& pbl);

/*!
 * Testing move_ship() func of PirateShip class
 */
void pirate_ship_move_unit_test();

/*!
 * Sets default params to pirateship builder
 */
void make_standart_police_ship(PoliceShipBuilder& builder);

/*!
 * Tests policeship method move_along_circle
 */
void police_ship_move_unit_test();

/*!
 * Tests character's combat methods.
 */
void character_method_unit_test();

/*!
 * Tests for dialogue shit
 */
void dio_test();

#endif //SPACESHIP_UNITESTS_H
