#ifndef PHYSICS_COLLISIONS_SOLVE_COLLISIONS_H
#define PHYSICS_COLLISIONS_SOLVE_COLLISIONS_H

#include "entities/character.h"
#include "level/level.h"

void solveCollisionsX(Character* character, Level* level);
void solveCollisionsY(Character* character, Level* level);

#endif
