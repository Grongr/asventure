#include <memory>

#include "init.h"
#include "pirateship.h"
#include "spaceship.h"

EnergyFuelSystemBuilder InitEFS() {
    EnergyFuelSystemBuilder efsb;
	efsb.set_size_of_bat_arr(50);
	efsb.set_bat_energy(100);
	efsb.set_fmv(10000);
	efsb.set_fu(1);
	efsb.set_fQ(1);
	
	return efsb;
}

std::shared_ptr<SpaceShip> InitSS() {
	SpaceShipBuilder ssb;
	ssb.set_fuel_cost(1);
	ssb.set_is_engine_active(false);
	ssb.set_AVec(Vector(0, 0));
	ssb.set_R(Vector(2520,1575));
	ssb.set_V(Vector(0,0));
	ssb.set_mass(0);
	auto ship = ssb.make_spaceship(InitEFS());
	
    return std::move(ship);
}

std::shared_ptr<PirateShip> InitPS(std::list<Vector> trajectory, int head_cost, Vector velocity, Vector radius_vector) {
    PirateShipBuilder psb;
    psb.set_trajectory (trajectory);
    psb.set_head_cost(head_cost);
    psb.set_V(velocity);
    psb.set_R(radius_vector);
	psb.set_fuel_cost(1);
	psb.set_is_engine_active(true);
	psb.set_AVec(Vector(0, 0));
    psb.set_mass(0);
    auto pirate_ship = psb.make_pirate_ship(InitEFS());

    return std::move(pirate_ship);
}

std::shared_ptr<Character> InitCH(int ac, int armor, int damage, int money, int bfg, int hp) {
    CharacterBuilder chb;
    chb.set_ammo_count(ac);
    chb.set_armor(armor);
    chb.set_damage(damage);
    chb.set_money(money);
    chb.set_BFG(bfg);
    chb.set_hp(hp);
    auto character = chb.make_char();

    return std::move(character);
}
