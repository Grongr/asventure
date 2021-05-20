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

public:
    DrawStats();
    virtual ~DrawStats() = default;
    void Update(sf::RenderWindow& window, Camera& camera);
    sf::FloatRect GetRect();
};
