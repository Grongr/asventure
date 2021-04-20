//
// Created by grongr on 2/11/21.
//

#include <iostream>
#include <algorithm>
#include "spaceship.h"

//-----------------------------------------------------------------------------------------------------------//
Vector Vector::operator+(Vector const& r) const {
    return Vector(this->x + r.x, this->y + r.y);
}

Vector Vector::operator-(Vector const& r) const {
    return Vector(this->x - r.x, this->y - r.y)
}

Vector Vector::operator*(double value) const {
    return Vector(this->x * value, this->y * value);
}

void Vector::normalise() {
    if (this->x != 0)
        this->x /= this->x;
    if (this->y != 0)
        this->y /= this->y;
}

bool Vector::operator!=(Vector const &r) const {
    if (this->x == r.x && this->y == r.y)
        return false;
    else
        return true;
}

void Vector::print_vector() const {
    std::cout << this->x << " " << this->y << std::endl;
}

//-----------------------------------------------------------------------------------------------------------//
void SpaceShip::move_ship(double time) {
    if (this->is_engine_active) {
        double needed_fuel = time * fuel_cost;

        double used_fuel = this->efs.use_some_fuel(needed_fuel);

        if (used_fuel < needed_fuel)
            this->toggle_engine();

        double time_of_moving_with_ac = used_fuel / this->fuel_cost;

        R = R + V * time_of_moving_with_ac +
            AVec * (time_of_moving_with_ac * time_of_moving_with_ac / 2.0);

        V = V + AVec * time_of_moving_with_ac;

        R = R + V * (time - time_of_moving_with_ac);
    } else {
        R = R + (V * time);
    }
}

bool SpaceShip::toggle_engine() {
    is_engine_active = !is_engine_active;
    return is_engine_active;
}

//-----------------------------------------------------------------------------------------------------------//
double Battery::use_battery(double energy) {
    if (energy <= 0)
        return 0;

    if (energy >= this->contain_energy) {
        this->contain_energy = 0;
        return energy;
    }
    this->contain_energy -= energy;
    return energy;
}

//-----------------------------------------------------------------------------------------------------------//
double FuelTank::get_some_fuel(double f) {
    if (f == 0 || contain_v == 0)                       // We cannot give that amount of fuel
        return 0;

    f = fmin(f, contain_v);                             // Maximum which we can give

    if (f < Q) {                                        // We only need one Q to give all we can or need
        contain_v -= f;
        return u;
    } else if ((int)(f / Q) == f / Q) {                 // If f contains an integer number of Q
        contain_v -= f;
        return (u * (int)(f / Q));
    } else {                                            // If not integer number of Q'es
        int count = (int) (f / Q) + 1;
        if (count * Q > contain_v) {                        // 1. When we need more then can give
            contain_v = 0;
            return u * count;
        } else {                                            // 2. When all is ok and none will be blamed
            contain_v -= count * Q;                         //    for greed
            return u * count;
        }
    }
}

double FuelTank::energy_cost(double f) const {
    if (f == 0 || contain_v == 0)                       // We cannot give that amount of fuel
        return 0;

    f = fmin(f, contain_v);                             // Maximum which we can give

    if (f < Q) {                                        // We only need one Q to give all we can or need
        return u;
    } else if ((int)(f / Q) == f / Q) {                 // If f contains an integer number of Q
        return (u * (int)(f / Q));
    } else {                                            // If not integer number of Q'es
        int count = (int) (f / Q) + 1;
        return u * count;
    }
}

double FuelTank::max_amount_of_fuel_to_give(double energy) const {
    int count = (int) (energy / this->u);               // How many times we can give Q amount of fuel

    return fmin(count * Q, this->contain_v);         // max or min ???
}
//-----------------------------------------------------------------------------------------------------------//
bool EnergyFuelSystem::have_enough_resources(double fuel) {
    double needed_energy = this->tank.energy_cost(fuel);

    if (needed_energy > this->full_energy)
        return false;

    if (fuel > this->get_fuel())
        return false;

    return true;
}

double EnergyFuelSystem::use_some_fuel(double fuel) {
    fuel = fmin(this->tank.max_amount_of_fuel_to_give(this->full_energy), fuel);

    double used_energy = this->tank.get_some_fuel(fuel);

    this->full_energy -= used_energy;

    size_t i = this->bat.size() - 1;

    while (used_energy > 0 && i >= 0) {
        used_energy -= bat[i].use_battery(used_energy);
        --i;
    }
    return fuel;
}
//-----------------------------------------------------------------------------------------------------------//
void PirateShip::move_ship(double time) {
    static double time_of_moving = 0;
    static auto it = trajectory.begin();

    double needed_time = 0;

    auto time_count = [&needed_time, this]
                      (std::vector<Vector>::iterator it) {
        time_of_moving = 0;
        this->V = *(++it) - *it;
        needed_time = this->V.length();
        this->V.normalise();
        needed_time /= this->V.length();
    };

    if (time_of_moving == 0)
        time_count(it);

    if (it != trajectory.end() - 1) {
        if (time_of_moving + time > needed_time) {                              // If you need to change
            ++it;                                                               // destination in the middle
            this->R = this->R + this->V * (needed_time - time_of_moving);   // deltaR before changing
            time -= needed_time - time_of_moving;
            time_count(it);                                                 // count new needed time
            this->R = this->R + this->V * time;                             // deltaR after changing
            time_of_moving += time;
        } else {                                                                // If you go straight
            this->R = this->R + this->V * time;
            time_of_moving += time;
        }
    } else {                                                                    // Repeat all the movings in
        std::reverse(trajectory.begin(), trajectory.end());            // reversed order to not stopping
        it = trajectory.begin();
    }
}