#include <iostream>
#include "unitests.h"
#include "spaceship.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>


int main() {
	
	sf::RenderWindow window( sf::VideoMode(1680, 1050), "asventure");
	sf::RectangleShape shape(sf::Vector2f(32.f, 32.f));
	shape.setFillColor(sf::Color::Red);

	EnergyFuelSystemBuilder efsb;
	efsb.set_size_of_bat_arr(50);
	efsb.set_bat_energy(100);
	efsb.set_fmv(10000);
	efsb.set_fu(1);
	efsb.set_fQ(1);
	
	SpaceShipBuilder ssb;
	ssb.set_fuel_cost(1);
	ssb.set_is_engine_active(false);
	ssb.set_AVec(Vector(0, 0));
	ssb.set_R(Vector(0,0));
	ssb.set_V(Vector(0,0));
	ssb.set_mass(0);
	auto* ship = ssb.make_spaceship(efsb);
	
	sf::FloatRect rect;
	rect = sf::FloatRect(160, 160, 32, 32);
	int i = 10;

	ship->toggle_engine();

	while(window.isOpen())
	{
		sf::Clock clock;
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/1000;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			ship->toggle_engine();
		}*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			ship->set_velocity(Vector(-0.1, 0) + (ship->get_velocity()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ship->set_velocity(Vector(0.1, 0) + (ship->get_velocity()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ship->set_velocity(Vector(0, -0.1) + (ship->get_velocity()));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			ship->set_velocity(Vector(0, 0.1) + (ship->get_velocity()));
		}

		//std::cout << (ship->get_accel().x_pos()) << (ship->get_accel().y_pos()) << std::endl;
		//time = time*100;
		ship->move_ship(time);
		Vector vec;
		vec = ship->get_position();
		rect.left = vec.x_pos();
		rect.top = vec.y_pos();
		
		shape.setPosition(rect.left, rect.top);
		//std::cout << "x = " << rect.left << " " << "y = " << rect.top;
		//std::cout << "time: " << time;
		window.clear();
		window.draw(shape);
		window.display();

		i += 10;
	}

	//unit_test();
	return 0;
}
