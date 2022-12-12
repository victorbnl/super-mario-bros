#include <iostream>
#include <vector>
#include <array>
#include <SDL2/SDL.h>

#include "tiles.h"
#include "../ltexture.h"

Tile::Tile(LTexture* texture)
{
    mTexture = texture;
}

void Tile::render(SDL_Renderer* renderer, int x, int y)
{
    if (mTexture != NULL)
        mTexture->render(renderer, x, y);
}

LTexture* getTileSet(SDL_Renderer* renderer)
{
    static LTexture tileSet[4] = {
        LTexture(),
        LTexture(),
        LTexture(),
        LTexture()
    };

    tileSet[0].loadFromFile(renderer, "assets/textures/grass.png");
    tileSet[1].loadFromFile(renderer, "assets/textures/dirt.png");
    tileSet[2].loadFromFile(renderer, "assets/textures/bricks.png");
    tileSet[3].loadFromFile(renderer, "assets/textures/luck.png");

    return tileSet;
}


