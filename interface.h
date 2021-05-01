#ifndef INTERFACE_H
#define INTERFACE_H

#include "spaceship.h"

/*
 * User interaction
 */

class Interface
{
    public:
        void QwertyInter(std::shared_ptr<SpaceShip> ship);
};

#endif // INTERFACE_H
