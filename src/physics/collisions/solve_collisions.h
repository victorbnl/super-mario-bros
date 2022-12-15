#ifndef PHYSICS_COLLISIONS_SOLVE_COLLISIONS_H
#define PHYSICS_COLLISIONS_SOLVE_COLLISIONS_H

#include "../../character.h"
#include "../../level/level.h"

void solveCollisions(Character* character, Level* level, Rectangle levelBoundaries);

#endif
