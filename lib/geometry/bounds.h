#pragma once

#include "coordinates.h"

enum Bound {
    NONE,
    UPPER,
    LOWER,
    RIGHT,
    LEFT
};

class Bounds {
public:
    int upper;
    int lower;
    int right;
    int left;

    void calculate_from_dimensions(coordinates dimensions);
    static Bounds* from_dimensions(coordinates dimensions);
};