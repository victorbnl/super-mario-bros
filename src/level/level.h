#ifndef LEVEL_LEVEL_H
#define LEVEL_LEVEL_H

#include <vector>
#include <SDL2/SDL.h>

#include "tile.h"
#include "tileset.h"
#include "../camera.h"

class Level
{
    public:

        // Load level from file (currently hardcoded)
        void load(Window* window, std::string path);

        // Get tile at coordinates (x, y)
        Tile* getTileAt(int x, int y);

        // Get level width
        int getWidth();

        // Level tiles
        std::vector<std::vector<Tile>> tiles;

    private:

        // Tileset
        Tileset mTileset;
};

#endif
