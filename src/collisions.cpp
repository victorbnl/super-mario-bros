#include <SDL2/SDL.h>

#include "character.h"

void solveCollisions(Character* character, int winWidth, int winHeight)
{
    // Check collisions with screen borders
    SDL_Rect charCollider = character->getCollider();
    if (charCollider.x < 0)
        character->moveX(-charCollider.x);
    if ((charCollider.x + charCollider.w) > winWidth)
        character->moveX(winWidth - (charCollider.x + charCollider.w));
}
