//
// Created by grongr on 4/24/21.
//

#ifndef ASVERGIN_DOUBLECMP_H
#define ASVERGIN_DOUBLECMP_H

#include <cmath>
#include <limits>

/*!
 * Real numbers cannot be compared with bool operators, so we need cmp func fro them
 * There I use std::limits to set a constant epsilon.
 * It's inline because of issues with multiplied definition
 * @param x  first num to compare
 * @param y  second num to compare
 * @return   true if x is equal y, false of not
 */
bool is_equal(double x, double y);

/*!
 * Real numbers cannot be compared with bool operators, so this is a cmp function
 * to know which onw is bigger
 * @param x  first num to compare
 * @param y  second num to compare
 * @return   true if x is bigger then y
 */
bool is_bigger(double x, double y);

/*!
 * Real numbers cannot be compared with bool operators, so this is a cmp function
 * to know which onw is less
 * @param x  first num to compare
 * @param y  second num to compare
 * @return   true if x is less then y
 */
bool is_less(double x, double y);

#endif //ASVERGIN_DOUBLECMP_H
