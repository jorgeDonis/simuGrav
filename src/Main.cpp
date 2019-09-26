#include <iostream>
#include <vector>
#include "MassObject.h"
#include "constants.h"
#include <cmath>
#include <curses.h>
#include <unistd.h>

using namespace std;

vector<MassObject> objects = vector<MassObject>(3);


void init()
{
    initscr();
    wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
    curs_set(0);
    Vec2 pos = Vec2(500e9, 250e9);
    Vec2 v = Vec2();
    MassObject sol = MassObject(pos, 4e30, v);
    pos = Vec2(500e9, 1.004e11);
    v = Vec2(3e4, 0);
    MassObject tierra = MassObject(pos, 6e24, v);
    pos = Vec2(500e9, 50.4e9);
    v = Vec2(-3e4, 0);
    MassObject marte = MassObject(pos, 3000e24, v);
    objects[0] = sol;
    objects[1] = tierra;
    objects[2] = marte;
}

Vec2 calculate_force(const MassObject& focus)
{
    Vec2 force = Vec2();
    for (MassObject& object : objects)
    {
        if (object != focus)
        {
            double r = focus.pos.distance_to(object.pos);
            double force_magnitude = G * (object.m * focus.m / pow(r,2));
            force = force + focus.pos.directionTo(object.pos) * force_magnitude;
        }
    }
    return force;
}

void print_universe()
{
    erase();
    for (MassObject& object : objects)
    {
        unsigned int text_i = TEXT_HEIGHT - (int) (object.pos.y / HEIGHT_PRINT_RATIO);
        unsigned int text_j = (int) (object.pos.x / WIDTH_PRINT_RATIO);
        mvwaddch(stdscr, text_i, text_j, PLANET_CHARACTER);
    }
    refresh();
}


int main()
{
    init();
    print_universe();
    for (int i = 0; i < 10000; i++)
    {
        usleep(MICROSECONDS_BETWEEN_PRINT);
        for (MassObject& object : objects)
        {
            //calculate position at delta t
            object.pos.x += object.v.x * SECONDS_BETWEEN_CALC;
            object.pos.y += object.v.y * SECONDS_BETWEEN_CALC;
            //calculate velocity at delta t
            Vec2 acc = calculate_force(object) / object.m;
            Vec2 final_v = acc * SECONDS_BETWEEN_CALC;
            object.v = object.v + final_v;
        }
        print_universe();
    }
    endwin();
    return 0;
}