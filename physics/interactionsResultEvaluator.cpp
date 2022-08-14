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
        //SDL_Log("UPPER bound colision, updating reaction");
        this->reaction->update({0, 1});
        break;
    
    case Bound::RIGHT:
        //SDL_Log("RIGHT bound colision, updating reaction");
        this->reaction->update({-1, 0});
        break;
    
    case Bound::LOWER:
        //SDL_Log("LOWER bound colision, updating reaction");
        this->reaction->update({0, -1});
        break;

    case Bound::LEFT:
        // SDL_Log("LEFT bound colision, updating reaction");
        this->reaction->update({1, 0});
        break;

    default:
        break;
    }
}

void InteractionsResultEvaluator::evaluate(
    Environment* Environment,
    std::vector<colision_information>* colisions
) {
    for(unsigned int i = 0; i < colisions->size(); i ++) {
        auto colision = colisions->at(i);
        if(colision.colision_type == ColisionType::COLISION_WITH_WALL) {   
            this->updateReactionVector(colision);
            colision.viewpoint_object->apply_velocity_transformation(this->reaction);
        }
    }
}