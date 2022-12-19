#include "level/tile.h"

#include <vector>

#include "constants.h"
#include "render/ltexture.h"

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
