#include "pixel.h"

void draw_pixel(SDL_Renderer *renderer, unsigned int x, unsigned int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}