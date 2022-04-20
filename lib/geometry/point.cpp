#include "point.h"
#include <cmath>

Point::Point(int x, int y) {
    this->set_coordinates(x, y);
}

void Point::set_coordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

int * Point::get_coordinates() {
    static int coord[] = {x, y};
    return coord;
}

unsigned int Point::get_distance_from(Point b) {
    float total = sqrt(
        pow((double) (this->x - b.x), 2) + 
        pow((double) (this->y - b.y), 2)
    );

    return (unsigned int) ceil(total);
}