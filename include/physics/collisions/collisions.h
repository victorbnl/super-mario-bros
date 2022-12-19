#ifndef PHYSICS_COLLISIONS_COLLISIONS_H
#define PHYSICS_COLLISIONS_COLLISIONS_H

#include "character.h"
#include "level/level.h"

class CollisionsEngine
{
    public:

        // Initialisation
        void init(Character* character, Level* level);

        // Update
        void solveX();
        void solveY();

    private:

        Character* mCharacter;
        Level* mLevel;
};

#endif
