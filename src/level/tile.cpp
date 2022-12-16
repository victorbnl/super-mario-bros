#include "tile.h"

#include <iostream>
#include <vector>
#include <array>
#include <SDL2/SDL.h>

#include "../render/ltexture.h"

Tile::Tile(int type, LTexture* texture_)
{
    mType = type;
    texture = texture_;
}

int Tile::getType()
{
    return mType;
}
