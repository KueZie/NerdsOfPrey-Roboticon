#pragma once

#include "Constants.h"

namespace functions
{
    double clamp(double n, double min, double max);
    double normalize(double n);
    double to_radians(double degrees);
    double to_degrees(double radians);
}