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
    if (charOnScreenPosX < 150)
    {
        // If camera is after the beginning of the level
        if (x >= 0)
        {
            x -= 150 - charOnScreenPosX;
        }
    }

    // If character is too much at the right
    if (charOnScreenPosX > SCREEN_WIDTH - 150)
    {
        x += (mCharacter->pos.x) - (x + SCREEN_WIDTH - 150);
    }
}
