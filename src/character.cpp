#include "character.h"

#include <iostream>
#include <string>

#include "constants.h"

void Character::init(LTexture* texture_)
{
    // Set texture
    texture = &(*texture_);

    // Initialise rigid body
    body.x = 50;
    body.y = 200;
    body.collider.w = texture->w;
    body.collider.h = texture->h;
}

void Character::stand()
{
    body.vel.x = 0;
}

void Character::walk(int direction)
{
    body.vel.x = CHARACTER_SPEED * direction;
}

void Character::jump()
{
    if (body.vel.y == 0)
        body.vel.y = -JUMP_HEIGHT;
}
