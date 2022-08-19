#pragma once

#include "physicalObject.h"
#include "../lib/geometry/bounds.h"
#include <vector>

enum ColisionType {
    COLISION_WITH_WALL
};

typedef struct colision_information {
    ColisionType colision_type;
    PhysicalObject* viewpoint_object;
    int viewpoint_object_index;
    PhysicalObject* other_object;
    int other_object_index;
    Bound violated_bound;
} colision_information;

class Colisions {
public:
    Colisions();
    std::vector<colision_information>* items;
    void add_colision(colision_information colision);
    void reset();
    bool is_coliding(PhysicalObject* object);
    unsigned int count();
    colision_information get(unsigned int k);
};
