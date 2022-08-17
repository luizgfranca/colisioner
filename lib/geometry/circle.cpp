#include "circle.h"
#include <cstdlib>

Circle::Circle(Point *center, unsigned int radius) {
    this->center = center;
    this->radius = radius;
}

Circle::Circle(unsigned int center_x, unsigned int center_y, unsigned int radius) {
    this->center = new Point(center_x, center_y);
    this->radius = radius;
}

int** Circle::get_shape_limits() {
    int** limits;

    limits = (int**) malloc(ORIENTATIONS_2D * sizeof(unsigned int *));
    for(int i = 0; i < ORIENTATIONS_2D; i ++) {
        limits[i] = (int*) malloc(2 * sizeof(int));
    }

    limits[ORIENTATION_HORIZONTAL][MIN] = this->center->x - radius;
    limits[ORIENTATION_HORIZONTAL][MAX] = this->center->x + radius;

    limits[ORIENTATION_VERTICAL][MIN] = this->center->y - radius;
    limits[ORIENTATION_VERTICAL][MAX] = this->center->y + radius;

    return limits;
}