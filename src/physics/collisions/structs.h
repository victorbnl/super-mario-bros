#ifndef PHYSICS_COLLISIONS_STRUCTS_H
#define PHYSICS_COLLISIONS_STRUCTS_H

#include "../../character.h"
#include "../../level/level.h"
#include "../../structures.h"

struct Collision
{
    Character* character;
    Tile* tile;
    int collidingArea;
    Vector solution;
}

#endif
