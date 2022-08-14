#include "app.h"
#include "lib/geometry/circle.h"
#include "physics/physicalObject.h"
#include "physics/circleObject.h"

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
    this->environment = new Environment(WINDOW_DETAULT_WITDH, WINDOW_DEFAULT_HEIGHT);
    this->physics_engine = new PhysicsEngine();
    this->create_initial_state();
}

void App::create_initial_state() {
    auto circle = new CircleObject(new Circle(
        WINDOW_DETAULT_WITDH / 2,
        WINDOW_DEFAULT_HEIGHT / 2,
        50
    ));

    circle->set_velocity({10, 9});

    this->environment->add_object(circle);
}

void App::loop() {
    while (this->is_running)
    {
        if(!this->frame_timer->isDone())
            continue;

        this->frame_timer->start(FRAMES_PER_SECOND);

        if( SDL_PollEvent(&this->sdl_event) && this->sdl_event.type == SDL_QUIT )
            this->is_running = false;

        this->physics_engine->compute(this->environment);
        this->render_engine->render(this->environment);

        SDL_UpdateWindowSurface(this->window);
    }
    
}