#include <vector>
#include "engine.h"
#include "../config.cpp"
#include "shape/pixel.h"
#include "shape/circle.h"
#include "../lib/geometry/circle.h"
#include "../physics/physicalObject.h"
#include "../physics/circleObject.h"

RenderEngine::RenderEngine(SDL_Window* window) {
    this->surface = SDL_GetWindowSurface(window);
    this->renderer = SDL_CreateSoftwareRenderer(this->surface);
    
    SDL_RenderGetViewport(this->renderer, &this->viewPort);

    this->set_color_draw();
}

void RenderEngine::set_color_background() {
    SDL_SetRenderDrawColor(
        this->renderer, 
        BACKGROUND_COLOR_R, 
        BACKGROUND_COLOR_G, 
        BACKGROUND_COLOR_B, 
        BACKGROUND_COLOR_A
    );
}

void RenderEngine::set_color_draw() {
    SDL_SetRenderDrawColor(
        this->renderer, 
        DRAW_COLOR_R, 
        DRAW_COLOR_G, 
        DRAW_COLOR_B, 
        DRAW_COLOR_A
    );
}

void RenderEngine::clear() {
    this->set_color_background();

    SDL_RenderClear(this->renderer);
    
    this->set_color_draw();
}

void RenderEngine::render(Environment* environment) {
    this->clear();
    auto objects = environment->objects->data();

    for(size_t i = 0; i < environment->objects->size(); i ++) {
        auto circle_object = dynamic_cast<CircleObject*>(objects[i]);
        
        if(circle_object != nullptr) {
            draw_circle(
                this->renderer, 
                circle_object->circle
            );
        }
    }
}