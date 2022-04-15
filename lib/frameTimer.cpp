#include <SDL2/SDL.h>
#include "frameTimer.h"

#define MILISSECONDS_IN_SECOND 1000

void FrameTimer::start(unsigned int fps) {
    this->duration = MILISSECONDS_IN_SECOND / fps;
    this->start_ms = SDL_GetTicks();
}

bool FrameTimer::isDone() {
    return ( (SDL_GetTicks() - start_ms) >= this->duration );
}

FrameTimer* FrameTimer::build(unsigned int fps) {
    FrameTimer* f = new FrameTimer();
    f->start(fps);
    return f;
}