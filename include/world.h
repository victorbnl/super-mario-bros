#ifndef WORLD_H
#define WORLD_H

#include "level/level.h"
#include "entities/character.h"
#include "render/ltexture.h"
#include "render/window.h"

class World
{
    public:

        // Methods
        void init(Window* window);
        void render(Window* window, int cameraX);

        // Attributes
        LTexture* backgroundTexture;
        Level level;
        Character character;
};

#endif
