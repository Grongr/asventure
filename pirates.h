#include <array>
#include <list>
#include "geometricvector.h"
#include "pirateship.h"
#include "drawship.h"
#include <SFML/Graphics.hpp>

/*
 * Class that contains information about
 * all pirateships on the map.
 */
class Pirates
{
    private:
        std::array<DrawPirateShip, 9> pirateships;
        std::array<std::list<Vector>, 9> trajectories;
        std::array<int, 9> head_costs;
        std::array<Vector, 9> velocities;
        std::array<Vector, 9> radius_vectors;
        std::array<sf::Sprite, 9> sprites;
        sf::Texture pirateTexture;

    public:
        /*
         * Opens .txt file and saves information 
         * about pirates, number of string in file 
         * determines number of ship's params in arrays
         */
        Pirates();
        void Draw(sf::RenderWindow& window, double time, double constant, double x, double y);
        std::array<DrawPirateShip, 9> GetPirates() { return pirateships; }
        std::array<int, 9> GetHeadCosts() { return head_costs; }
};
