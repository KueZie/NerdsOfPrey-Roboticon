#pragma once

#include <cmath>

#include "util/Functions.h"

struct Rotation2D
{
    double value, sin, cos;
    Rotation2D(double value) : Rotation2D(std::cos(value), std::sin(value), true) {}
    Rotation2D(double x, double y, bool normalize)
    {
        if (normalize)
        {
            double mag = std::hypot(x, y);
            if (mag > 1e-9)
            {
                sin = y / mag;
                cos = x / mag;
            }
            else
            {
                sin = 0.0f;
                cos = 1.0f;
            }
        }
        else
        {
            cos = x;
            sin = y;
        }
        value = std::atan2(sin, cos);
    }
    double GetRadians() { return value; }
    double GetDegrees() { return functions::to_degrees(value); }
}