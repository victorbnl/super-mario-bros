#ifndef TILES_INCLUDE_GUARD
#define TILES_INCLUDE_GUARD

#include <vector>
#include <fstream>

#include "../ltexture.h"

class Tile
{
    public:

        // Constructor
        Tile(LTexture* texture);

        // Render
        void render(SDL_Renderer* renderer, int x, int y);

    private:

        // Texture
        LTexture* mTexture;
};

// Get texture set
LTexture* getTileSet(SDL_Renderer* renderer);

#endif
