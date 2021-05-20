#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "interface.h"
#include "spaceship.h"

/*
 * Params also will be mutable in the future
 * when there will be any boosters.
 */
void Interface::QwertyInter(std::shared_ptr<SpaceShip> ship)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
        ship->set_velocity(Vector(-0.1, 0) + (ship->get_velocity()));
    }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		ship->set_velocity(Vector(0.1, 0) + (ship->get_velocity()));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		ship->set_velocity(Vector(0, -0.1) + (ship->get_velocity()));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		ship->set_velocity(Vector(0, 0.1) + (ship->get_velocity()));
    }
}
