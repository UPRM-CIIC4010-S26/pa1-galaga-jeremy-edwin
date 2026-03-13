#pragma once
#include "Hitbox.hpp"

class Math {
    public:
        Math() {}

        static double atan3(double y, double x) {
            double result = (180/PI) * atan2(y, x);
            return (result < 0) ? result + 360 : result;
        }

        static int sign(double x) { return (x > 0)? 1 : -1; }

        static float getDistance(std::pair<float, float> source, std::pair<float, float> target) {
            return sqrt(pow(source.first - target.first, 2) + 
                        pow(source.second - target.second, 2));
        }
};