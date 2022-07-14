#include "bounds.h"

Bounds* Bounds::from_dimensions(coordinates dimensions) {
    auto bounds = new Bounds();
    bounds->calculate_from_dimensions(dimensions);
    return bounds;
}

void Bounds::calculate_from_dimensions(coordinates dimensions) {
    this->upper = 0;
    this->right = dimensions.x;
    this->lower = dimensions.y;
    this->left = 0;
}