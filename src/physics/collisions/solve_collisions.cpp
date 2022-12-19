#include "physics/collisions/solve_collisions.h"

#include <vector>

#include "constants.h"
#include "entities/character.h"
#include "level/tile.h"
#include "level/level.h"
#include "physics/structs.h"
#include "physics/collisions/get_adjacent_tiles.h"

bool areColliding(Character* character, Tile* tile)
{
    SideCoords charSideCoords = character->body.getSideCoords();
    SideCoords tileSideCoords = tile->body.getSideCoords();

    return (
        charSideCoords.right > tileSideCoords.left
        && charSideCoords.left < tileSideCoords.right
        & charSideCoords.bottom > tileSideCoords.top
        && charSideCoords.top < tileSideCoords.bottom
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

    SideCoords tileSideCoords = tile->body.getSideCoords();

    // Character moving right
    if (character->body.vel.x > 0)
    {
        character->body.x = tileSideCoords.left - TILE_SIZE;
    }

    // Character moving left
    if (character->body.vel.x < 0)
    {
        character->body.vel.x = 0;
        character->body.x = tileSideCoords.right;
    }
}

void solveCollisionY(Character* character, Tile* tile)
{
    // If tile is air
    if (tile->type == -1)
        return;

    // If there is no collision
    if (!areColliding(character, tile))
        return;

    SideCoords tileSideCoords = tile->body.getSideCoords();

    // Character moving down
    if (character->body.vel.y > 0)
    {
        character->body.vel.y = 0;
        character->body.y = tileSideCoords.top - TILE_SIZE;
        character->isOnGround = true;
    }

    // Character moving up
    if (character->body.vel.y < 0)
    {
        character->body.vel.y = 0;
        character->body.y = tileSideCoords.bottom;
    }
}

void solveCollisionsX(Character* character, Level* level)
{
    // Get colliders
    std::vector<Tile*> tiles = getAdjacentTiles(character->body, level);

    // For each adjacent tile
    for (int i = 0; i < size(tiles); i++)
    {
        Tile* tile = tiles[i];

        solveCollisionX(character, tile);
    }
}

void solveCollisionsY(Character* character, Level* level)
{
    // Get colliders
    std::vector<Tile*> tiles = getAdjacentTiles(character->body, level);

    // For each adjacent tile
    for (int i = 0; i < size(tiles); i++)
    {
        Tile* tile = tiles[i];

        solveCollisionY(character, tile);
    }
}
