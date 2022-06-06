#pragma once

#include "physics/physicalObject.h"
#include <vector>

class Environment {
    unsigned int width;
    unsigned int height;  
public:
    std::vector<PhysicalObject*> *objects;

    Environment(unsigned int width, unsigned int height);
    void add_object(PhysicalObject* object);
};