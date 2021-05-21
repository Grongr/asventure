#ifndef COLLISION_H
#define COLLISION_H

#include "geometricvector.h"
#include "spaceship.h"
#include "pirateship.h"
#include "quests.h"
#include <array>
#include "drawship.h"
#include "dialogue.h"
#include "fight.h"
#include "police.h"

/*
 * Communication with pirate ships
 */

void Collision(std::shared_ptr<SpaceShip> ship, std::array<DrawPirateShip, 9> pirates, Police police, Quest* quest, DrawStats ds, Camera& camera)
{
    for (int i = 0; i < 9; i++)
    {
        if (std::abs(ship->get_position().x_pos() - pirates[i].GetShip()->get_position().x_pos()) < 20 && std::abs(ship->get_position().y_pos() - pirates[i].GetShip()->get_position().y_pos()) < 20)
        {
            sf::RenderWindow window (sf::VideoMode(1221, 725), "dialog_with_pirate");
            sf::Texture dialogue;
            dialogue.loadFromFile("../images/diag/win.png");
            sf::Sprite win(dialogue); 
            win.setPosition(0, 0);
            
            Dialogue dia(Dialogue::find_file("pirate", 0));

            sf::Font font;
            font.loadFromFile("../images/font/18839.otf");
            
            sf::Text text1;
            text1.setString("Beginning");
            text1.setFont(font);
            text1.setCharacterSize(50);
            text1.setFillColor(sf::Color::Yellow);
            text1.setPosition(930, 50);

            sf::Text text2;
            text2.setString("About me");
            text2.setFont(font);
            text2.setCharacterSize(50);
            text2.setFillColor(sf::Color::Yellow);
            text2.setPosition(930, 150);

            sf::Text text3;
            text3.setFont(font);
            text3.setString("Attack");
            text3.setCharacterSize(50);
            text3.setFillColor(sf::Color::Yellow);
            text3.setPosition(930, 250);

            sf::Text text4;
            text4.setFont(font);
            text4.setString("Goodbye");
            text4.setCharacterSize(50);
            text4.setFillColor(sf::Color::Yellow);
            text4.setPosition(930, 350);

            string str = "";
            int num = 0;
            bool agr = false;

            while (window.isOpen())
            {
                text1.setFillColor(sf::Color::Yellow);
                text2.setFillColor(sf::Color::Yellow);
                text3.setFillColor(sf::Color::Yellow);
                text4.setFillColor(sf::Color::Yellow);

        	    sf::Event event;
        	    while (window.pollEvent(event))
        	    {
        		    if (event.type == sf::Event::Closed)
        		    {
        			    window.close();
        		    }
			    }
                if (sf::IntRect(930, 50, text1.getGlobalBounds().width, text1.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text1.setFillColor(sf::Color::Red);
                    str = "Beginning";
                    num = 1;
                }

                if (sf::IntRect(930, 150, text2.getGlobalBounds().width, text2.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text2.setFillColor(sf::Color::Red);
                    str = "About me";
                    num = 2;
                }

                if (sf::IntRect(930, 250, text3.getGlobalBounds().width, text3.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text3.setFillColor(sf::Color::Red);
                    str = "Attack";
                    num = 3;
                }

                if (sf::IntRect(930, 350, text4.getGlobalBounds().width, text4.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text4.setFillColor(sf::Color::Red);
                    str = "Goodbye";
                    num = 4;
                }
            
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (num == 1)
                    {
                        sf::Text outcome1;
                        outcome1.setFont(font);
                        outcome1.setString(dia.variants[str]);
                        outcome1.setCharacterSize(40);
                        outcome1.setFillColor(sf::Color::Yellow);
                        outcome1.setPosition(50, 50);
                        window.draw(outcome1);
                    }
                    else if (num == 2)
                    {
                        sf::Text outcome2;
                        outcome2.setFont(font);
                        outcome2.setString(dia.variants[str]);
                        outcome2.setCharacterSize(35);
                        outcome2.setFillColor(sf::Color::Yellow);
                        outcome2.setPosition(50, 150);
                        window.draw(outcome2);
                    }
                    else if (num == 3)
                    {
                        sf::Text outcome3;
                        outcome3.setFont(font);
                        outcome3.setString(dia.variants[str]);
                        outcome3.setCharacterSize(40);
                        outcome3.setFillColor(sf::Color::Yellow);
                        outcome3.setPosition(50, 350);
                        window.draw(outcome3);
                        agr = true;
                    }
                    else if (num == 4)
                    {
                        sf::Text outcome4;
                        outcome4.setFont(font);
                        outcome4.setString(dia.variants[str]);
                        outcome4.setCharacterSize(40);
                        outcome4.setFillColor(sf::Color::Yellow);
                        outcome4.setPosition(50, 450);
                        window.draw(outcome4);
                    }

                }
		
		        //window.clear();
                window.draw(win);
                window.draw(text1);
                window.draw(text2);
                window.draw(text3);
                window.draw(text4);
		        window.display();


    	    }

            /*if (agr)
            {
                Fight(ds, camera);
            }*/
        }
    }

/* 
 * Communication with map borders
 */    
    if (ship->get_position().x_pos() < 0 || ship->get_position().y_pos() < 0 || ship->get_position().x_pos() > 5000 || ship->get_position().y_pos() > 3100)
    {
        ship->set_velocity(ship->get_velocity() * (-1));
    }
    
/*
 * Communication with police ships
 */
 
    for (int i = 0; i < 2; i++)
    {
        if (std::abs(ship->get_position().x_pos() - police.GetCoords()[i].x_pos()) < 20 && std::abs(ship->get_position().y_pos() - police.GetCoords()[i].y_pos()) < 20 && !(quest->is_active()))
        {
            sf::RenderWindow window (sf::VideoMode(1221, 725), "dialog_with_cop");
            sf::Texture dialogue;
            dialogue.loadFromFile("../images/diag/win.png");
            sf::Sprite win(dialogue); 
            win.setPosition(0, 0);
            
            Dialogue dia(Dialogue::find_file("police", 0));

            sf::Font font;
            font.loadFromFile("../images/font/18839.otf");
            
            sf::Text text1;
            text1.setString("Beginning");
            text1.setFont(font);
            text1.setCharacterSize(50);
            text1.setFillColor(sf::Color::Yellow);
            text1.setPosition(930, 50);

            sf::Text text2;
            text2.setString("About me");
            text2.setFont(font);
            text2.setCharacterSize(50);
            text2.setFillColor(sf::Color::Yellow);
            text2.setPosition(930, 150);

            sf::Text text3;
            text3.setFont(font);
            text3.setString("Pirates nearby");
            text3.setCharacterSize(50);
            text3.setFillColor(sf::Color::Yellow);
            text3.setPosition(860, 250);

            sf::Text text4;
            text4.setFont(font);
            text4.setString("Goodbye");
            text4.setCharacterSize(50);
            text4.setFillColor(sf::Color::Yellow);
            text4.setPosition(930, 350);

            string str = "";
            int num = 0;
            bool agr = false;

            while (window.isOpen())
            {
                text1.setFillColor(sf::Color::Yellow);
                text2.setFillColor(sf::Color::Yellow);
                text3.setFillColor(sf::Color::Yellow);
                text4.setFillColor(sf::Color::Yellow);

        	    sf::Event event;
        	    while (window.pollEvent(event))
        	    {
        		    if (event.type == sf::Event::Closed)
        		    {
        			    window.close();
        			    quest->make_active();
        		    }
			    }
                if (sf::IntRect(930, 50, text1.getGlobalBounds().width, text1.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text1.setFillColor(sf::Color::Red);
                    str = "Beginning";
                    num = 1;
                }

                if (sf::IntRect(930, 150, text2.getGlobalBounds().width, text2.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text2.setFillColor(sf::Color::Red);
                    str = "About you";
                    num = 2;
                }

                if (sf::IntRect(930, 250, text3.getGlobalBounds().width, text3.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text3.setFillColor(sf::Color::Red);
                    str = "Pirates nearby";
                    num = 3;
                }

                if (sf::IntRect(930, 350, text4.getGlobalBounds().width, text4.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                {
                    text4.setFillColor(sf::Color::Red);
                    str = "Goodbye";
                    num = 4;
                }
            
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (num == 1)
                    {
                        sf::Text outcome1;
                        outcome1.setFont(font);
                        outcome1.setString(dia.variants[str]);
                        outcome1.setCharacterSize(40);
                        outcome1.setFillColor(sf::Color::Yellow);
                        outcome1.setPosition(50, 50);
                        window.draw(outcome1);
                    }
                    else if (num == 2)
                    {
                        sf::Text outcome2;
                        outcome2.setFont(font);
                        outcome2.setString(dia.variants[str]);
                        outcome2.setCharacterSize(35);
                        outcome2.setFillColor(sf::Color::Yellow);
                        outcome2.setPosition(50, 250);
                        window.draw(outcome2);
                    }
                    else if (num == 3)
                    {
                        sf::Text outcome3;
                        outcome3.setFont(font);
                        outcome3.setString(dia.variants[str]);
                        outcome3.setCharacterSize(40);
                        outcome3.setFillColor(sf::Color::Yellow);
                        outcome3.setPosition(50, 350);
                        window.draw(outcome3);
                        quest->make_active();
                    }
                    else if (num == 4)
                    {
                        sf::Text outcome4;
                        outcome4.setFont(font);
                        outcome4.setString(dia.variants[str]);
                        outcome4.setCharacterSize(40);
                        outcome4.setFillColor(sf::Color::Yellow);
                        outcome4.setPosition(50, 450);
                        window.draw(outcome4);
                    }

                }
		
		        //window.clear();
                window.draw(win);
                window.draw(text1);
                window.draw(text2);
                window.draw(text3);
                window.draw(text4);
		        window.display();


    	    }
    	}
    	    

    	    else if(quest->is_done())
    	    {
    	        sf::RenderWindow window (sf::VideoMode(1221, 725), "dialog_with_cop");
                sf::Texture dialogue;
                dialogue.loadFromFile("../images/diag/win.png");
                sf::Sprite win(dialogue); 
                win.setPosition(0, 0);
            
                Dialogue dia(Dialogue::find_file("police", 0));

                sf::Font font;
                font.loadFromFile("../images/font/18839.otf");
                
                sf::Text text1;
                text1.setString("Get reward");
                text1.setFont(font);
                text1.setCharacterSize(50);
                text1.setFillColor(sf::Color::Yellow);
                text1.setPosition(930, 50);
                
                string str = "";
                int num = 0;
                bool agr = false;

                while (window.isOpen())
                {
                    text1.setFillColor(sf::Color::Yellow);

            	    sf::Event event;
             	    while (window.pollEvent(event))
             	    {
             		    if (event.type == sf::Event::Closed)
             		    {
             			    window.close();
             			    quest->make_active();
             		    }
		       	    }
                    if (sf::IntRect(930, 50, text1.getGlobalBounds().width, text1.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
                    {
                        text1.setFillColor(sf::Color::Red);
                        str = "Get reward";
                        num = 1;
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        if (num == 1)
                        {
                            sf::Text outcome1;
                            outcome1.setFont(font);
                            outcome1.setString(dia.variants[str]);
                            outcome1.setCharacterSize(40);
                            outcome1.setFillColor(sf::Color::Yellow);
                            outcome1.setPosition(50, 50);
                            window.draw(outcome1);
                        }
                    }
                    window.draw(win);
                    window.draw(text1);
		            window.display();
                        
                }
             }
         }
     }


#endif // COLLISION_H
