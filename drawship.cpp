#include <SFML/Graphics.hpp>
#include <memory>

#include "drawship.h"
#include "spaceship.h"
#include "pirateship.h"
#include "init.h"

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

DrawPirateShip::DrawPirateShip(std::list<Vector> trajectory, int head_cost, Vector velocity, Vector radius_vector)
{
    this->rect = sf::FloatRect(500, 500, 32, 32);
    this->pirate_ship = InitPS(trajectory, head_cost, velocity, radius_vector);
}

DrawPirateShip::DrawPirateShip()
{
    //this->rect = sf::FloatRect(500, 500, 32, 32);
    //this->pirate_ship = InitPS();
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


/*==========================_PoliceShip_========================*/

DrawPoliceShip::DrawPoliceShip()
{
}

DrawPoliceShip::DrawPoliceShip(Vector cc, double r, double aV)
{
    this->rect = sf::FloatRect(500, 500, 32, 32);
    this->police_ship = InitPL(cc, r, aV);
}

std::shared_ptr<PoliceShip> DrawPoliceShip::GetShip() { return this->police_ship; }
