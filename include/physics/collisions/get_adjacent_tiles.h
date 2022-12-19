#ifndef PHYSICS_COLLISIONS_GET_ADJACENT_TILES_H
#define PHYSICS_COLLISIONS_GET_ADJACENT_TILES_H

#include <vector>

#include "character.h"
#include "level/level.h"
#include "physics/bodies.h"

// Get adjacent tiles' colliders
std::vector<Tile*> getAdjacentTiles(Body body, Level* level);

#endif
