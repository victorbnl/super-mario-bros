#include <vector>
#include <SDL2/SDL.h>

#include "character.h"
#include "level/level.h"

void solveCollisions(Character* character, Level* level, int winWidth, int winHeight)
{
    // Check collisions with screen borders
    SDL_Rect charCollider = character->getCollider();
    if (charCollider.x < 0)
        character->moveX(-charCollider.x);
    if ((charCollider.x + charCollider.w) > winWidth)
        character->moveX(winWidth - (charCollider.x + charCollider.w));

    // Check collisions with map
}
