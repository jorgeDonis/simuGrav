#include "Vec2.h"
#include <cmath>

Vec2 Vec2::operator+(const Vec2& b)
    {
        Vec2 result = Vec2();
        result.x = b.x + x;
        result.y = b.y + y;
            return result;
    }

Vec2& Vec2::operator=(const Vec2& b)
{
    if (this != &b)
    {
        delete this;
        this->x = b.x;
        this->y = b.y;
    }
    return *this;
}

Vec2::Vec2(const Vec2& b)
{
    this->x = b.y;
    this->y = b.y;
}

double Vec2::distance_to(const Vec2& b) const
{
    double x = b.x - this->x;
    double y = b.y - this->y;
    return sqrt(pow(x,2) + pow(y,2));
}

Vec2 Vec2::directionTo(const Vec2& b)
{
    double x = b.x - this->x;
    double y = b.y - this->y;
    double module = sqrt(pow(x,2) + pow(y,2));
    return Vec2(x / module, y / module);
}