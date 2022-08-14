#pragma once

#include "../lib/geometry/circle.h"
#include "../lib/geometry/coordinates.h"
#include "vector.h"
#include "physicalObject.h"

class CircleObject : public PhysicalObject {  
public:
    Circle *circle;
    
    CircleObject(Circle* circle);
    void update_position(int x_offset, int y_offset);
    Bound is_over_bounds(Bounds* bounds);
};