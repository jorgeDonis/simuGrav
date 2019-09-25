#include "MassObject.h"
#include <iostream>
using namespace std;

void MassObject::print()
{
    cout << scientific  << "[" << pos.x << "," << pos.y << "]" << endl;
}