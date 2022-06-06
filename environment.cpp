#include "environment.h"

Environment::Environment(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    this->objects = new std::vector<PhysicalObject*>();
}

void Environment::add_object(PhysicalObject* object) {
    this->objects->push_back(object);
}