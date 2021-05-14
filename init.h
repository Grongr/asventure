#ifndef INIT_H
#define INIT_H

#include "spaceship.h"
#include "pirateship.h"
#include <memory>

/*
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

/*
 * Creates a spaceship.
 */
 
auto InitSS()
{
	SpaceShipBuilder ssb;
	ssb.set_fuel_cost(1);
	ssb.set_is_engine_active(false);
	ssb.set_AVec(Vector(0, 0));
	ssb.set_R(Vector(150,150));
	ssb.set_V(Vector(0,0));
	ssb.set_mass(0);
	auto ship = ssb.make_spaceship(InitEFS());
	
	return std::move(ship);
}

/*
 * Creates a pirate ship
 */

auto InitPS()
{
    PirateShipBuilder psb;
    Vector vec1, vec2, vec3, vec4;
    vec1 = Vector(500, 500);
    vec2 = Vector(150, 320);
    vec3 = Vector(380, 270);
    vec4 = Vector(500, 500);
    std::list<Vector> List;
    List.push_back(vec1);
    List.push_back(vec2);
    List.push_back(vec3);
    List.push_back(vec4);

    psb.set_trajectory (List);
    psb.set_head_cost(10000);
    psb.set_V(Vector(0.1, 0.1));
    psb.set_R(Vector(0, 0));
	psb.set_fuel_cost(1);
	psb.set_is_engine_active(true);
	psb.set_AVec(Vector(0, 0));
    psb.set_mass(0);
    auto pirate_ship = psb.make_pirate_ship(InitEFS());

    return std::move(pirate_ship);
}

#endif //INIT_H


