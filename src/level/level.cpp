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
                LTexture* texture = (tileSet+levelData[i][j]);
                line.push_back(new Tile(texture));
            }
            else
            {
                line.push_back(new Tile(NULL));
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