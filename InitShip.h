#ifndef INITSHIP_H
#define INITSHIP_H

#include "spaceship.h"
/*!
 * Creates Energy Fuel System
 * to build a spaceship.
 */
 
EnergyFuelSystemBuilder InitEFS()
{
    EnergyFuelSystemBuilder efsb;
	efsb.set_size_of_bat_arr(50);
	efsb.set_bat_energy(100);
	efsb.set_fmv(10000);
	efsb.set_fu(1);
	efsb.set_fQ(1);
	
	return efsb;
}

/*!
 * Creates a spaceship.
 */
 
auto* InitSSB()
{
	SpaceShipBuilder ssb;
	ssb.set_fuel_cost(1);
	ssb.set_is_engine_active(false);
	ssb.set_AVec(Vector(0, 0));
	ssb.set_R(Vector(0,0));
	ssb.set_V(Vector(0,0));
	ssb.set_mass(0);
	auto* ship = ssb.make_spaceship(InitEFS());
	
	return ship;
}

#endif //INITSHIP
