#ifndef LEVEL_TILESET_H
#define LEVEL_TILESET_H

#include <array>

#include "../render/window.h"
#include "../render/ltexture.h"

class Tileset
{
    public:

        // Load textures
        void load(Window* window);

        // Get texture by index
        LTexture* get(int i);

    private:

        // Tileset array
        std::array<LTexture*, 4> mTileset;
};

#endif
