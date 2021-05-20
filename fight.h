#include <SFML/Graphics.hpp>

void Fight()
{
    sf::RenderWindow window (sf::VideoMode(1680, 1050), "FIGHT!!");
    sf::Texture back;
    back.loadFromFile("../images/diag/fight0.png");
    sf::Sprite win(back);
    win.setPosition(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(win);
        window.display();
    }
}
