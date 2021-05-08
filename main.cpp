#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "drawship.h"
#include "spaceship.h"
#include <memory>
#include "interface.h"
#include "menu.h"
#include "view.h"


int main() 
{
    // Rendering window
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "asventure");
    
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
    DrawPirateShip drawpirateship;

    // Sprite for pirate ship
    sf::Texture pirateTexture;
    pirateTexture.loadFromFile("../images/ships/ship2.png");
    sf::Sprite pirateship(pirateTexture);
    
    // Init user interaction
    Interface interface;

    menu(window);
    
    sf::Texture backTexture;
    backTexture.loadFromFile("../images/interface/background.png");
    sf::Sprite background(backTexture);
    background.setPosition(0, 0);

    while (window.isOpen())
    {
        sf::Clock clock;
        double time = clock.getElapsedTime().asMicroseconds();
        
        // Starting timer
        clock.restart();
        
        // I'm still not good at time management
        time = time/1000;

        // Managing window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        interface.QwertyInter(drawship.GetShip());
        camera.StalkingShip(drawship.GetShip()->get_position());

        drawpirateship.MoveShip(time, 100);
        drawship.MoveShip(time);

        // Drawing ship
        ship.setPosition((drawship.GetRect()).left, (drawship.GetRect()).top);
        
        // Drawing pirate ship
        pirateship.setPosition((drawpirateship.GetRect()).left, (drawpirateship.GetRect()).top);
        //std::cout << (drawpirateship.GetRect()).left << " " << (drawpirateship.GetRect()).top;

        // Reset
        window.setView(camera.getView());
        window.clear();
        window.draw(background);
        window.draw(ship);
        window.draw(pirateship);
    	window.display();
    }
	
    return 0;
}
