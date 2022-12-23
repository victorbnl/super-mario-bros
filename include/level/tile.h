#ifndef LEVEL_TILE_H
#define LEVEL_TILE_H

#include "physics/bodies.h"

class Tile
{
    public:

        // Constructor
        Tile(int x, int y, int sprite_);

        // Texture
        int sprite;

        // Physics
        RigidBody body;
};

#endif
