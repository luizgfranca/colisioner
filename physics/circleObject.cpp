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

bool CircleObject::is_over_bounds(Bounds* bounds) {
    auto virtual_point = new Point(0,0);

    virtual_point->set_coordinates(this->circle->center->x, bounds->upper);
    if(this->circle->center->get_distance_from(*virtual_point) <= this->circle->radius)
        return true;

    virtual_point->set_coordinates(bounds->right, this->circle->center->y);
    if(this->circle->center->get_distance_from(*virtual_point) <= this->circle->radius)
        return true;

    virtual_point->set_coordinates(this->circle->center->x, bounds->lower);
    if(this->circle->center->get_distance_from(*virtual_point) <= this->circle->radius)
        return true;

    virtual_point->set_coordinates(bounds->left, this->circle->center->y);
    if(this->circle->center->get_distance_from(*virtual_point) <= this->circle->radius)
        return true;

    return false;
}