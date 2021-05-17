//
// Created by grongr on 4/23/21.
//

#include <iostream>
#include <cmath>

#include "geometricvector.h"

//-----------------------------------------------------------------------------------------------------------//
Vector Vector::operator+(Vector const& r) const {
    return Vector(this->x + r.x, this->y + r.y);
}

Vector Vector::operator-(Vector const& r) const {
    return Vector(this->x - r.x, this->y - r.y);
}

Vector Vector::operator*(double value) const {
    return Vector(this->x * value, this->y * value);
}

void Vector::normalise() {
    if (!is_equal(this->x, 0))
        this->x /= fabs(this->x);
    if (!is_equal(this->y, 0))
        this->y /= fabs(this->y);
}

bool Vector::operator!=(Vector const &r) const {
    if (is_equal(this->x, r.x) && is_equal(this->y, r.y))
        return false;
    else
        return true;
}

bool Vector::operator==(const Vector &r) const {
    return !(*this != r);
}

void Vector::print_vector() const {
    std::cout << this->x << " " << this->y << std::endl;
<<<<<<< HEAD
}
=======
}
>>>>>>> master
