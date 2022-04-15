#include <SDL2/SDL.h>
#include "lib/frameTimer.h"
#include "config.cpp"
#include "render/engine.h"

class App {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    SDL_Event sdl_event;

    FrameTimer* frame_timer;
    RenderEngine* render_engine;
    bool is_running;

    void create_window();
    void setup_application();
    void loop();

    public:
        void init();
};