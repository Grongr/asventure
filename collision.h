#ifndef COLLISION_H
#define COLLISION_H

#include "geometricvector.h"
#include "spaceship.h"
#include "pirateship.h"
#include "quests.h"
#include "collision.h"

/*
 * Communication with pirate ships
 */

void Collision(std::shared_ptr<SpaceShip> ship, std::shared_ptr<PirateShip> pirate, Quest* quest)
{
	
    if ((ship->get_position().x_pos() - pirate->get_position().x_pos()) < 20 && (ship->get_position().y_pos() - pirate->get_position().y_pos()) < 20 && !(quest->is_active()))
    {
        sf::RenderWindow window (sf::VideoMode(800, 800), "dialog_with_pirate");
        
        while (window.isOpen())
        {
        	sf::Event event;
        	while (window.pollEvent(event))
        	{
        		if (event.type == sf::Event::Closed)
        		{
        			window.close();
        			quest->make_active();
        		}
			}
		
		window.clear();
		window.display();
    	}
    }
}

#endif // COLLISION_H