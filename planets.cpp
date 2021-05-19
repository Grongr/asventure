#include "planets.h"

//---------------------------------------------------Planet---------------------------------------------------//

[[nodiscard]] double Planet::get_radius() const { return this->radius; }

[[nodiscard]] double Planet::get_mass()   const { return this->mass; }

[[nodiscard]] Vector Planet::get_R()      const { return this->R; }

//-----------------------------------------------ShoppingPlanet----------------------------------------------//

[[nodiscard]] int ShoppingPlanet::get_armor_upgrade_cost() const { return this->armor_upgrade_cost; }

[[nodiscard]] int ShoppingPlanet::get_gun_upgrade_cost()   const { return this->gun_upgrade_cost; }

[[nodiscard]] int ShoppingPlanet::get_upgrade_limit()      const { return this->upgrade_limit; }

[[nodiscard]] int ShoppingPlanet::get_battery_cost()       const { return this->battery_cost; }

[[nodiscard]] int ShoppingPlanet::get_fuel_cost()          const { return this->fuel_cost; }

[[nodiscard]] int ShoppingPlanet::get_ammo_cost()          const { return this->ammo_cost; }

//-----------------------------------------------PlanetBuilder-----------------------------------------------//

void PlanetBuilder::set_radius(double radius) { this->radius = radius; ++count_of_params; }

void PlanetBuilder::set_mass(double mass)     { this->mass = mass; ++count_of_params; }

void PlanetBuilder::set_R(Vector R)           { this->R = R; ++count_of_params; }

//-------------------------------------------ShoppingPlanetBuilder-------------------------------------------//

void ShoppingPlanetBuilder::set_armor_upgrade_cost(int auc) { this->armor_upgrade_cost = auc; ++count_of_params; }

void ShoppingPlanetBuilder::set_upgrade_limit(int upglim)   { this->upgrade_limit = upglim; ++count_of_params; }

void ShoppingPlanetBuilder::set_gun_upgrade_cost(int guc)   { this->gun_upgrade_cost = guc; ++count_of_params; }

void ShoppingPlanetBuilder::set_battery_cost(int batc)      { this->battery_cost = batc; ++count_of_params; }

void ShoppingPlanetBuilder::set_fuel_cost(int fc)           { this->fuel_cost = fc; ++count_of_params; }

void ShoppingPlanetBuilder::set_ammo_cost(int ac)           { this->ammo_cost = ac; ++count_of_params; }
    
//-----------------------------------------------------------------------------------------------------------//
