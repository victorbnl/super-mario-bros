#include "physics/collisions/solve_collisions.h"

#include <vector>

#include "structures.h"
#include "constants.h"
#include "physics/collisions/get_adjacent_tiles.h"

bool areColliding(Character* character, Tile* tile)
{
    return (
        character->body.right > tile->body.left
        && character->body.left < tile->body.right
        & character->body.bottom > tile->body.top
        && character->body.top < tile->body.bottom
    );
}

void solveCollisionX(Character* character, Tile* tile)
{
    // If tile is air
    if (tile->type == -1)
        return;

    // If there is no collision
    if (!areColliding(character, tile))
        return;

    // Character moving right
    if (character->body.velX > 0)
    {
        character->body.x = tile->body.left - TILE_SIZE;
    }

    // Character moving left
    if (character->body.velX < 0)
    {
        character->body.velX = 0;
        character->body.x = tile->body.right;
    }

    character->body.update();
    character->oldBody = character->body;
}

void solveCollisionY(Character* character, Tile* tile)
{
    // If tile is air
    if (tile->type == -1)
        return;

    // If there is no collision
    if (!areColliding(character, tile))
        return;

    // Character moving down
    if (character->body.velY > 0)
    {
        character->body.velY = 0;
        character->body.y = tile->body.top - TILE_SIZE;
    }

    // Character moving up
    if (character->body.velY < 0)
    {
        character->body.velY = 0;
        character->body.y = tile->body.bottom;
    }

    character->body.update();
}

void solveCollisionsX(Character* character, Level* level, Rectangle screenBoundaries)
{
    // Get colliders
    std::vector<Tile*> tiles = getAdjacentTiles(character->body, level);

    // For each adjacent tile
    for (int i = 0; i < size(tiles); i++)
    {
        Tile* tile = tiles[i];

        solveCollisionX(character, tile);
    }

    character->body.update();
    character->oldBody = character->body;
}

void solveCollisionsY(Character* character, Level* level, Rectangle screenBoundaries)
{
    // Get colliders
    std::vector<Tile*> tiles = getAdjacentTiles(character->body, level);

    // For each adjacent tile
    for (int i = 0; i < size(tiles); i++)
    {
        Tile* tile = tiles[i];

        solveCollisionY(character, tile);
    }

    character->body.update();
    character->oldBody = character->body;
}
