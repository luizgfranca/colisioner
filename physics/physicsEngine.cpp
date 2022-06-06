#include <SDL2/SDL.h>
#include "physicsEngine.h"
#include "../config.cpp"
#include <vector>

PhysicsEngine::PhysicsEngine() {
    this->last_computed_moments = new std::vector<int>;
}

void PhysicsEngine::compute(Environment* environment) {
    for(size_t i = 0; i < environment->objects->size(); i ++) {
        unsigned int current_ticks = SDL_GetTicks();
        
        if(i >= this->last_computed_moments->size()) {
            this->last_computed_moments->push_back(current_ticks);
            continue;
        }
        
        unsigned int last_computed_moment = this->last_computed_moments->at(i);
        if( (last_computed_moment - current_ticks) >= MS_IN_TIME_UNIT) {
            auto object = environment->objects->at(i);
            auto elapsed_time = (current_ticks - last_computed_moment) / MS_IN_TIME_UNIT;
        
            object->update_position(
                object->velocity.x * elapsed_time,
                object->velocity.y * elapsed_time
            );

            last_computed_moment = current_ticks;
        }
    }
}