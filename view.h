#include <SFML/Graphics.hpp>
#include "geometricvector.h"

class Camera
{
    private:
        sf::View camera_view;
    public:
        Camera()
        {
            sf::View view;
            this->camera_view = view;
            this->camera_view.reset(sf::FloatRect(0, 0, 1680, 1050));
        }
        sf::View getView()
        {
            return this->camera_view;
        }
        void StalkingShip(Vector vec)
        {
            camera_view.setCenter(vec.x_pos(), vec.y_pos());
        }
};
