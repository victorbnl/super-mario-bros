#ifndef PHYSICS_PHYSICS_H
#define PHYSICS_PHYSICS_H

#include "entities/character.h"
#include "level/level.h"

class PhysicsEngine
{
    public:

        // Initialisation
        void init(Character* character, Level* level);

        // Update
        void update();

    private:

        Character* mCharacter;
        Level* mLevel;
};

#endif
