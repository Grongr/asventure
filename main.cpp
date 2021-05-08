#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "drawship.h"
#include "spaceship.h"
#include <memory>
#include "interface.h"
#include "menu.h"


int main() 
{
    // Rendering window
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "asventure");
    
    // Here the ship is building
    DrawShip drawship;
    
    // Sprite for ship
    //sf::RectangleShape shape1(sf::Vector2f(32.f, 32.f));
    //shape1.setFillColor(sf::Color::Red);
    sf::Texture shipTexture;
    shipTexture.loadFromFile("../images/ships/ship1.png");
    sf::Sprite ship(shipTexture);
    
    // Engine is active (can be activated in params of builder also)
    drawship.GetShip()->toggle_engine();
    
    // Pirate ship is building
    DrawPirateShip drawpirateship;

    // Sprite for pirate ship
    //sf::RectangleShape shape2(sf::Vector2f(32.f, 32.f));
    //shape2.setFillColor(sf::Color::Blue);
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

        drawpirateship.MoveShip(time, 100);
        drawship.MoveShip(time);

        // Drawing ship
        ship.setPosition((drawship.GetRect()).left, (drawship.GetRect()).top);
        
        // Drawing pirate ship
        pirateship.setPosition((drawpirateship.GetRect()).left, (drawpirateship.GetRect()).top);
        //std::cout << (drawpirateship.GetRect()).left << " " << (drawpirateship.GetRect()).top;

        // Reset
        window.clear();
        window.draw(background);
        window.draw(ship);
        window.draw(pirateship);
    	window.display();
    }
	
    return 0;
}
