#include <SDL2/SDL.h>

class RenderEngine {

    SDL_Renderer *renderer;
    SDL_Surface *surface;

public:
    RenderEngine(SDL_Window* window);
    void execute();
};