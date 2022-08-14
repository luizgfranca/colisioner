#pragma once

#include "physicalObject.h"
#include "colisionDetector.h"
#include "../environment.h"
#include <vector>
#include "InteractionsResultEvaluator.h"

class PhysicsEngine {
    std::vector<int>* last_computed_moments;
    ColisionDetector* colision_detector;
    InteractionsResultEvaluator* interactions_result_evaluator;

public:
    PhysicsEngine();
    void compute(Environment* environment);
};