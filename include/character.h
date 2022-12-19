#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <SDL2/SDL.h>

#include "render/ltexture.h"
#include "geometry.h"
#include "camera.h"
#include "physics/bodies.h"

class Character
{
    public:

        // Initialise
        void init(LTexture* texture_);

        // Actions
        void stand();
        void walk(int direction);
        void jump();

        // Rendering
        LTexture* texture;

        // Physics
        RigidBody body;
        RigidBody oldBody;
};

#endif
