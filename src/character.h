#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <SDL2/SDL.h>

#include "render/ltexture.h"
#include "structs.h"
#include "camera.h"

class Character
{
    public:

        // Constructor
        Character();

        // Load texture
        void init(LTexture* texture_);

        // Move character
        void moveX(int direction);
        void moveY(int direction);

        // Jump
        void jump();

        // Get collider
        Rectangle getCollider();

        // Update character's collider
        void updateCollider();

        // Texture
        LTexture* texture;

        // Character position
        Coordinates pos;

        // Character velocity
        Velocity vel;

    private:

        // Collider
        Rectangle mCollider;
};

#endif
