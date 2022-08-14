#include "physicalObject.h"

#include <SDL2/SDL.h>

PhysicalObject::PhysicalObject() {
    this->velocity = new Vector(0, 0);
}

void PhysicalObject::set_velocity(coordinates values) {
    this->velocity->update(values);
}

void PhysicalObject::apply_velocity_transformation(Vector* velocity_transformation) {
    // SDL_Log("apply_velocity_transformation");
    // SDL_Log("current (%d, %d)", this->velocity->x, this->velocity->y);
    // SDL_Log("reaction (%d, %d)", velocity_transformation->x, velocity_transformation->y);

    this->velocity->add_with(*velocity_transformation);

//    SDL_Log("final (%d, %d)", this->velocity->x, this->velocity->y);
}

void PhysicalObject::update_position(int x_offset, int y_offset) {}
Bound PhysicalObject::is_over_bounds(Bounds* bounds) {return Bound::NONE;}