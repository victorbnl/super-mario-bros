#ifndef ENTITIES_CHARACTER_H
#define ENTITIES_CHARACTER_H

#include "entities/entity.h"

class Character : public Entity
{
    public:

        // Initialisation
        void init(LTexture* texture_);

        // Actions
        void stand();
        void walk(int direction);
        void jump();

        // For jumping
        bool isOnGround;
};

#endif
