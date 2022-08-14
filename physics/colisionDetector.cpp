#include "colisionDetector.h"
#include "../lib/geometry/coordinates.h"
#include "SDL2/SDL.h"

ColisionDetector::ColisionDetector() {
    this->colisions = new std::vector<colision_information>();
}

void ColisionDetector::set_environment(Environment* e) {
    this->environment = e;
}

void ColisionDetector::reset() {
    this->colisions->clear();
}

Bound ColisionDetector::is_coliding_with_wall(PhysicalObject* object, Bounds* bounds) {
    return object->is_over_bounds(bounds);
}

void ColisionDetector::evaluate_wall_colisions() {
    auto dimensions = this->environment->get_dimensions();
    auto bounds = Bounds::from_dimensions(dimensions);

    for(unsigned int i = 0; i < this->environment->objects->size(); i ++) {
        auto object = this->environment->objects->at(i);
        auto violated_bound = is_coliding_with_wall(object, bounds);

        if(violated_bound != Bound::NONE) {
            colision_information colision = {
                ColisionType::COLISION_WITH_WALL,
                object,
                NULL,
                violated_bound
            };
            
            this->colisions->push_back(colision);
        }
            
    }

    //SDL_Log("coliding objects %ld", this->colisions->size());
}

std::vector<colision_information>* ColisionDetector::evaluate_colisions() {
    this->evaluate_wall_colisions();
    return this->colisions;
}