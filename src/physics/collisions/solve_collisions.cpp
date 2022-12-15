#include "solve_collisions.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>

#include "collisions.h"
#include "math.h"
#include "../../structs.h"
#include "../../constants.h"
#include "../../character.h"
#include "../../level/level.h"
#include "../../level/tile.h"

std::vector<Coordinates> getCloseTilesCoords(SDL_Rect charCollider)
{
    std::vector<Coordinates> tiles;

    Coordinates tile {
        floorCoord(charCollider.x),
        floorCoord(charCollider.y)
    };
    tiles.push_back(tile);
    tile.y = ceilCoord(charCollider.y);
    tiles.push_back(tile);
    tile.x = ceilCoord(charCollider.x);
    tiles.push_back(tile);
    tile.y = floorCoord(charCollider.y);
    tiles.push_back(tile);

    return tiles;
}

Vector getCollisionSolution(SDL_Rect colliderA, SDL_Rect colliderB)
{
    SidesCoords a = getSidesCoords(colliderA);
    SidesCoords b = getSidesCoords(colliderB);

    // Get x and y distances between objects
    int distanceX, distanceY;
    int directionX, directionY;
    if (a.left <= b.left)
    {
        distanceX = b.left - a.right;
        directionX = 1;
    }
    if (a.left > b.left)
    {
        distanceX = a.left - b.right;
        directionX = -1;
    }
    if (a.top <= b.top)
    {
        distanceY = b.top - a.bottom;
        directionY = 1;
    }
    if (a.top > b.top)
    {
        distanceY = a.top - a.bottom;
        directionY = -1;
    }

    // No collision by default
    Vector collision {0, 0};
    // If there is a collision
    if (distanceX < 0 && distanceY < 0)
    {
        // Return it
        collision = {distanceX * directionX, distanceY * directionY};
    }

    return collision;
}

Vector getLevelBordersCollisionSolution(SDL_Rect collider, Level* level, Rectangle levelBoundaries)
{
    SidesCoords a = getSidesCoords(collider);
    Vector solution {0, 0};

    // Left border
    if (a.left < 0)
        solution.x = -a.left;

    // Right border
    if (a.right > levelBoundaries.w)
        solution.x = a.right - levelBoundaries.w;

    // Top border
    if (a.top < 0)
        solution.y = -a.top;

    // Bottom border
    if (a.bottom > levelBoundaries.h - 10)
        solution.y = levelBoundaries.h - a.bottom - 10;

    return solution;
}

void moveCharacter(Vector vector, SDL_Rect charCollider, Character* character, Level* level)
{
    character->pos.x = std::clamp(character->pos.x + vector.x, 0, level->getWidth()-charCollider.w-10);
    character->pos.y = std::clamp(character->pos.y + vector.y, 0, SCREEN_HEIGHT-charCollider.h-10);
}

void solveCollisions(Character* character, Level* level, Rectangle levelBoundaries)
{
    SDL_Rect charCollider = character->getCollider();

    // Get coordinates of tiles around the player
    std::vector<Coordinates> closeTilesCoords = getCloseTilesCoords(charCollider);

    // Get tiles
    std::vector<Tile*> closeTiles;
    // For each tile coordinate
    for (int i = 0; i < size(closeTilesCoords); i++)
    {
        closeTiles.push_back(level->getTileAt(closeTilesCoords[i].x, closeTilesCoords[i].y));
    }

    std::vector<int> xMoves {0};
    std::vector<int> yMoves {0};

    // For each close tile
    for (int i = 0; i < size(closeTilesCoords); i++)
    {
        // If tile is a solid block
        if (closeTiles[i]->getType() > -1)
        {
            SDL_Rect tileCollider = {
                closeTilesCoords[i].x,
                closeTilesCoords[i].y,
                TILE_SIZE,
                TILE_SIZE
            };

            // Get collision
            Vector collision = getCollisionSolution(charCollider, tileCollider);

            // Move character accordingly
            if (abs(collision.x) < abs(collision.y))
            {
                xMoves.push_back(collision.x);
            }
            if (abs(collision.x) >= abs(collision.y))
            {
                yMoves.push_back(collision.y);
            }
        }
    }

    // Determine greatest moves
    int xMove = maxAbsValue(xMoves);
    int yMove = maxAbsValue(yMoves);
    Vector move {xMove, yMove};

    // Move character
    character->pos.x += move.x;
    character->pos.y += move.y;

    // Screen borders
    Vector levelBordersCollisionSolution = getLevelBordersCollisionSolution(charCollider, level, levelBoundaries);
    character->pos.x += levelBordersCollisionSolution.x;
    character->pos.y += levelBordersCollisionSolution.y;

    // Update character velocity accordingly
    if (move.x != 0 || levelBordersCollisionSolution.x != 0)
        character->vel.x = 0;
    if (move.y != 0 || levelBordersCollisionSolution.y != 0)
        character->vel.y = 0;
}
