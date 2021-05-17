//
// Created by grongr on 4/23/21.
//

#include <iostream>
#include <cmath>

#include "doublecmp.h"
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
}
//-----------------------------------------------------------------------------------------------------------//
[[nodiscard]] double dot(const Vector &a, const Vector &b) {
    double ans;
    ans = a.x_pos() * b.x_pos() + a.y_pos() * b.y_pos();
    return ans;
}

[[nodiscard]] bool is_koll(const Vector &a, const Vector &b) {
    if (a == Vector(0, 0) || b == Vector(0, 0))
        return true;

    if ( is_equal(a.x_pos(), 0.0) && is_equal(a.x_pos(), b.x_pos()) )
        return true;

    if ( is_equal(a.y_pos(), 0.0) && is_equal(a.y_pos(), b.y_pos()) )
        return true;

    return  is_equal( a.x_pos() / b.x_pos(), a.y_pos() / b.y_pos() );
}

[[nodiscard]] double get_angle(const Vector &a, const Vector &b) {
    if ( is_koll(a, b) )
        return 0.0;
    double d = dot(a, b);
    double cos;
    if (is_equal(d, 0))
        cos = 0;
    else
        cos = d / a.length() / b.length();
    return std::acos(cos);
}
