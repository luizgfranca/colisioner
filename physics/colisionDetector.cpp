#include "colisionDetector.h"
#include "../lib/geometry/coordinates.h"
#include "SDL2/SDL.h"

ColisionDetector::ColisionDetector() {
    this->coliding_objects = new std::vector<PhysicalObject*>();
}

void ColisionDetector::set_environment(Environment* e) {
    this->environment = e;
}

void ColisionDetector::reset() {
    this->coliding_objects->clear();
}

bool ColisionDetector::is_coliding_with_wall(PhysicalObject* object, Bounds* bounds) {
    return object->is_over_bounds(bounds);
}

void ColisionDetector::evaluate_wall_colisions() {
    auto dimensions = this->environment->get_dimensions();
    auto bounds = Bounds::from_dimensions(dimensions);

    for(unsigned int i = 0; i < this->environment->objects->size(); i ++) {
        auto object = this->environment->objects->at(i);

        if(is_coliding_with_wall(object, bounds))
            this->coliding_objects->push_back(object);
    }

    SDL_Log("coliding objects %ld", this->coliding_objects->size());
}

std::vector<PhysicalObject*>* ColisionDetector::evaluate_colisions() {
    this->evaluate_wall_colisions();
    return this->coliding_objects;
}