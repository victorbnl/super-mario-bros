#ifndef WORLD_H
#define WORLD_H

#include "level/level.h"
#include "entities/character.h"

class World
{
    public:

        // Methods
        World();

        // Attributes
        int backgroundSprite;
        Level level;
        Character character;
};

#endif
