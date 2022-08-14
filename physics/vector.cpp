#include "vector.h"

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector::Vector(coordinates coord) {
    this->x = coord.x;
    this->y = coord.y;
}

void Vector::update(coordinates values) {
    this->x = values.x;
    this->y = values.y;
}

void Vector::add_with(Vector v) {
    this->x += v.x;
    this->y += v.y;
}