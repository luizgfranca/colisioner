#include "physicalObject.h"

PhysicalObject::PhysicalObject() {
    this->velocity = {0, 0};
}

void PhysicalObject::set_velocity(Vector v) {
    this->velocity = v;
}

void PhysicalObject::update_position(int x_offset, int y_offset) {}