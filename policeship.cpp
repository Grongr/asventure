#include "policeship.h"
#include "doublecmp.h"
#include "geometricvector.h"
#include "sps_errors.h"

#include <cmath>


void PoliceShip::move_along_circle(double time) {
    if (is_less(time, 0))
        throw WrongTimeValue("Time cannot be less than zero in PoliceShip::move_along_cercle() method");
    if (is_less(this->angV, 0))
        throw WrongAngleVelocityValue("This method now can only work with positive numbers of angV");

    double angle = get_angle(this->R - this->center_coords, Vector(1, 0));

    /* std::cout << "This angle on start: " << angle * 180 / pi() << std::endl; */

    if (is_bigger(this->angV * time, pi() / 2))
        throw WrongAngleVelocityValue("Police ship is moving too fast");
    
    angle += this->angV * time;

    double x = 0, y = 0;
    double cos = std::cos(angle), sin = std::sin(angle);

    /* std::cout << "Angle in the end: " << angle * 180 / pi() << std::endl; */

    // Change sign of cosinus depending on which quarter is angle in
    if (is_less(R.x_pos(), center_coords.x_pos()))
        cos = -std::fabs(cos);
    else
        cos = std::fabs(cos);

    // Change sign of sinus depending on which quarter is angle in
    if (is_less(R.y_pos(), center_coords.y_pos()))
        sin = -std::fabs(sin);
    else
        sin = std::fabs(sin);

    x = this->radius * cos + this->center_coords.x_pos();
    y = this->radius * sin + this->center_coords.y_pos();

    this->R = Vector(x, y);
}
