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
    std::array<DrawPoliceShip, 2> policeships;
    std::array<Vector, 2> radius_vectors;
    std::array<sf::Sprite, 2> sprites;
    sf::Texture policeTexture;

public:
    Police();
    void Draw(sf::RenderWindow& window, double x, double y);
    std::array<DrawPoliceShip, 2> GetPolice() { return policeships; }
    std::array<Vector, 2> GetCoords() { return radius_vectors; }
};
