#include "fight.h"

void Fight(DrawPirateShip drawpirateship, int head_cost, DrawStats& drawstats)
{
    sf::RenderWindow window(sf::VideoMode(1680, 1025), "FIGHT!!");

    sf::Texture fight;
    fight.loadFromFile("../images/diag/fight0.png");
    sf::Sprite fight0(fight);
    
    std::shared_ptr<Character> pirate;
    pirate = InitCH(10000, 9, 1, 15, 0, 40, drawpirateship.GetShip());

    sf::Font font;
    font.loadFromFile("../images/font/18839.otf");

    sf::Text attack;
    attack.setString("Attack");
    attack.setFont(font);
    attack.setCharacterSize(50);
    attack.setFillColor(sf::Color::Yellow);
    attack.setPosition(800, 820);

    sf::Text defend;
    defend.setString("Defend");
    defend.setFont(font);
    defend.setCharacterSize(50);
    defend.setFillColor(sf::Color::Yellow);
    defend.setPosition(360, 820);

    sf::Text repair;
    repair.setString("Repair");
    repair.setFont(font);
    repair.setCharacterSize(50);
    repair.setFillColor(sf::Color::Yellow);
    repair.setPosition(560, 690);

    sf::Text maneuver;
    maneuver.setString("Maneuver");
    maneuver.setFont(font);
    maneuver.setCharacterSize(50);
    maneuver.setFillColor(sf::Color::Yellow);
    maneuver.setPosition(950, 690);

    int num = 0;

    int pirates_turns = 0;
    int players_turns = 0;


    while (window.isOpen())
    {
        attack.setFillColor(sf::Color::Yellow);
        defend.setFillColor(sf::Color::Yellow);
        maneuver.setFillColor(sf::Color::Yellow);
        repair.setFillColor(sf::Color::Yellow);

        /*sf::Event event;
        while (window.pollEvent(event))
        {
            if ( !((*(pirate)).is_alive()))
            {
                drawstats.GetCharacter()->reward(head_cost);
                drawpirateship.Kill();
                window.close();
            }
        }*/

        if ( !((*(pirate)).is_alive()))
        {
            drawstats.GetCharacter()->reward(head_cost);
            drawpirateship.Kill();
            window.close();
        }


        if (sf::IntRect(800, 820, attack.getGlobalBounds().width, attack.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
        {
            attack.setFillColor(sf::Color::Red);
            num = 1;
        }

        if (sf::IntRect(360, 820, defend.getGlobalBounds().width, defend.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
        {
            defend.setFillColor(sf::Color::Red);
            num = 2;
        }
        if (sf::IntRect(560, 690, repair.getGlobalBounds().width, repair.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
        {
            repair.setFillColor(sf::Color::Red);
            num = 3;
        }
        if (sf::IntRect(950, 690, maneuver.getGlobalBounds().width, maneuver.getGlobalBounds().height).contains(sf::Mouse::getPosition(window)))
        {
            maneuver.setFillColor(sf::Color::Red);
            num = 4;
        }
        
        sf::Time delayTime = sf::milliseconds(100);

        if (players_turns < 2)
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::sleep(delayTime);

                if (num == 1)
                {
                    drawstats.GetCharacter()->attack(*(pirate));   
                }
                else if (num == 2)
                {
                    drawstats.GetCharacter()->active_defence();
                }
                else if (num == 3)
                {
                    drawstats.GetCharacter()->repair(); 
                }
                else if (num == 4)
                {
                    drawstats.GetCharacter()->maneuver(*(pirate));
                }
            }
            players_turns ++;
        }
        else if (pirates_turns < 2)
        {
            Character::enemy_ai(*(drawstats.GetCharacter()), *(pirate));
            pirates_turns ++;
        }
        else
        {
            pirates_turns = 0;
            players_turns = 0;
        }
        
        window.clear();

        window.draw(fight0);

        drawstats.Update(window, "static");
        window.draw(attack);
        window.draw(defend);
        window.draw(repair);
        window.draw(maneuver);
        window.display();
    }
}
