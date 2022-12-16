#include "character.h"

#include <iostream>
#include <string>

#include "constants.h"
#include "camera.h"

Character::Character()
{
    pos = {150, 200};
    vel = {0, 0};
}

void Character::init(LTexture* texture_)
{
    // Set texture
    texture = &(*texture_);

    // Initialise collider
    mCollider = {(int)pos.x, (int)pos.y, texture->w, texture->h};
}

void Character::moveX(int distance)
{
    pos.x += distance;
    mCollider.x = pos.x;
}

void Character::moveY(int distance)
{
    pos.y += distance;
    mCollider.y = pos.y;
}

void Character::jump()
{
    if (vel.y == 0)
        vel.y = -JUMP_HEIGHT;
}

Rectangle Character::getCollider()
{
    return mCollider;
}

void Character::updateCollider()
{
    mCollider.x = pos.x;
    mCollider.y = pos.y;
}
