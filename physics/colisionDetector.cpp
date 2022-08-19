#include "colisionDetector.h"
#include "../lib/geometry/coordinates.h"
#include "SDL2/SDL.h"

ColisionDetector::ColisionDetector() {
    this->colisions = new Colisions();
}

void ColisionDetector::set_environment(Environment* e) {
    this->environment = e;
}

void ColisionDetector::reset() {
    this->colisions->reset();
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
                (int) i,
                NULL,
                -1,
                violated_bound
            };
            
            this->colisions->add_colision(colision);
        }
            
    }
}

Colisions* ColisionDetector::evaluate_colisions() {
    this->evaluate_wall_colisions();
    return this->colisions;
}