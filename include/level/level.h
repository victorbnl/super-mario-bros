#ifndef LEVEL_LEVEL_H
#define LEVEL_LEVEL_H

#include <vector>
#include <string>

#include "render/window.h"
#include "level/tile.h"
#include "level/tileset.h"
#include "physics/bodies.h"

class Level
{
    public:

        // Load level from file (currently hardcoded)
        void load(Window* window, std::string path);

        // Get tile at coordinates (x, y)
        Tile* getTileAt(int x, int y);

        // Level tiles
        std::vector<std::vector<Tile>> tiles;

        // Physics body (for collisions with level boundaries)
        Body body;

    private:

        // Tileset
        Tileset mTileset;
};

#endif
