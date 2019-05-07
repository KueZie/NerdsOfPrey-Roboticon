#pragma once

#include "Constants.h"
#include "Units.hpp"

namespace functions
{
    double clamp(double n, double min, double max);
    double normalize(double n);
    double to_radians(double degrees);
    double to_degrees(double radians);
    double angle_from_ticks(double ticks, double gearRatio, double ticksPerRevolution);
}