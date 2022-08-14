#include <vector>
#include "physicalObject.h"
#include "colisionInformation.h"
#include "../environment.h"

class InteractionsResultEvaluator {
    Vector* reaction;

    void updateReactionVector(colision_information colision);

public:
    InteractionsResultEvaluator();

    void evaluate(
        Environment* Environment,
        std::vector<colision_information>* colisions
    );
};