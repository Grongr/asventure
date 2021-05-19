#ifndef BACKGROUND_H
#define BACKGROUND_h

#include <SFML/Graphics.hpp>
#include <array>

using namespace std;

/*
 * Initializing matrix of background textures
 */

class Background
{
    private:
        array<array<sf::Sprite, 3>, 3> back;
        sf::Texture backTexture;

    public:

        Background()
        {
            this->backTexture.loadFromFile("../images/interface/background.png");
            sf::Sprite background(backTexture);

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    back[i][j] = background;
                }
            }
    
            int x = 0;
            int y = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    back[i][j].setPosition(x, y);
                    x = x + 1680;
                }
                
                x = 0;
                y = y + 1050;
            }
        }

        /*
         * Draws matrix of background textures.
         * In the future must be done drawing of
         * the nearest to spaceship sprites.
         */

        void DrawBack(sf::RenderWindow& window, std::shared_ptr<SpaceShip> ship)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (ship->get_position().x_pos() > (j-2)*1680 && ship->get_position().y_pos() < (j+2)*1680 && ship->get_position().y_pos() > (i-2)*1050 && ship->get_position().y_pos() < (i+2)*1050)
                        window.draw(back[i][j]);
                }
            }
        }
};

#endif // BACKGROUND_H
