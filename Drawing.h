#ifndef DRAWSHIP_H
#define DRAWSHIP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "spaceship.h"

/*!
 * Now it's drawing rectangle,
 * later there will be textures.
 */

class DrawShip
{
    private:
        SpaceShip* ship;
        sf::FloatRect rect;
    public:
        DrawShip();
        ~DrawShip();
        void MoveShip(double time);
        SpaceShip* GetShip();
        sf::FloatRect GetRect();
};

#endif //DRAWSHIP_H
