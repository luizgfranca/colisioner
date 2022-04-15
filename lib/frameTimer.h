#pragma once

class FrameTimer {
    int start_ms;
    unsigned int duration;
    
    public:
        void start(unsigned int fps);
        bool isDone();

        static FrameTimer* build(unsigned int fps);
};