#ifndef LEVEL_TILE_H
#define LEVEL_TILE_H

#include <vector>
#include <fstream>

#include "../render/ltexture.h"

class Tile
{
    public:

        // Constructor
        Tile(int type, LTexture* texture_);

        // Get tile type
        int getType();

        // Texture
        LTexture* texture;

    private:

        // Type
        int mType;
};

#endif
