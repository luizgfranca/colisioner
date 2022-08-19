#include "colisionInformation.h"

Colisions::Colisions() {
    this->items = new std::vector<colision_information>();
}

void Colisions::add_colision(colision_information colision) {
    this->items->push_back(colision);
}

void Colisions::reset() {
    this->items->clear();
}

bool Colisions::is_coliding(PhysicalObject* object) {
    for(unsigned int i = 0; i < this->items->size(); i ++) {
        if(this->items->at(i).viewpoint_object == object) {
            return true;
        }
    }

    return false;
}

unsigned int Colisions::count() {
    return this->items->size();
}

colision_information Colisions::get(unsigned int k) {
    return this->items->at(k);
}