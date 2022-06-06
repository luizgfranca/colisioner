#include <SDL2/SDL.h>
#include "../environment.h"

class RenderEngine {

    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Rect viewPort;

public:
    RenderEngine(SDL_Window* window);
    void set_color_background();
    void set_color_draw();
    void render(Environment* environment);
    void clear();
};