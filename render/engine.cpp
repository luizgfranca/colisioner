#include "engine.h"
#include "../config.cpp"
#include "shape/pixel.h"
#include "shape/circle.h"


RenderEngine::RenderEngine(SDL_Window* window) {
    this->surface = SDL_GetWindowSurface(window);
    this->renderer = SDL_CreateSoftwareRenderer(this->surface);

    SDL_SetRenderDrawColor(
        this->renderer, 
        DRAW_COLOR_R, 
        DRAW_COLOR_G, 
        DRAW_COLOR_B, 
        DRAW_COLOR_A
    );
}

void RenderEngine::execute() {
    Circle c;
    c.center_x = this->surface->w / 2;
    c.center_y = this->surface->h / 2;
    c.radius = 100;

    draw_circle(this->renderer, c);
}