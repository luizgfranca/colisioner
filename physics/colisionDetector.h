#include <vector>
#include "../lib/geometry/bounds.h"
#include "../environment.h"
#include "physicalObject.h"
#include "vector.h"


class ColisionDetector {
    Environment* environment;
    std::vector<PhysicalObject*>* coliding_objects;

    void evaluate_wall_colisions();
    bool is_coliding_with_wall(PhysicalObject* object, Bounds* bounds);

public:
    ColisionDetector();
    void set_environment(Environment* environment);
    std::vector<PhysicalObject*>* evaluate_colisions();
    void reset();
};