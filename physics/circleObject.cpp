#include "circleObject.h"

CircleObject::CircleObject(Circle* circle) {
    this->circle = circle;
    this->velocity = {0, 0};
}

void CircleObject::update_position(int x_offset, int y_offset) {
    this->circle->center->set_coordinates(
        this->circle->center->x + x_offset,
        this->circle->center->y + y_offset
    );
}