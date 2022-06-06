#pragma once

#include "vector.h"

class PhysicalObject {
public:
    Vector velocity;
    PhysicalObject();
    void set_velocity(Vector v);
    virtual void update_position(int x_offset, int y_offset);
};