#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "collisions.h"
#include "math.h"
#include "structs.h"
#include "../constants.h"
#include "../character.h"
#include "../level/level.h"
#include "../level/tile.h"

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

Vector getScreenBordersCollisionSolution(SDL_Rect collider)
{
    SidesCoords a = getSidesCoords(collider);
    Vector solution {0, 0};

    // Left border
    if (a.left < 0)
        solution.x = -a.left;

    // Top border
    if (a.top < 0)
        solution.y = -a.top;

    // Bottom border
    if (a.bottom > SCREEN_HEIGHT)
        solution.y = SCREEN_HEIGHT - a.bottom - 20;

    return solution;
}

void solveCollisions(Character* character, Level* level)
{
    SDL_Rect charCollider = character->getCollider();

    // Screen borders
    Vector screenBordersCollisionSolution = getScreenBordersCollisionSolution(charCollider);
    character->moveX(screenBordersCollisionSolution.x);
    character->moveY(screenBordersCollisionSolution.y);

    // Check collisions with level tiles

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

    // Move character
    character->moveX(xMove);
    character->moveY(yMove);
}
