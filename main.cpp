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
    sf::RectangleShape shape1(sf::Vector2f(32.f, 32.f));
    shape1.setFillColor(sf::Color::Red);
    
    // Engine is active (can be activated in params of builder also)
    drawship.GetShip()->toggle_engine();
    
    // Pirate ship is building
    DrawPirateShip drawpirateship;

    // Sprite for pirate ship
    sf::RectangleShape shape2(sf::Vector2f(32.f, 32.f));
    shape2.setFillColor(sf::Color::Blue);
    
    // Init user interaction
    Interface interface;

    menu(window);

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
        shape1.setPosition((drawship.GetRect()).left, (drawship.GetRect()).top);
        
        // Drawing pirate ship
        shape2.setPosition((drawpirateship.GetRect()).left, (drawpirateship.GetRect()).top);
        //std::cout << (drawpirateship.GetRect()).left << " " << (drawpirateship.GetRect()).top;

        // Reset
        window.clear();
        window.draw(shape1);
        window.draw(shape2);
    	window.display();
    }
	
    return 0;
}
