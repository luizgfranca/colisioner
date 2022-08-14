#pragma once
#include "../lib/geometry/coordinates.h"

class Vector {
    
public:
    int x;
    int y;

    Vector(int x, int y);
    Vector(coordinates coord);

    void update(coordinates values);
    void add_with(Vector v);
};