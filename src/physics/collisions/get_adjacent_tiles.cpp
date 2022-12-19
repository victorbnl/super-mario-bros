#include "physics/collisions/get_adjacent_tiles.h"

#include "geometry.h"
#include "physics/bodies.h"
#include "physics/collisions/math.h"
#include "level/level.h"

std::vector<Coordinates> calculateAdjacentTilesCoords(Body body)
{
    std::vector<Coordinates> tiles;

    Coordinates tile;

    // Left up tile
    tile.x = floorCoord(body.x);
    tile.y = floorCoord(body.y);
    tiles.push_back(tile);

    // Left down tile
    tile.y = ceilCoord(body.y);
    tiles.push_back(tile);

    // Right down tile
    tile.x = ceilCoord(body.x);
    tiles.push_back(tile);

    // Right up tile
    tile.y = floorCoord(body.y);
    tiles.push_back(tile);

    return tiles;
}

std::vector<Tile*> getAdjacentTiles(Body body, Level* level)
{
    // Initialise the list of colliders to be returned
    std::vector<Tile*> tiles;

    // Get adjacent tiles coordinates
    std::vector<Coordinates> tilesCoords = calculateAdjacentTilesCoords(body);

    // For each adjacent tile
    for (int i = 0; i < size(tilesCoords); i++)
    {
        // Return a pointer to the Tile object
        tiles.push_back(level->getTileAt(tilesCoords[i].x, tilesCoords[i].y));
    }

    return tiles;
}
