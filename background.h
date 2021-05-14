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
        array<array<sf::Sprite, 10>, 10> back;
        sf::Texture backTexture;

    public:

        Background()
        {
            this->backTexture.loadFromFile("../images/interface/background.png");
            sf::Sprite background(backTexture);

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    back[i][j] = background;
                }
            }
    
            int x = 0;
            int y = 0;

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
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

        void DrawBack(sf::RenderWindow& window)
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    window.draw(back[i][j]);
                }
            }
        }
};

#endif // BACKGROUND_H
