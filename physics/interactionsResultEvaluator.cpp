#include "InteractionsResultEvaluator.h"
#include "../lib/geometry/bounds.h"

#include <SDL2/SDL.h>

InteractionsResultEvaluator::InteractionsResultEvaluator() {
    this->reaction = new Vector(0,0);
}

void InteractionsResultEvaluator::updateReactionVector(
    colision_information colision
) {
    switch (colision.violated_bound)
    {
    case Bound::UPPER:
        this->reaction->update({0, 1});
        break;
    
    case Bound::RIGHT:
        this->reaction->update({-1, 0});
        break;
    
    case Bound::LOWER:
        this->reaction->update({0, -1});
        break;

    case Bound::LEFT:
        this->reaction->update({1, 0});
        break;

    default:
        break;
    }
}

void InteractionsResultEvaluator::evaluate(
    Environment* Environment,
    Colisions* colisions
) {
    for(unsigned int i = 0; i < colisions->count(); i ++) {
        auto colision = colisions->get(i);
        if(colision.colision_type == ColisionType::COLISION_WITH_WALL) {   
            this->updateReactionVector(colision);
            colision.viewpoint_object->apply_velocity_transformation(this->reaction);
        }
    }
}