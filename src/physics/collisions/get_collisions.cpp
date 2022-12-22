#include "physics/collisions/get_collisions.h"

#include <vector>
#include <cmath>
#include <algorithm>

#include "constants.h"
#include "entities/character.h"
#include "level/tile.h"
#include "level/level.h"
#include "physics/structs.h"
#include "physics/bodies.h"
#include "physics/collisions/get_adjacent_tiles.h"

bool areColliding(Body* body, Tile* tile)
{
    SideCoords bodySideCoords = body->getSideCoords();
    SideCoords tileSideCoords = tile->body.getSideCoords();

    return (
        bodySideCoords.right > tileSideCoords.left
        && bodySideCoords.left < tileSideCoords.right
        && bodySideCoords.bottom > tileSideCoords.top
        && bodySideCoords.top < tileSideCoords.bottom
    );
}

Collision getCollision(Entity* entity, Tile* tile)
{
    // Define collision
    Collision collision;
    collision.entity = entity;
    collision.solution = {0, 0};
    collision.collidingArea = 0;

    // If the tile is air
    if (tile->type == -1)
        return collision;

    // If they don't collide
    if (!areColliding(&entity->body, tile))
        return collision;

    // Get sides coordinates for calculation
    SideCoords entitySideCoords = entity->body.getSideCoords();
    SideCoords tileSideCoords = tile->body.getSideCoords();

    // Entity comes from the top
    if (entitySideCoords.bottom > tileSideCoords.top && entitySideCoords.top < tileSideCoords.top)
        collision.solution.y = tileSideCoords.top - entitySideCoords.bottom;

    // Entity comes from the bottom
    if (entitySideCoords.top < tileSideCoords.bottom && entitySideCoords.bottom > tileSideCoords.bottom)
        collision.solution.y = tileSideCoords.bottom - entitySideCoords.top;

    // Entity comes from the left
    if (entitySideCoords.right > tileSideCoords.left && entitySideCoords.left < tileSideCoords.left)
        collision.solution.x = tileSideCoords.left - entitySideCoords.right;

    // Entity comes from the right
    if (entitySideCoords.left < tileSideCoords.right && entitySideCoords.right > tileSideCoords.right)
        collision.solution.x = tileSideCoords.right - entitySideCoords.left;

    // Get the colliding area
    int collidingAreaWidth = collision.solution.x == 0 ? TILE_SIZE : std::abs(collision.solution.x);
    int collidingAreaHeight = collision.solution.y == 0 ? TILE_SIZE : std::abs(collision.solution.y);
    collision.collidingArea = collidingAreaWidth * collidingAreaHeight;

    // Move by the smallest distance required to solve the collision
    if (std::abs(collision.solution.x) >= std::abs(collision.solution.y) && collision.solution.y != 0)
        collision.solution.x = 0;
    if (std::abs(collision.solution.y) > std::abs(collision.solution.x) && collision.solution.x != 0)
        collision.solution.y = 0;

    return collision;
}

bool compByCollidingArea(Collision a, Collision b)
{
    return a.collidingArea > b.collidingArea;
}

std::vector<Collision> sortByCollidingArea(std::vector<Collision> collisions)
{
    std::vector<Collision> sorted = collisions;

    std::sort(sorted.begin(), sorted.end(), compByCollidingArea);

    return sorted;
}

Collision getLevelBoundariesCollision(Entity* entity, Level* level)
{
    // Define collision
    Collision collision;
    collision.entity = entity;
    collision.solution = {0, 0};
    collision.collidingArea = 0;

    SideCoords entitySideCoords = entity->body.getSideCoords();
    SideCoords levelSideCoords = level->body.getSideCoords();

    // If entity is outside at the left
    if (entitySideCoords.left < levelSideCoords.left)
        collision.solution.x = levelSideCoords.left - entitySideCoords.left;

    // If entity is outside at the right
    if (entitySideCoords.right > levelSideCoords.right)
        collision.solution.x = levelSideCoords.right - entitySideCoords.right;

    // If entity is outside at the bottom
    if (entitySideCoords.bottom > levelSideCoords.bottom)
        collision.solution.y = levelSideCoords.bottom - entitySideCoords.bottom;

    collision.collidingArea =
        std::abs(collision.solution.x) * TILE_SIZE
        + std::abs(collision.solution.y) * TILE_SIZE;

    return collision;
}

std::vector<Collision> getCollisions(Entity* entity, Level* level)
{
    std::vector<Collision> collisions;

    Collision levelBoundariesCollision = getLevelBoundariesCollision(entity, level);
    if (levelBoundariesCollision.collidingArea > 0)
        collisions.push_back(levelBoundariesCollision);

    // Get nearby tiles
    std::vector<Tile*> adjacentTiles = getAdjacentTiles(entity->body, level);

    // For each of them
    for (Tile* tile : adjacentTiles)
    {
        // Get the collision
        Collision collision = getCollision(entity, tile);

        // Add it if not empty
        if (collision.collidingArea > 0)
            collisions.push_back(collision);
    }

    // Sort them by colliding area
    collisions = sortByCollidingArea(collisions);

    return collisions;
}
