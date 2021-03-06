#ifndef POLICESHIP_ASVENTURE
#define POLICESHIP_ASVENTURE

#include "geometricvector.h"
#include "pirateship.h"
#include "spaceship.h"
#include "sps_errors.h"

#include <memory>

//-----------------------------------------------------------------------------------------------------------//
class PoliceShip : public SpaceShip {
public:
    /*!
     * Constructor with default params
     */
    PoliceShip(EnergyFuelSystemBuilder const &builder, double mass, double fuel_cost,
               Vector R, Vector V, Vector a_vec, Vector center_coords, double radius_coords, double angV)
        : SpaceShip(builder, mass, fuel_cost, R, V, a_vec), 
          center_coords{center_coords}, radius{radius_coords}, angV{angV} {}

    /*!
     * Moves police ship along a circli trajectory
     * @param time  time of moving
     */
    void move_along_circle(double time);

private:
    /*!
     * @param center_coords Center coords is radius vector of where the circle trajectory centre is
     * @param radius Radius of a trajectory circle
     * @param angV   angle velocity of police ship should be bigger then zero
     */
    Vector center_coords;
    double angV;
    double radius;
};
//-----------------------------------------------------------------------------------------------------------//
class PoliceShipBuilder : public SpaceShipBuilder {
public:
    PoliceShipBuilder() : SpaceShipBuilder(),
                          center_coords{}, radius{0} {}

    /*!
     * Sets the coords of center of future trajectory of police ship
     * @param cc  radius vector of a center
     */
    void set_center_coords(Vector const& cc) { center_coords = cc; ++count_of_params; }

    /*!
     * Sets the radius of future trajectory of police ship
     * @param radius  real radius of future trajectory
     */
    void set_radius(double radius) { this->radius = radius; ++count_of_params; }

    void set_angV(double angV) { this->angV = angV; ++count_of_params; }

    /*!
     * Function which os made to be creator of your own pirateship class object :)
     * @param efs  builder of energy fuel system of future  ship
     * @return pointer to created ship
     */
    std::shared_ptr<PoliceShip> make_police_ship(EnergyFuelSystemBuilder const& efs) {
        if (count_of_params != 9)
            throw PoliceShipBParamCountError("Count of params of police ship builder is not 9");
        std::shared_ptr<PoliceShip> polsh(new PoliceShip(efs, mass, fuel_cost, R,
                                    V, AVec, center_coords, radius, angV));
        return polsh;
    }

private:
    Vector center_coords;
    double angV;
    double radius;
};

#endif // POLICESHIP_ASVENTURE
