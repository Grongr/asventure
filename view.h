#ifndef VIEW_H
#define VIEW_H

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
            double x = vec.x_pos();
            double y = vec.y_pos();

            if (x < 840)
                x = 840;
            if (x > 4200)
                x = 4200;
            if (y < 525)
                y = 525;
            if (y > 2625)
                y = 2625;
            camera_view.setCenter(x, y);
        }
};

#endif // VIEW_H
