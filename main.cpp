#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <memory>

#include "drawship.h"
#include "spaceship.h"
#include "interface.h"
#include "menu.h"
#include "view.h"
#include "background.h"
#include "collision.h"
#include "quests.h"
#include <vector>
#include "pirates.h"
//#include "drawstats.h"
#include "character.h"
#include "init.h"
//#include "police.h"

int main() 
{
    // Rendering window
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "asventure");
    
    //window.setFramerateLimit(30);
    
    // Init camera view to follow your ship
    Camera camera;
    
    // Here the ship is building
    DrawShip drawship;
    
    // Sprite for ship
    sf::Texture shipTexture;
    shipTexture.loadFromFile("../images/ships/ship1.png");
    sf::Sprite ship(shipTexture); 
    
    // Engine is active (can be activated in params of builder also)
    drawship.GetShip()->toggle_engine();
    
    // Pirate ship is building
    
    //DrawPirateShip drawpirateship;

    Quest quest;

    // Sprite for pirate ship
    //sf::Texture pirateTexture;
    //pirateTexture.loadFromFile("../images/ships/ship2.png");
    //sf::Sprite pirateship(pirateTexture);
    
    // Init user interaction
    Interface interface;

    menu(window);
    
    Background background;

    Pirates pirates;

    Police police;

    DrawStats drawstats(drawship.GetShip());

    double time = 0.001;

    while (window.isOpen())
    {
        //sf::Clock clock;
        //double time = clock.getElapsedTime().asMicroseconds();
        
        // Starting timer
        //clock.restart();
        
        // I'm still not good at time management
        //time = time/2;

        // Managing window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // User interaction
        interface.QwertyInter(drawship.GetShip());

        Collision(drawship.GetShip(), pirates.GetPirates(),  police, &quest, drawstats, camera);

        //drawpirateship.MoveShip(time, 100);
        drawship.MoveShip(time);

        // Moving camera
        camera.StalkingShip(drawship.GetShip()->get_position());

        // Drawing ship
        ship.setPosition((drawship.GetRect()).left, (drawship.GetRect()).top);
        
        // Drawing pirate ship
        //pirateship.setPosition((drawpirateship.GetRect()).left, (drawpirateship.GetRect()).top);
        //std::cout << (drawpirateship.GetRect()).left << " " << (drawpirateship.GetRect()).top;
        
        
        // Reset
        window.setView(camera.getView());
        window.clear();
        

        background.DrawBack(window, drawship.GetShip());

        drawstats.Update(window, camera);
        
        pirates.Draw(window, time, 100, drawship.GetShip()->get_position().x_pos(), drawship.GetShip()->get_position().y_pos());
        
        police.Draw(window, drawship.GetShip()->get_position().x_pos(), drawship.GetShip()->get_position().y_pos());
        window.draw(ship);
        //window.draw(pirateship);
    	window.display();
    }
}
