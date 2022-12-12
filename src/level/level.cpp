#include <string>
#include <SDL2/SDL.h>

#include "level.h"
#include "../constants.h"
#include "csv.h"
#include "tile.h"
#include "tileset.h"

void Level::load(SDL_Renderer* renderer, std::string path)
{
    // Parse tiles file
    std::vector<std::vector<int>> levelData = parseCSVLevel(path);

    // Get textures
    mTileset.load(renderer);

    // For each line of tiles
    for (int i = 0; i < size(levelData); i++)
    {
        std::vector<Tile*> line;
        // For each tile of line
        for (int j = 0; j < size(levelData[i]); j++)
        {
            int tileType = levelData[i][j];
            // If actual tile
            if (tileType > -1)
            {
                // Add it to the list
                LTexture* texture = mTileset.get(tileType);
                line.push_back(new Tile(texture));
            }
            else
            {
                line.push_back(new Tile(NULL));
            }
        }
        mTiles.push_back(line);
    }
}

Tile* getTileAt(int x, int y)
{
    throw "Not implemented";
}

void Level::render(SDL_Renderer* renderer)
{
    // For line of tiles
    for (int i = 0; i < size(mTiles); i++)
    {
        // For tile of line
        for (int j = 0; j < size(mTiles[i]); j++)
        {
            // Render tile
            int x = j*TILE_WIDTH;
            int y = SCREEN_HEIGHT-((size(mTiles))*48)+i*TILE_HEIGHT;
            mTiles[i][j]->render(renderer, x, y);
        }
    }
}
