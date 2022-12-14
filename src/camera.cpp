#include <algorithm>
#include <SDL2/SDL.h>

#include "camera.h"
#include "structs.h"
#include "constants.h"
#include "character.h"
#include "constants.h"

Camera::Camera()
{
    x = 0;
}

void Camera::followCharacter(Character* character)
{
    mCharacter = character;
}

void Camera::update()
{
    int charOnScreenPosX = mCharacter->pos.x - x;

    // If character is too much at the left
    if (charOnScreenPosX < SCREEN_PADDING_X)
    {
        // If camera is after the beginning of the level
        if (x >= 0)
        {
            // std::max ensures camera doesn't go to the left of the level
            x = std::max(x - (SCREEN_PADDING_X - charOnScreenPosX), 0);
        }
    }

    // If character is too much at the right
    if (charOnScreenPosX > SCREEN_WIDTH - SCREEN_PADDING_X)
    {
        x += (mCharacter->pos.x) - (x + SCREEN_WIDTH - SCREEN_PADDING_X);
    }
}
