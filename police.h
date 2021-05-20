#include <array>
#include "geometricvector.h"
#include "drawship.h"
#include <SFML/Graphics.hpp>

/*
 * Class that contains information about
 * all police ships on the map
 */
class Police
{
private:
    std::array<DrawPoliceShip, 9> policeships;
    std::array<Vector, 9> radius_vectors;
    std::array<sf::Sprite, 9> sprites;
    sf::Texture policeTexture;

public:
    Police();
    void Draw(sf::RenderWindow& window, double x, double y);
    std::array<DrawPoliceShip, 9> GetPolice() { return policeships; }
};
