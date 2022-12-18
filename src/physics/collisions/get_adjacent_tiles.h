#ifndef PHYSICS_COLLISIONS_GET_ADJACENT_TILES_H
#define PHYSICS_COLLISIONS_GET_ADJACENT_TILES_H

#include <vector>

#include "../../character.h"
#include "../../level/level.h"

// Get adjacent tiles' colliders
std::vector<Tile*> getAdjacentTiles(RigidBody body, Level* level);

#endif