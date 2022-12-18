#ifndef PHYSICS_COLLISIONS_COLLISIONS_H
#define PHYSICS_COLLISIONS_COLLISIONS_H

#include "../../character.h"
#include "../../level/level.h"
#include "../../structures.h"

class CollisionsEngine
{
    public:

        // Initialisation
        void init(Character* character, Level* level, Rectangle levelBoundaries);

        // Update
        void solveX();
        void solveY();

    private:

        Character* mCharacter;
        Level* mLevel;
        Rectangle mLevelBoundaries;
};

#endif
