#pragma once

#include "coordinates.h"

class Bounds {
public:
    int upper;
    int lower;
    int right;
    int left;

    void calculate_from_dimensions(coordinates dimensions);
    static Bounds* from_dimensions(coordinates dimensions);
};