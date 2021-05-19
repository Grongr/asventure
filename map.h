#include <iostream>
#include "geometricvector.h"
#include <string.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "drawship.h"
#include <array>
#include "spaceship.h"
#include "pirateship.h"

void Map(std::shared_ptr<SpaceShip> ship, sf::RenderWindow& window, double time)
{
    Vector current_square, current_position;
    current_square = Vector(2, 2);
    double x,y;
    x = int (ship->get_position().x_pos()/7) + 1;
    y = int (ship->get_position().y_pos()/7) + 1;
    current_position = Vector(x, y);
    int N;

    std::list<Vector> trajectory;
    int head_cost;
    Vector velocity;
    Vector radius_vector;

    std::array<PirateShip, 9> pirates_around;

    /*for (int i = current_position.y_pos() - 1; i <= current_position.y_pos() + 1; i ++)
    {
        for (int j = current_position.x_pos() - 1; j <= current_position.x_pos() + 1; i++)
        {
            N = i*3 + j;

            DrawPirateShip drawpirateship(N);
            sf::Texture pirateTexture;
            pirateTexture.loadFromFile("../images/ships/ship2.png");
            sf::Sprite pirateship(pirateTexture);
            drawpirateship.MoveShip(time, 100);
            pirateship.setPosition(radius_vector.x_pos(), radius_vector.y_pos());

            window.clear();
            window.draw(pirateship);
            window.display();

        }
    }*/
    
