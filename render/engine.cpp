#include "engine.h"
#include "../config.cpp"
#include "pixel.h"

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
    draw_pixel(this->renderer, this->surface->w / 2, this->surface->h / 2);
}