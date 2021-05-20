#ifndef DRAWSHIP_H
#define DRAWSHIP_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "spaceship.h"
#include "pirateship.h"
#include "geometricvector.h"
#include "init.h"

/*
 * This class contains funcs to draw SpaceShip.
 * It stores ptr on the ship and params for 
 * ship's sprite
 */

class DrawShip
{
    private:
        std::shared_ptr<SpaceShip> ship;
        sf::FloatRect rect;
    public:
        /*
         * Builds SpaceShip, sets params for rect
         */
        DrawShip();
        
        /*
         * Plantango
         */
        virtual ~DrawShip() = default;
    
        /*
         * Changes location of spaceship in time
         */
        void MoveShip(double time);
        
        /*
         * Returns ptr on ship
         */
        std::shared_ptr<SpaceShip> GetShip();

        /*
         * Returns rect params
         */
        sf::FloatRect GetRect();
};

/*
 * This class contains funcs to draw PirateShip.
 * It stores ptr on the pirate ship and params
 * for it's sprite
 */

class DrawPirateShip: public DrawShip
{
    private:
        std::shared_ptr<PirateShip> pirate_ship;
        sf::FloatRect rect;
    public:
        /*
         * Builds PirateShip, sets params for rect
         */
        DrawPirateShip();
        DrawPirateShip(std::list<Vector> trajectory, int head_cost, Vector velocity, Vector radius_vector);
        
        /*
         * Changes location of pirate ship in time.
         * Constant is neede due to move_ship_forward
         * implementation (look in pirateship.cpp)
         */
        void MoveShip(double time, double constant);
        
        /*
         * Returns ptr to pirate ship
         */
        std::shared_ptr<PirateShip> GetShip();
        
        /*
         * Returns rect params
         */
        sf::FloatRect GetRect();
};

#endif //DRAWSHIP_H
