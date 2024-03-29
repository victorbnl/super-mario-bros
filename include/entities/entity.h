#ifndef ENTITIES_ENTITY_H
#define ENTITIES_ENTITY_H

#include "physics/bodies.h"

class Entity
{
    public:

        // Texture
        int sprite;

        // Physics
        RigidBody body;
};

#endif
