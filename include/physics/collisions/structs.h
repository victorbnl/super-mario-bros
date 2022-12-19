#ifndef PHYSICS_COLLISIONS_STRUCTS_H
#define PHYSICS_COLLISIONS_STRUCTS_H

#include "character.h"
#include "structures.h"
#include "level/level.h"

struct Collision
{
    Character* character;
    Tile* tile;
    int collidingArea;
    Vector solution;
}

#endif
