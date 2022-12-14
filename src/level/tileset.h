#ifndef LEVEL_TILESET_H
#define LEVEL_TILESET_H

#include <array>

#include "../ltexture.h"

class Tileset
{
    public:

        // Load textures
        void load(SDL_Renderer* renderer);

        // Get texture by index
        LTexture* get(int i);

    private:

        // Tileset array
        std::array<LTexture, 4> mTileset;
};

#endif
