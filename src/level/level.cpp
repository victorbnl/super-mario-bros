#include <string>
#include <SDL2/SDL.h>

#include "level.h"
#include "csv.h"
#include "tiles.h"

const int SCREEN_HEIGHT = 48*10;

const int TILE_WIDTH = 48;
const int TILE_HEIGHT = 48;

void Level::load(SDL_Renderer* renderer, std::string path)
{
    // Parse tiles file
    std::vector<std::vector<int>> levelData = parseCSVLevel(path);

    // Get textures
    LTexture* tileSet = getTileSet(renderer);

    // For each line of tiles
    int x, y;
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
                x = j*TILE_WIDTH;
                y = SCREEN_HEIGHT-(size(levelData)*48)+i*TILE_HEIGHT;
                LTexture* texture = (tileSet+levelData[i][j]);
                line.push_back(new Tile(x, y, texture));
            }
        }
        mTiles.push_back(line);
        x = 0;
    }
}

Tile* getTileAt(int x, int y)
{
    throw "Not implemented";
}

void Level::render(SDL_Renderer* renderer)
{
    for (std::vector<Tile*> line : mTiles)
    {
        for (Tile* tile : line)
        {
            tile->render(renderer);
        }
    }
}
