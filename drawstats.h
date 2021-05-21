#include <SFML/Graphics.hpp>
#include <array>
#include "character.h"
#include "view.h"
#include <string>

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
   sf::Text hp_val;
   sf::Text am_val;
   std::array<sf::Texture, 10> bat;
   std::array<sf::Texture, 6> ft;
   Camera* camera0;

public:
    DrawStats(std::shared_ptr<SpaceShip> ship, Camera* camera);
    virtual ~DrawStats() = default;
    void Update(sf::RenderWindow& window, std::string id);
    sf::FloatRect GetRect();
    Camera* GetCamera() { return camera0; }
    std::shared_ptr<Character> GetCharacter() { return character; }
};
