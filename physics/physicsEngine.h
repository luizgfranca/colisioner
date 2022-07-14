#pragma once

#include "physicalObject.h"
#include "colisionDetector.h"
#include "../environment.h"
#include <vector>

class PhysicsEngine {
    std::vector<int>* last_computed_moments;
    ColisionDetector* colision_detector;

public:
    PhysicsEngine();
    void compute(Environment* environment);
};