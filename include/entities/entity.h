#ifndef ENTITIES_ENTITY_H
#define ENTITIES_ENTITY_H

#include "render/ltexture.h"
#include "physics/bodies.h"

class Entity
{
    public:

        // Initialise
        void init(LTexture* texture_);

        // Texture
        LTexture* texture;

        // Physics
        RigidBody body;
};

#endif
