#include <iostream>
#include <vector>
#include <array>
#include <SDL2/SDL.h>

#include "tile.h"
#include "../ltexture.h"

Tile::Tile(int type, LTexture* texture)
{
    mType = type;
    mTexture = texture;
}

void Tile::render(SDL_Renderer* renderer, int x, int y)
{
    if (mTexture != NULL)
        mTexture->render(renderer, x, y);
}

int Tile::getType()
{
    return mType;
}
