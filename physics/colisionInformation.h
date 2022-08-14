#pragma once

#include "physicalObject.h"
#include "../lib/geometry/bounds.h"

enum ColisionType {
    COLISION_WITH_WALL
};

typedef struct colision_information {
    ColisionType colision_type;
    PhysicalObject* viewpoint_object;
    PhysicalObject* other_object;
    Bound violated_bound;
} colision_information;