#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "spaceship.h"
#include "Drawing.h"
#include "Interface.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "asventure");
    sf::RectangleShape shape(sf::Vector2f(32.f, 32.f));
    shape.setFillColor(sf::Color::Red);
    
    DrawShip drawship;
    drawship.GetShip()->toggle_engine();
    
    Interface interface;
    
    sf::Event event;
    
    sf::FloatRect rect;
	rect = sf::FloatRect(160, 160, 32, 32);

    while(window.isOpen())
    {	
    	sf::Clock clock;
        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/1000;        // I'm not good at time management :(

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        interface.QwertyInter(drawship.GetShip());
        
        drawship.MoveShip(time);
		
		rect = drawship.GetRect();
		
		shape.setPosition(rect.left, rect.top);
		
		window.clear();
		window.draw(shape);
        window.display();
    }
	
    return 0;
}
