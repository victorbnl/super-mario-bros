#include "level/tile.h"

#include <vector>

#include "constants.h"

Tile::Tile(int x, int y, int sprite_)
{
    // Initialise rigid body
    body.x = x;
    body.y = y;
    body.collider.w = TILE_SIZE;
    body.collider.h = TILE_SIZE;

    // Initialise texture
    sprite = sprite_;
}
