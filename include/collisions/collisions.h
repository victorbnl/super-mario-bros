#ifndef PHYSICS_COLLISIONS_COLLISIONS_H
#define PHYSICS_COLLISIONS_COLLISIONS_H

#include "entities/character.h"
#include "level/level.h"

class CollisionsEngine
{
    public:

        // Initialisation
        void init(Character* character, Level* level);

        // Update
        void solve();

    private:

        Character* mCharacter;
        Level* mLevel;
};

#endif
