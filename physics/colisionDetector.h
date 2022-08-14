#include <vector>
#include "../lib/geometry/bounds.h"
#include "../environment.h"
#include "physicalObject.h"
#include "vector.h"
#include "colisionInformation.h"


class ColisionDetector {
    Environment* environment;
    std::vector<colision_information>* colisions;

    void evaluate_wall_colisions();
    Bound is_coliding_with_wall(PhysicalObject* object, Bounds* bounds);

public:
    ColisionDetector();
    void set_environment(Environment* environment);
    std::vector<colision_information>* evaluate_colisions();
    void reset();
};