//
// Created by grongr on 4/23/21.
//

#ifndef ASVERGIN_GEOMETRICVECTOR_H
#define ASVERGIN_GEOMETRICVECTOR_H

#include <cmath>

#include "doublecmp.h"

#define DEBUG
//-----------------------------------------------------------------------------------------------------------//
/*!
 * Geometric representation of a vector in 2D space
 */
class Vector {
public:
    /*!
     * Default constructor.
     * Params become zeroes :)
     */
    Vector() : x{0}, y{0} { }

    /*!
     * Constructor which could initialize all coordinates
     * @param x x coordinate of a new vector
     * @param y y coordinate of a new vector
     */
    Vector(double x, double y) : x{x}, y{y} { }

    /*!
     * If you wanna know the length or the absolute value
     * of this vector
     *
     * @return the length of a vector
     */
    [[nodiscard]] double length() const { return sqrt(x * x + y * y); }

    /*!
     * Normalises this vector
     */
    void normalise();

    /*!
     * This is how Vectors are summed. Yeah
     * I wish, there is the word like "summed" in English language
     * @param r
     * @return
     */
    Vector operator+ (Vector const& r) const;

    /*!
     * This is how Vectors are subtracted.
     * @param r
     * @return
     */
    Vector operator- (Vector const& r) const;

    /*!
     * You know, that is vector that is multiplied on a real number...
     * @param value
     * @return
     */
    Vector operator* (double value) const;

    /*!
     * Operator !=
     * @param r
     * @return true if this != r
     */
    bool operator!= (Vector const &r) const;

    /*!
     * Operator ==
     * @param r
     * @return   true if this == r and false if not
     */
    bool operator== (Vector const& r) const;

    /*!
     * Do you wanna the x coordinate of this Vector???
     * @return the x coordinate of this Vector
     */
    [[nodiscard]] double x_pos() const { return x; }

    /*!
     * Do you wanna the y coordinate of this Vector???
     * @return the y coordinate of this Vector
     */
    [[nodiscard]] double y_pos() const { return y; }

    /*!
     * How to integrate one vector into another
     * @param p
     * @return result vector
     */
    Vector& operator= (Vector const &p) = default;

#ifdef DEBUG

    /*!
     * Simply out x, y
     */
    void print_vector() const;

#endif // DEBUG

protected:
    /*!
     * Coordinates of a point in space
     */
    double x, y;
};

#endif //ASVERGIN_GEOMETRICVECTOR_H
