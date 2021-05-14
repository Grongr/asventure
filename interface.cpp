#include "interface.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "spaceship.h"

/*
 * Params also will be mutable in the future
 * when there will be any boosters.
 */
 
void Interface::QwertyInter(std::shared_ptr<SpaceShip> ship)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			ship->set_velocity(Vector(-0.1, 0) + (ship->get_velocity()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ship->set_velocity(Vector(0.1, 0) + (ship->get_velocity()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ship->set_velocity(Vector(0, -0.1) + (ship->get_velocity()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			ship->set_velocity(Vector(0, 0.1) + (ship->get_velocity()));
        }
}
