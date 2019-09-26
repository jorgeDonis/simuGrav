#ifndef VEC2
#define VEC2

class Vec2
{
    public:
        double x;
        double y;
        Vec2(double x, double y){this->x = x; this->y = y;}
        Vec2(){x = 0; y = 0;}
        ~Vec2(){;}
        Vec2(const Vec2&);
        Vec2 operator+(const Vec2&);
        Vec2& operator=(const Vec2&);
        Vec2 directionTo(const Vec2&) const;
        Vec2 operator*(const double& scalar){return Vec2(x * scalar, y*scalar);}
        Vec2 operator/(const double& scalar){return Vec2(x / scalar, y/scalar);}
        double distance_to(const Vec2&) const;
        bool operator==(const Vec2&) const;
        bool operator!=(const Vec2&) const;
};

#endif