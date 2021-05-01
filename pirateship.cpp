//
// Created by grongr on 4/23/21.
//

#include "pirateship.h"

//-----------------------------------------------------------------------------------------------------------//
void PirateShip::move_ship_forward(double time, double speed_const) {
    //TODO: Optimisation
    double needed_time = 0;

    auto time_count = [&needed_time, this, speed_const, time]
            (std::list<Vector>::iterator i) {
        this->V = *i - this->R;
        needed_time = this->V.length();
        this->V.normalise();
        if (is_equal(this->V.length(), 0.0))
            throw ZeroSpeedError("Two neighbour trajectory points are equal or iterator <it> has been changed incorrectly");
        this->V = this->V * speed_const;
        needed_time /= this->V.length();
    };

    time_count(it);

    if (it != (--trajectory.end())) {
        while (time > needed_time) {
            this->R = *it;
            if (*it == *(--trajectory.end())) {
                it = trajectory.begin();
            } else {
                ++it;
            }
            time -= needed_time;
            if (is_equal(time, 0.0)) break;
            time_count(it);

        }
        this->R = this->R + this->V * time;
    }

}