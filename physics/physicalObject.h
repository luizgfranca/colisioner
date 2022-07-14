#pragma once

#include "vector.h"
#include "../lib/geometry/coordinates.h"
#include "../lib/geometry/bounds.h"

class PhysicalObject {
public:
    Vector velocity;
    PhysicalObject();
    void set_velocity(Vector v);
    virtual void update_position(int x_offset, int y_offset);
    virtual bool is_over_bounds(Bounds* bounds);
};