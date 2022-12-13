#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "collisions.h"
#include "structs.h"
#include "../constants.h"
#include "../character.h"
#include "../level/level.h"
#include "../level/tile.h"

std::vector<Coordinates> getCloseTilesCoords(SDL_Rect charCollider)
{
    std::vector<Coordinates> cases;

    Coordinates upLeftTileCoords {
        (charCollider.x - charCollider.x % TILE_WIDTH),
        (charCollider.y - charCollider.y % TILE_HEIGHT)
    };
    cases.push_back(upLeftTileCoords);

    Coordinates upRightTileCoords {
        (charCollider.x - charCollider.x % TILE_WIDTH) + charCollider.w,
        (charCollider.y - charCollider.y % TILE_HEIGHT)
    };
    cases.push_back(upRightTileCoords);

    Coordinates downLeftTileCoords {
        (charCollider.x - charCollider.x % TILE_WIDTH),
        (charCollider.y - charCollider.y % TILE_HEIGHT) + charCollider.h
    };
    cases.push_back(downLeftTileCoords);

    Coordinates downRightTileCoords {
        (charCollider.x - charCollider.x % TILE_WIDTH) + charCollider.w,
        (charCollider.y - charCollider.y % TILE_HEIGHT) + charCollider.h
    };
    cases.push_back(downRightTileCoords);

    return cases;
}

Collision checkCollision(SDL_Rect colliderA, SDL_Rect colliderB)
{
    int topA = colliderA.y;
    int bottomA = colliderA.y + colliderA.h;
    int leftA = colliderA.x;
    int rightA = colliderA.x + colliderA.w;

    int topB = colliderB.y;
    int bottomB = colliderB.y + colliderB.h;
    int leftB = colliderB.x;
    int rightB = colliderB.x + colliderB.w;

    // Get x and y distances between objects
    int distanceX, distanceY;
    int directionX, directionY;
    if (leftA <= leftB)
    {
        distanceX = leftB - rightA;
        directionX = 1;
    }
    if (leftA > leftB)
    {
        distanceX = leftA - rightB;
        directionX = -1;
    }
    if (topA <= topB)
    {
        distanceY = topB - bottomA;
        directionY = 1;
    }
    if (topA > topB)
    {
        distanceY = topA - bottomB;
        directionY = -1;
    }

    // No collision by default
    Collision collision {0, 0};
    // If there is a collision
    if (distanceX < 0 && distanceY < 0)
    {
        // Return it
        collision = {distanceX * directionX, distanceY * directionY};
    }

    return collision;
}

void solveCollisions(Character* character, Level* level)
{
    SDL_Rect charCollider = character->getCollider();

    // Left screen border
    if (charCollider.x < 0)
        character->moveX(-charCollider.x);
    // Right screen border
    if ((charCollider.x + charCollider.w) > SCREEN_WIDTH)
        character->moveX(SCREEN_WIDTH - (charCollider.x + charCollider.w));
    // Up screen border
    if (charCollider.y < 0)
        character->moveY(-charCollider.y);
    if ((charCollider.y + charCollider.h) > SCREEN_HEIGHT-20)
        character->moveY(SCREEN_HEIGHT - (charCollider.y + charCollider.w) - 20);

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
                TILE_WIDTH,
                TILE_HEIGHT
            };

            // Get collision
            Collision collision = checkCollision(charCollider, tileCollider);

            // Move character accordingly
            if (abs(collision.distanceX) < abs(collision.distanceY))
            {
                xMoves.push_back(collision.distanceX);
            }
            if (abs(collision.distanceX) >= abs(collision.distanceY))
            {
                yMoves.push_back(collision.distanceY);
            }
        }
    }

    // Determine greatest X move
    int xMove = xMoves[0];
    for (int i = 0; i < size(xMoves); i++)
    {
        if (abs(xMoves[i]) > abs(xMove))
            xMove = xMoves[i];
    }

    // Determine greatest Y move
    int yMove = yMoves[0];
    for (int i = 0; i < size(yMoves); i++)
    {
        if (abs(yMoves[i]) > abs(yMove))
            yMove = yMoves[i];
    }

    // Move character
    character->moveX(xMove);
    character->moveY(yMove);
}
