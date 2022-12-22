#ifndef PHYSICS_COLLISIONS_SOLVE_COLLISIONS_H
#define PHYSICS_COLLISIONS_SOLVE_COLLISIONS_H

#include <vector>

#include "geometry.h"
#include "entities/entity.h"
#include "level/level.h"

struct Collision
{
    Entity* entity;
    Tile* tile;
    Vector solution;
    int collidingArea;
};

std::vector<Collision> getCollisions(Entity* entity, Level* level);

#endif
