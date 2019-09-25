#include <iostream>
#include <vector>
#include "MassObject.h"
#include "constants.h"
#include <cmath>

using namespace std;

vector<MassObject> objects;

void init()
{
    Vec2 pos = Vec2(500e9, 250e9);
    Vec2 v = Vec2();
    MassObject sol = MassObject(pos, 2e30, v);
    pos = Vec2(400e9, 0);
    v = Vec2(3e4, 0);
    MassObject tierra = MassObject(pos, 6e24, v);
    objects.push_back(sol);
    objects.push_back(tierra);
}

Vec2 calculate_force(const MassObject& focus)
{
    Vec2 force = Vec2();
    for (MassObject object : objects)
    {
        double force_magnitude = G * (object.m / pow(focus.pos.distance_to(object.pos),2));
        force = force + object.pos.directionTo(object.pos) * force_magnitude;
    }
    return force;
}



int main()
{
    init();
    for (int i = 0; i < 5; i++)
    {
        for (MassObject object : objects)
        {
            object.print();
            //calculate position at delta t
            object.pos.x += object.v.x * SECONDS_BETWEEN_CALC;
            object.pos.y += object.v.y * SECONDS_BETWEEN_CALC;
            //calculate velocity at delta t
            Vec2 acc = calculate_force(object) / object.m;
            Vec2 final_v = acc * SECONDS_BETWEEN_CALC;
            object.v = object.v + final_v;
        }
    }
    return 0;
}