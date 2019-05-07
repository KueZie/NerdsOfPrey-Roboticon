#pragma once

#include <cmath>

struct Translation2D
{
    double x, y;
    Translation2D() : x(0.0f), y(0.0f) {}
    Translation2D(double x, double y) : x(x), y(y) {}
    Translation2D();
    double Distance(const Translation2D& other) { return std::hypot(x - other.x, y - other.y); }
    Translation2D& operator+(const Translation2D& other) { return Translation2D(x + other.x, y + other.y); } 
    Translation2D& operator-(const Translation2D& other) { return Translation2D(x - other.x, y - other.y); }
}