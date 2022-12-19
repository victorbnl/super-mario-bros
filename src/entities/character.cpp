#include "entities/character.h"

#include "constants.h"
#include "entities/entity.h"

void Character::init(LTexture* texture_)
{
    Entity::init(texture_);

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
    if (isOnGround)
        body.vel.y = -JUMP_HEIGHT;
        isOnGround = false;
}
