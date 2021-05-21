#include <SFML/Graphics.hpp>
#include <array>
#include "character.h"
#include "view.h"

class DrawStats
{
private:
   std::shared_ptr<Character> character;
   sf::FloatRect rect;
   std::array<sf::Texture, 6> ammo;
   std::array<sf::Texture, 6> hp;
   sf::Texture stat;
   sf::Text money;
   sf::Text damage;
   sf::Text armor;
   sf::Text bfg;
   sf::Font font;
   std::array<sf::Texture, 10> bat;
   std::array<sf::Texture, 6> ft;

public:
    DrawStats(std::shared_ptr<SpaceShip> ship);
    virtual ~DrawStats() = default;
    void Update(sf::RenderWindow& window, Camera& camera);
    sf::FloatRect GetRect();
};
