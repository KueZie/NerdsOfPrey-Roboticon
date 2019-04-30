#include "util/Transform2D.h"

Transform2D::Transform2D(double x, double y, double theta)
    : x(x), y(y), theta(theta)
{}

Transform2D::Transform2D()
    : x(0.0f), y(0.0f), theta(0.0f)
{}

Vec2D Transform2D::GetPosition()
{
    return Vec2D(x, y);
}

Transform2D Transform2D::Identity()
{
    return Transform2D();
}

Transform2D Transform2D::operator+(const Transform2D& other)
{}

Transform2D Transform2D::operator-(const Transform2D& other)
{}