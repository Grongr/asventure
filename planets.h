#ifndef PLATENS_HEADER_FILE
#define PLATENS_HEADER_FILE

#include "geometricvector.h"
#include "spaceship.h"
#include "sps_errors.h"

#include <exception>
#include <memory>

//-----------------------------------------------------------------------------------------------------------//
/*!
 * This class describes what is a planet in this game
 */
class Planet {

public:
    /*!
     * Constructor with all the params
     * @param radius - radius of this planet
     * @param mass   - mass of this planet
     * @param R      - radius vector to the center of this planet
     */
    Planet(double radius, double mass, Vector R) :
          radius{radius}, mass{mass}, R{R} {}

    /*!
     * If you wanna know radius
     * @return radius of this planet
     */
    [[nodiscard]] double get_radius() const;

    /*!
     * If you wanna know mass of this Planet
     * @return mass
     */
    [[nodiscard]] double get_mass() const;

    /*!
     * If you wanna know radius vector of this planet
     * @return R
     */
    [[nodiscard]] Vector get_R() const;

protected:
    double radius;
    double mass;
    Vector R;
};

//-----------------------------------------------------------------------------------------------------------//
/*!
 * This class describes a planet where player can buy resources
 */
class ShoppingPlanet : public Planet {
public:
    
    /*!
     * Constructor with all the params.
     * @param armor_upgrade_cost  -  credits ypu need to upgrade your armor
     * @param gun_upgrade_cost    -  credits you need to upgrade your ammo
     * @param battery_cost        -  credits you need to buy one battery
     * @prarm ammo_cost           -  credits you need to pay to buy a new ammo
     * @param fuel_cost           -  credits you need to buy one unit of fuel
     */
    ShoppingPlanet(double radius, double mass, Vector R,
                   int battery_cost, int fuel_cost, int gun_upgrade_cost,
                   int ammo_cost, int armor_upgrade_cost,
                   int upgrade_limit) :
        Planet{radius, mass, R}, battery_cost{battery_cost}, fuel_cost{fuel_cost},
        gun_upgrade_cost{gun_upgrade_cost}, ammo_cost{ammo_cost},
        armor_upgrade_cost{armor_upgrade_cost}, upgrade_limit{upgrade_limit} {}


    /*!
     * Wanna know hom much does it cost to upgrade your armor?
     * @return armor_upgrade_cost
     */
    [[nodiscard]] int get_armor_upgrade_cost() const;

    /*!
     * Wanna know hom much does it cost to upgrade your gun?
     * @return gun_upgrade_cost
     */
    [[nodiscard]] int get_gun_upgrade_cost() const;

    /*!
     * Wanna know hom much does it cost to buy a new battery?
     * @return battery_cost
     */
    [[nodiscard]] int get_battery_cost() const;

    /*!
     * Wanna know hom much does it cost to buy one unit of fuel?
     * @param fuel_cost
     */
    [[nodiscard]] int get_fuel_cost() const;

    /*!
     * Wanna know hom much does it cost to buy some ammo?
     * @return ammo_cost
     */
    [[nodiscard]] int get_ammo_cost() const;

    /*!
     * Wanna know your upgrade limit?
     * @return upgrade_limit
     */
    [[nodiscard]] int get_upgrade_limit() const;

protected:
    int battery_cost;
    int fuel_cost;
    int gun_upgrade_cost;
    int ammo_cost;
    int armor_upgrade_cost;
    int upgrade_limit;
};

//-----------------------------------------------------------------------------------------------------------//
class PlanetBuilder {
public:
    /*!
     * Constructor of a builder.
     * Params description could be seen in Planet class.
     */
    PlanetBuilder(double radius, double mass, Vector R) :
                  radius{radius}, mass{mass}, R{R}, count_of_params{3} {}

    /*!
     * Calls default constructor for all the params
     */
    PlanetBuilder() : radius{0}, mass{0}, R{Vector()} {}

    /*!
     * Set radius param
     */
    void set_radius(double radius);

    /*!
     * Set radius param
     */
    void set_mass(double mass);

    /*!
     * Set R param
     */
    void set_R(Vector R);

    /*!
     * Makes a shared ptr to a new planet object made from
     * this class params
     * @return shared_ptr to new planet object
     */
    [[nodiscard]] virtual std::shared_ptr<Planet> make_planet() {
        if (count_of_params != 3)
            throw std::exception();
        std::shared_ptr<Planet> plt(new Planet(radius, mass, R));
        return plt;
    }

protected:
       int count_of_params;
    double radius;
    double mass;
    Vector R;
};
//-----------------------------------------------------------------------------------------------------------//
class ShoppingPlanetBuilder : public PlanetBuilder {

    /*!
     * No params constructor. Sets all params as zero.
     */
    ShoppingPlanetBuilder() :
        PlanetBuilder(), armor_upgrade_cost{0}, gun_upgrade_cost{0},
        battery_cost{0}, fuel_cost{0}, ammo_cost{0}, upgrade_limit{0} {}

    /*!
     * Sets armor_upgrade_cost param
     */
    void set_armor_upgrade_cost(int auc);

    /*!
     * Sets gun_upgrade_cost param
     */
    void set_gun_upgrade_cost(int guc);

    /*!
     * Sets battery_cost param
     */
    void set_battery_cost(int batc);

    /*!
     * Sets fuel_cost param
     */
    void set_fuel_cost(int fc);

    /*!
     * Sets ammo_cost param
     */
    void set_ammo_cost(int ac);
    
    /*!
     * Sets upgrade_limit param
     */
    void set_upgrade_limit(int upglim);

    /*!
     * Maeks shared ptr to a new planet object
     * made from this class params
     * @return shared_ptr to a new planet object
     */
    [[nodiscard]] virtual std::shared_ptr<ShoppingPlanet> make_shoppingplanet() {
        if (count_of_params != 6)
            throw ShoppingPlanetBParamCountError("Count of set params is not 6");
        std::shared_ptr<ShoppingPlanet> shplt(new ShoppingPlanet(radius, mass, R, battery_cost, fuel_cost, gun_upgrade_cost, ammo_cost, armor_upgrade_cost, upgrade_limit));
        return shplt;
    }

private:
    int armor_upgrade_cost;
    int gun_upgrade_cost;
    int battery_cost;
    int fuel_cost;
    int ammo_cost;
    int upgrade_limit;
};

#endif // PLATENS_HEADER_FILE
