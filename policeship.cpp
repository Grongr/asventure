#include "policeship.h"
#include "doublecmp.h"
#include "geometricvector.h"

#include <cmath>


void PoliceShip::move_along_circle(double time) {
    auto radius_vector = [&] () {
        return (this->R - this->center_coords);
    };
    
    this->R = this->R + this->V * time;

    Vector r  = radius_vector();

    double _x = r.x_pos();
    double _y = r.y_pos();

    double x = 0, y = 0;
    double k = (_y / _x);
    k *= k;

    double L = this->V.length();
    L *= L;
    
    y  = -k + std::sqrt(k*k - L);
    y /= 2;

    x = -k * y;

    this->V = Vector(x, y);
}
