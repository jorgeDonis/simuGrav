#include "MassObject.h"
#include <iostream>
using namespace std;

void MassObject::print()
{
    cout << scientific  << "[" << pos.x << "," << pos.y << "]" << endl;
}

bool MassObject::operator==(const MassObject& b) const
{
    return (this->m == b.m && this->pos == b.pos && v == b.v);
}

bool MassObject::operator!=(const MassObject& b) const
{
    return !(b == *this);
}
