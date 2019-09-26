#ifndef MASS_OBJECT
#define MASS_OBJECT
#include "Vec2.h"

class MassObject
{
    private:
    public:
        Vec2 pos;
        long double m;
        Vec2 v;
        MassObject() { m = 0; }
        MassObject(Vec2& pos, long double m, Vec2& v)
        {
            this->pos = pos;
            this->m = m;
            this->v = v;
        }
        bool operator==(const MassObject&) const;
        bool operator!=(const MassObject&) const;
        void print();
};

#endif