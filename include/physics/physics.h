#ifndef PHYSICS_PHYSICS_H
#define PHYSICS_PHYSICS_H

#include "character.h"
#include "structures.h"
#include "level/level.h"
#include "collisions/collisions.h"

class PhysicsEngine
{
    public:

        // Initialisation
        void init(Character* character, Level* level, Rectangle levelBoundaries);

        // Update
        void update();

    private:

        Character* mCharacter;
        Level* mLevel;
        CollisionsEngine mCollisions;
};

#endif
