#pragma once

#include "physicalObject.h"
#include "../environment.h"
#include <vector>

class PhysicsEngine {
    std::vector<int>* last_computed_moments;

public:
    PhysicsEngine();
    void compute(Environment* environment);
};