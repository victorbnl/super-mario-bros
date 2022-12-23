#include "level/level.h"

#include <string>

#include "constants.h"
#include "level/csv.h"
#include "level/tile.h"

void Level::load(std::string path)
{
    // Parse tiles file
    std::vector<std::vector<int>> levelData = parseCSVLevel(path);

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
                line.push_back(Tile(j * TILE_SIZE, i * TILE_SIZE, tileType));
            }
            else
            {
                line.push_back(Tile(j * TILE_SIZE, i * TILE_SIZE, tileType));
            }
        }
        tiles.push_back(line);
    }

    // Define body
    body.collider.w = size(tiles[0]) * TILE_SIZE;
    body.collider.h = SCREEN_HEIGHT;
    body.x = 0;
    body.y = 0;
}

Tile* Level::getTileAt(int x, int y)
{
    // Find index in mTiles
    int i = y / TILE_SIZE;
    int j = x / TILE_SIZE;

    Tile* tile = &tiles[i][j];

    return tile;
}
