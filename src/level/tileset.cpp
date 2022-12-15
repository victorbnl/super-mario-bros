#include "tileset.h"

#include <SDL2/SDL.h>

#include "../ltexture.h"

void Tileset::load(SDL_Renderer* renderer)
{
    std::string prefix = "assets/textures/";
    std::string ext = ".png";

    mTileset[0].loadFromFile(renderer, prefix + "grass" + ext);
    mTileset[1].loadFromFile(renderer, prefix + "dirt" + ext);
    mTileset[2].loadFromFile(renderer, prefix + "bricks" + ext);
    mTileset[3].loadFromFile(renderer, prefix + "luck" + ext);
}

LTexture* Tileset::get(int type)
{
    return &(mTileset[type]);
}
