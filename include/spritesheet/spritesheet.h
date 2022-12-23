#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <array>

#include "constants.h"
#include "spritesheet/sprite.h"

class SpriteSheet
{
    public:

        void load(SDL_Renderer* renderer);

        Sprite* get(int i);

    private:

        std::array<Sprite, SPRITESHEET_LENGTH> sprites;
};

#endif
