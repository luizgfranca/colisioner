#include "app.h"


void App::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->setup_application();
    this->loop();
}

void App::create_window() {
    this->window = SDL_CreateWindow(
        APP_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        WINDOW_DETAULT_WITDH, 
        WINDOW_DEFAULT_HEIGHT, 
        SDL_WINDOW_RESIZABLE
    );

    this->surface = SDL_GetWindowSurface(this->window);
    this->renderer = SDL_CreateSoftwareRenderer(this->surface);
}

void App::setup_application() {
    this->is_running = true;
    this->create_window();
    this->frame_timer = FrameTimer::build(FRAMES_PER_SECOND);
    this->render_engine = new RenderEngine(this->window);
}

void App::loop() {
    while (this->is_running)
    {
        if(!this->frame_timer->isDone())
            continue;

        this->frame_timer->start(FRAMES_PER_SECOND);

        if( SDL_PollEvent(&this->sdl_event) && this->sdl_event.type == SDL_QUIT )
            this->is_running = false;

        this->render_engine->execute();

        SDL_UpdateWindowSurface(this->window);
    }
    
}