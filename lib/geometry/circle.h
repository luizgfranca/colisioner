#pragma once

#include "reference.h"
#include "point.h"

class Circle {
    
public:
    Point *center;
    unsigned int radius;

    Circle(Point *center, unsigned int radius);
    Circle(unsigned int center_x, unsigned int center_y, unsigned int radius);

    unsigned int** get_shape_limits();
};