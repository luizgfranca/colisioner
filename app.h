#include <SDL2/SDL.h>
#include "lib/frameTimer.h"
#include "config.cpp"
#include "environment.h"
#include "render/engine.h"
#include "physics/physicsEngine.h"

class App {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    SDL_Event sdl_event;

    FrameTimer* frame_timer;
    RenderEngine* render_engine;
    PhysicsEngine* physics_engine;
    Environment* environment;
    bool is_running;

    void create_window();
    void setup_application();
    void create_initial_state();
    void loop();

    public:
        void init();
};