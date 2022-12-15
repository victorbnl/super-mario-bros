#ifndef PHYSICS_PHYSICS_H
#define PHYSICS_PHYSICS_H

#include "../character.h"
#include "../level/level.h"

class PhysicsEngine
{
    public:

        // Initialisation
        void init(Character* character);

        // Update
        void update();

    private:

        Character* mCharacter;
};

#endif
