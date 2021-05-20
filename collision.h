#ifndef COLLISION_H
#define COLLISION_H

#include "geometricvector.h"
#include "spaceship.h"
#include "pirateship.h"
#include "quests.h"
#include <array>
#include "drawship.h"
#include "dialogue.h"

/*
 * Communication with pirate ships
 */

void Collision(std::shared_ptr<SpaceShip> ship, std::array<DrawPirateShip, 9> pirates, Quest* quest)
{
    for (int i = 0; i < 9; i++)
    {
        if ((ship->get_position().x_pos() - pirates[i].GetShip()->get_position().x_pos()) < 20 && (ship->get_position().y_pos() - pirates[i].GetShip()->get_position().y_pos()) < 20 && !(quest->is_active()))
        {
            sf::RenderWindow window (sf::VideoMode(1221, 725), "dialog_with_pirate");
            sf::Texture dialogue;
            dialogue.loadFromFile("../images/diag/win.png");
            sf::Sprite win(dialogue); 
            win.setPosition(0, 0);
            
            Dialogue dia;

            sf::Font font;
            font.loadFromFile("18839.otf");
            
            sf::Text text1;
            text1.setFont(font);
            text1.setString("Beginning");
            text1.setPosition(1000, 50);

            sf::Text text2;
            text2.setFont(font);
            text2.setString("About me");

            sf::Text text3;
            text3.setFont(font);
            text3.setString("Attack");

            sf::Text text4;
            text4.setFont(font);
            text4.setString("Goodbye");


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
            window.draw(win);
            window.draw(text1);
		    window.display();
    	    }
        }
    }

/* 
 * Communication with map borders
 */    
    if (ship->get_position().x_pos() < 0 || ship->get_position().y_pos() < 0 || ship->get_position().x_pos() > 5000 || ship->get_position().y_pos() > 3100)
    {
        ship->set_velocity(ship->get_velocity() * (-1));
    }
}

#endif // COLLISION_H
