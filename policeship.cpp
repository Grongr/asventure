#include "policeship.h"
#include "doublecmp.h"
#include "geometricvector.h"
#include "sps_errors.h"

#include <cmath>


void PoliceShip::move_along_circle(double time) {
    if (is_less(time, 0))
        throw WrongTimeValue("Time cannot be less than zero in PoliceShip::move_along_cercle() method");

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
    
    y = L / std::sqrt( k + 1 );
    x = y * std::sqrt( k );

    auto ans = [&] (double ax, double ay) {
        return is_equal((ax * _x) + (ay * _y), 0);
    };

    /*
     * Check what answere is correct one
     */
    if      (ans( x,  y)) { this->V = Vector( x,  y); }
    else if (ans( x, -y)) { this->V = Vector( x, -y); }
    else if (ans(-x,  y)) { this->V = Vector(-x,  y); }
    else if (ans(-x, -y)) { this->V = Vector(-x, -y); }
    else {
        throw BadXYValue("None answere was correct in move_along_cirle method");
    }
}
