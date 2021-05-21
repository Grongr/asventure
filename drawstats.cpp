#include "drawstats.h"
#include "init.h"
#include "geometricvector.h"
#include <SFML/Graphics.hpp>
#include <string>

DrawStats::DrawStats()
{
    character = InitCH(50, 15, 3, 100, 11, 100);
    rect = sf::FloatRect(452, 452, 132, 132);

    stat.loadFromFile("../images/states/states.png");

    ammo[0].loadFromFile("../images/states/am10.png");
    ammo[1].loadFromFile("../images/states/am20.png");
    ammo[2].loadFromFile("../images/states/am40.png");
    ammo[3].loadFromFile("../images/states/am60.png");
    ammo[4].loadFromFile("../images/states/am80.png");
    ammo[5].loadFromFile("../images/states/am100.png");

    hp[0].loadFromFile("../images/states/hp10.png");
    hp[1].loadFromFile("../images/states/hp20.png");
    hp[2].loadFromFile("../images/states/hp40.png");
    hp[3].loadFromFile("../images/states/hp60.png");
    hp[4].loadFromFile("../images/states/hp80.png");
    hp[5].loadFromFile("../images/states/hp100.png");
    
    //sf::Font f;
    font.loadFromFile("../images/font/18839.otf");
    //font = f;

    money.setFont(font);
    money.setCharacterSize(40);
    money.setFillColor(sf::Color::Yellow);
    money.setPosition(1553, 1025);

    damage.setFont(font);
    damage.setCharacterSize(40);
    damage.setFillColor(sf::Color::Yellow);
    damage.setPosition(1353, 1025);

    armor.setFont(font);
    armor.setCharacterSize(40);
    armor.setFillColor(sf::Color::Yellow);
    armor.setPosition(1253, 1050);

    bfg.setFont(font);
    bfg.setCharacterSize(40);
    bfg.setFillColor(sf::Color::Yellow);
    bfg.setPosition(1453, 1050);

    
}

void DrawStats::Update(sf::RenderWindow& window, Camera& camera)
{
    sf::Sprite stat0(stat);
    sf::Sprite hp0;
    sf::Sprite am0;
    
    if (character->hp() > 80)
        hp0 = sf::Sprite(hp[5]);
    else if (character->hp() > 60)
        hp0 = sf::Sprite(hp[4]);
    else if (character->hp() > 40)
        hp0 = sf::Sprite(hp[3]);
    else if (character->hp() > 20)
        hp0 = sf::Sprite(hp[2]);
    else if (character->hp() > 10)
        hp0 = sf::Sprite(hp[1]);
    else if (character->hp() > 0)
        hp0 = sf::Sprite(hp[0]);

    if (character->ammo_count() > 80)
    {
        am0 = sf::Sprite(ammo[5]);
    }
    else if (character->ammo_count() > 60)
        am0 = sf::Sprite(ammo[4]);
    else if (character->ammo_count() > 40)
    {
        am0 = sf::Sprite(ammo[3]);
    }
    else if (character->ammo_count() > 20)
        am0 = sf::Sprite(ammo[2]);
    else if (character->ammo_count() > 10)
        am0 = sf::Sprite(ammo[1]);
    else if (character->ammo_count() > 0)
        am0 = sf::Sprite(ammo[0]);

    double x = camera.getCameraCoords().x_pos() + 388;
    double y = camera.getCameraCoords().y_pos() + 393;



    stat0.setPosition(x, y);
    if (character->ammo_count() > 0)
        am0.setPosition(x, y);
    if (character->hp() > 0)
        hp0.setPosition(x, y);

    money.setPosition(x + 55, y + 65);
    damage.setPosition(x + 170, y + 65);
    armor.setPosition(x + 270, y + 65);
    bfg.setPosition(x + 375, y + 65);

    money.setString(std::to_string(character->money()));
    damage.setString(std::to_string(character->damage()));
    armor.setString(std::to_string(character->armor()));
    bfg.setString(std::to_string(character->BFG()));

    window.draw(money);
    window.draw(damage);
    window.draw(armor);
    window.draw(bfg);
    
    window.draw(stat0);
    window.draw(am0);
    window.draw(hp0);
    //window.display();
}
