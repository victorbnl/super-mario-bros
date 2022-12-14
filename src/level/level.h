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
        void load(SDL_Renderer* renderer, std::string path);

        // Get tile at coordinates (x, y)
        Tile* getTileAt(int x, int y);

        // Get level width
        int getWidth();

        // Render level (render each tile)
        void render(SDL_Renderer* renderer, Camera* camera);

    private:

        // Tileset
        Tileset mTileset;

        // Level tiles
        std::vector<std::vector<Tile*>> mTiles;
};

#endif
