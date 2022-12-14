#ifndef LEVEL_LEVEL_H
#define LEVEL_LEVEL_H

#include <vector>
#include <SDL2/SDL.h>

#include "tile.h"
#include "tileset.h"

class Level
{
    public:

        // Load level from file (currently hardcoded)
        void load(SDL_Renderer* renderer, std::string path);

        // Get tile at coordinates (x, y)
        Tile* getTileAt(int x, int y);

        // Render level (render each tile)
        void render(SDL_Renderer* renderer);

    private:

        // Tileset
        Tileset mTileset;

        // Level tiles
        std::vector<std::vector<Tile*>> mTiles;
};

#endif
