#ifndef MASS_OBJECT
#define MASS_OBJECT

class MassObject
{
    private:
        double m;
        double vx;
        double vy;
    public:
        MassObject() { m = vx = vy = 0; }
};

#endif