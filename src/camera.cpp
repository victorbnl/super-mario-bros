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

void Camera::init(Character* character, Rectangle levelBoundaries)
{
    mCharacter = character;
    mLevelBoundaries = levelBoundaries;
}

void Camera::update()
{
    int charOnScreenPosX = mCharacter->pos.x - x;

    int moveX = 0;

    // If character is too much at the left
    if (charOnScreenPosX < SCREEN_PADDING_X)
    {
        moveX = -(SCREEN_PADDING_X - charOnScreenPosX);
    }

    // If character is too much at the right
    if (charOnScreenPosX > SCREEN_WIDTH - SCREEN_PADDING_X)
    {
        moveX = (mCharacter->pos.x) - (x + SCREEN_WIDTH - SCREEN_PADDING_X);
    }

    // Move camera
    // std::clamp ensure camera stays inside the level
    x = std::clamp(x + moveX, mLevelBoundaries.x, mLevelBoundaries.x + mLevelBoundaries.w - SCREEN_WIDTH);
}
