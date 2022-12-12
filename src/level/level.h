#ifndef LEVEL_INCLUDE_GUARD
#define LEVEL_INCLUDE_GUARD

#include <vector>
#include <SDL2/SDL.h>

#include "tiles.h"

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

        // Level tiles
        std::vector<std::vector<Tile*>> mTiles;
};

#endif
