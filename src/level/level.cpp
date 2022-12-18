#include "level.h"

#include <string>
#include <SDL2/SDL.h>

#include "../constants.h"
#include "csv.h"
#include "tile.h"
#include "tileset.h"
#include "../camera.h"

void Level::load(Window* window, std::string path)
{
    // Parse tiles file
    std::vector<std::vector<int>> levelData = parseCSVLevel(path);

    // Get textures
    mTileset.load(window);

    // For each line of tiles
    for (int i = 0; i < size(levelData); i++)
    {
        std::vector<Tile> line;
        // For each tile of line
        for (int j = 0; j < size(levelData[i]); j++)
        {
            int tileType = levelData[i][j];
            // If actual tile
            if (tileType > -1)
            {
                // Add it to the list
                LTexture* texture = mTileset.get(tileType);
                line.push_back(Tile(j * TILE_SIZE, i * TILE_SIZE, tileType, texture));
            }
            else
            {
                line.push_back(Tile(j * TILE_SIZE, i * TILE_SIZE, tileType, NULL));
            }
        }
        tiles.push_back(line);
    }
}

Tile* Level::getTileAt(int x, int y)
{
    // Find index in mTiles
    int i = y / TILE_SIZE;
    int j = x / TILE_SIZE;

    Tile* tile = &tiles[i][j];

    return tile;
}

int Level::getWidth()
{
    return size(tiles[0]) * TILE_SIZE;
}
