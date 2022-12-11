#ifndef TILES_INCLUDE_GUARD
#define TILES_INCLUDE_GUARD

#include <vector>
#include <fstream>

#include "ltexture.h"

class Tile
{
    public:

        // Constructor
        Tile(int x, int y, LTexture* texture);

        // Render
        void render(SDL_Renderer* renderer);

    private:

        // Texture
        LTexture* mTexture;

        // Position
        int mPosX, mPosY;
};

LTexture* getTileSet(SDL_Renderer* renderer);

std::vector<Tile*> getTiles(SDL_Renderer* renderer);

#endif
