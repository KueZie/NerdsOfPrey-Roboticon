#pragma once

#include "util/Vec2D.h"

struct Transform2D
{
    double x, y, theta;
    Transform2D(double x, double y, double theta);
    Transform2D();
    Vec2D GetPosition();
    static Transform2D Identity();
    Transform2D operator+(const Transform2D& other);
    Transform2D operator-(const Transform2D& other);
    void operator+=(const Transform2D& other);
    void operator-=(const Transform2D& other);
}