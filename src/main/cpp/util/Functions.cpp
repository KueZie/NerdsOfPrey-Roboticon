#include "util/Functions.h"

namespace functions
{
    double clamp(double n, double min, double max)
    {
        if (n < min) return min;
        else if (n > max) return max;
        else return n;
    }

    double normalize(double n)
    {
        return clamp(n, -1.0f, 1.0f);
    }

    double to_radians(double degrees)
    {
        return (degrees * constants::PI) / 180.0f;
    }

    double to_degrees(double radians)
    {
        return (radians * 180.0f) / constants::PI;
    }

    double angle_from_ticks(double ticks, double gearRatio, double ticksPerRevolution)
    {
        return ticks * gearRatio * (360 / ticksPerRevolution);
    }
}