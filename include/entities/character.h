#ifndef ENTITIES_CHARACTER_H
#define ENTITIES_CHARACTER_H

#include "entities/entity.h"
#include "spritesheet/sprite.h"

class Character : public Entity
{
    public:

        // Constructor
        Character();

        // Actions
        void stand();
        void walk(int direction);
        void jump();

        // For jumping
        bool isOnGround;
};

#endif
