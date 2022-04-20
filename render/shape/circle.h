#include <SDL2/SDL.h>

typedef struct circle {
    unsigned int center_x;
    unsigned int center_y;
    unsigned int radius;
} Circle;

void draw_circle(SDL_Renderer *renderer, Circle definition);