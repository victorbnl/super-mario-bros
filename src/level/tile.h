#ifndef LEVEL_TILE_H
#define LEVEL_TILE_H

#include <vector>
#include <fstream>

#include "../render/ltexture.h"
#include "../physics/rigidbody.h"

class Tile
{
    public:

        // Constructor
        Tile(int x, int y, int type_, LTexture* texture_);

        // Texture
        int type;
        LTexture* texture;

        // Physics
        RigidBody body;
};

#endif
