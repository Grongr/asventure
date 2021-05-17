//
// Created by grongr on 4/23/21.
//

#ifndef ASVERGIN_PIRATESHIP_H
#define ASVERGIN_PIRATESHIP_H

#include "spaceship.h"
#include "sps_errors.h"

#include <iostream>
#include <memory>
#include <string>
#include <list>

//-----------------------------------------------------------------------------------------------------------//
class PirateShip : public SpaceShip {
public:

    /*!
     * Constructor with some initialisation
     * @param builder   - special builder for fuel system
     * @param mass      - mass of spaceship
     * @param fuel_cost - how many fuel it takes to move
     * @param R         - start location
     * @param V         - start velocity
     */
    PirateShip(EnergyFuelSystemBuilder const &builder, double mass, double fuel_cost,
               Vector R, Vector V, Vector a_vec, std::list<Vector>& tr, int head_cost)
               : SpaceShip(builder, mass, fuel_cost,
                           R, V, a_vec), trajectory{std::move(tr)}, head_cost(head_cost)
                           { is_engine_active = true; }

    /*!
     * Moves pirate's spaceship for "time" time
     * It moves down the line between to neighbour points
     * from trajectory. If no points left flies in reversed order
     * till the firs point is reached
     * @param time         time of moving
     * @param speed_const  this is a real number
     *                     on which the velocity is multiplied
     */
    void move_ship_forward(double time, double speed_const = 1.0);

    /*!
     * To know from where to start the movement
     * @return begin iterator of trajectory
     */
    std::list<Vector>::iterator begin() { return trajectory.begin(); }

#ifdef DEBUG
    void print_trajectory() const {
        for (const auto& i : trajectory)
            std::cout << "{ " << i.x_pos() << " " << i.y_pos() << " }, ";
        std::cout << std::endl;
    }
#endif // DEBUG

    //! Iterator to point in trajectory to which ship is moving right now
    std::list<Vector>::iterator it;
private:
    /*!
     * @param trajectory array of coords between which spaceship travels ( it should not be changed )
     * @param head_cost  how much money can ypu earn from killing this ship
     */
    std::list<Vector> trajectory{};
    int head_cost{0};
};

//-----------------------------------------------------------------------------------------------------------//
class PirateShipBuilder : public SpaceShipBuilder {
public:

    /*!
     * Func to set trajectory list all in one string
     * @param tr
     */
    void set_trajectory(std::list<Vector> const & tr) {
        trajectory = tr;
        if (!is_tr_given) {
            ++count_of_params;
            is_tr_given = true;
        }
    }

    /*!
     * Func to add one more point to trajectory
     * @param vec
     */
    void add_point(Vector const& vec) {
        trajectory.push_back(vec);
        if (!is_tr_given) {
            ++count_of_params;
            is_tr_given = true;
        }
    }

    /*!
     * Sets head cost from given param
     * @param head_cost  needed head cost
     */
    void set_head_cost(int head_cost) { head_cost = head_cost; ++count_of_params; }

    /*!
     * The first point of the way of pirate spaceship is R vector
     */
    void set_R(Vector const& R) override {
        this->R = R; trajectory.push_front(R);
        ++count_of_params;
    }

    /*!
     * Makes Pirate Spaceship from given params and EFSBuilder object.
     * @param efs  EFSBuilder object
     * @return     pointer to created PirateShip object
     */
    [[nodiscard]] std::unique_ptr<PirateShip> make_pirate_ship(EnergyFuelSystemBuilder const& efs) {
        if (count_of_params != 8)
            throw PirateShipBParamCountError("Count of params of pirate ship builder is not 8");
        std::unique_ptr<PirateShip> psh(new PirateShip(efs, mass, fuel_cost, R,
                                   V, AVec, trajectory, head_cost));
        psh->it = (++psh->begin());
        return psh;
    }

protected:
    bool is_tr_given{false};           // is trajectory given or not?
    std::list<Vector> trajectory{};
    int head_cost{0};
};

#endif //ASVERGIN_PIRATESHIP_H
