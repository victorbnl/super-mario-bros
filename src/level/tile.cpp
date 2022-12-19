#include "level/tile.h"

#include <iostream>
#include <vector>
#include <array>
#include <SDL2/SDL.h>

#include "render/ltexture.h"
#include "constants.h"

Tile::Tile(int x, int y, int type_, LTexture* texture_)
{
    // Initialise texture
    type = type_;
    texture = texture_;

    // Initialise rigid body
    body.x = x;
    body.y = y;
    body.collider.w = TILE_SIZE;
    body.collider.h = TILE_SIZE;
}
