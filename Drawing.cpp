#include "Drawing.h"
#include "InitShip.h"
#include "spaceship.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

DrawShip::~DrawShip()
{
	delete ship;
}

DrawShip::DrawShip()
{
    this->rect = sf::FloatRect(160,160,32,32);			// Params will be changed when
 														// textures will be ready
    this->ship = InitSSB();
}

void DrawShip::MoveShip(double time)
{
    this->ship->move_ship(time);
    Vector vec = this->ship->get_position();
    rect.left = vec.x_pos();
    rect.top = vec.y_pos();
}

sf::FloatRect DrawShip::GetRect()
{
	return rect;
}

SpaceShip* DrawShip::GetShip() { return this->ship; }	
