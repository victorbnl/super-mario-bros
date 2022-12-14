#ifndef LEVEL_TILE_H
#define LEVEL_TILE_H

#include <vector>
#include <fstream>

#include "../ltexture.h"

class Tile
{
    public:

        // Constructor
        Tile(int type, LTexture* texture);

        // Render
        void render(SDL_Renderer* renderer, int x, int y);

        // Get tile type
        int getType();

    private:

        // Type
        int mType;

        // Texture
        LTexture* mTexture;
};

#endif
