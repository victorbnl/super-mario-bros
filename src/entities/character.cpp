#include "entities/character.h"

#include "constants.h"
#include "entities/entity.h"

Character::Character()
{
    // Body properties
    body.x = 50;
    body.y = 200;
    body.collider.w = TILE_SIZE;
    body.collider.h = TILE_SIZE;

    // Texture
    sprite = SPRITES::CHARACTER;
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
