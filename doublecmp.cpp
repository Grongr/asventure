//
// Created by grongr on 4/24/21.
//

#include "doublecmp.h"
#include <limits>

bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

bool is_bigger(double x, double y) {
    return x - std::numeric_limits<double>::epsilon() > y;
}

bool is_less(double x, double y) {
    return (!is_equal(x, y) && !is_bigger(x, y));
}
