#include <memory>
#include "drawship.h"
#include "spaceship.h"
#include "pirateship.h"
#include "init.h"
#include <SFML/Graphics.hpp>

/*========================_SpaceShip_===========================*/

DrawShip::DrawShip()
{
    this->rect = sf::FloatRect(160, 160, 32, 32);
    this->ship = InitSS();
}

void DrawShip::MoveShip(double time)
{
    this->ship->move_ship(time);
    Vector vec = this->ship->get_position();
    rect.left  = vec.x_pos();
    rect.top   = vec.y_pos();
}

std::shared_ptr<SpaceShip> DrawShip::GetShip() { return this->ship; }

sf::FloatRect DrawShip::GetRect() { return this->rect; }

/*========================_PirateShip_==========================*/

DrawPirateShip::DrawPirateShip()
{
    this->rect = sf::FloatRect(500, 500, 32, 32);
    this->pirate_ship = InitPS();
}

void DrawPirateShip::MoveShip(double time, double constant)
{
    this->pirate_ship->move_ship_forward(time, constant);
    Vector vec = this->pirate_ship->get_position();
    this->rect.left  = vec.x_pos();
    this->rect.top   = vec.y_pos();
}

std::shared_ptr<PirateShip> DrawPirateShip::GetShip() { return this->pirate_ship; }

sf::FloatRect DrawPirateShip::GetRect() { return this->rect; }
