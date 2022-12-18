#include "character.h"

#include <iostream>
#include <string>

#include "constants.h"

void Character::init(LTexture* texture_)
{
    // Set texture
    texture = &(*texture_);

    // Initialise rigid body
    body.init(
        50,
        200,
        texture->w,
        texture->h
    );
}

void Character::stand()
{
    body.velX = 0;
    body.update();
}

void Character::walk(int direction)
{
    body.velX = CHARACTER_SPEED * direction;
    body.update();
}

void Character::jump()
{
    if (body.velY == 0)
        body.velY = -JUMP_HEIGHT;
    body.update();
}
