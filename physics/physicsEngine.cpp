#include <SDL2/SDL.h>
#include "physicsEngine.h"
#include "../config.cpp"
#include <vector>

PhysicsEngine::PhysicsEngine() {
    this->last_computed_moments = new std::vector<int>;
    this->colision_detector = new ColisionDetector();
    this->interactions_result_evaluator = new InteractionsResultEvaluator();
}

void PhysicsEngine::compute(Environment* environment) {
    this->colision_detector->reset();
    this->colision_detector->set_environment(environment);

    auto colisions = this->colision_detector->evaluate_colisions();
    this->interactions_result_evaluator->evaluate(environment, colisions);

    for(size_t i = 0; i < environment->objects->size(); i ++) {
        unsigned int current_ticks = SDL_GetTicks();
        
        if(i >= this->last_computed_moments->size()) {
            this->last_computed_moments->push_back(current_ticks);
            continue;
        }
        
        unsigned int last_computed_moment = this->last_computed_moments->at(i);
        auto elapsed_time = (current_ticks - last_computed_moment) / MS_IN_TIME_UNIT;
        if(elapsed_time >= 1) {
            auto object = environment->objects->at(i);
            
            object->update_position(
                object->velocity->x * elapsed_time,
                object->velocity->y * elapsed_time
            );

            this->last_computed_moments->at(i) = current_ticks;
        }
    }
}