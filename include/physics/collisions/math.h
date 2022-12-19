#ifndef PHYSICS_COLLISIONS_MATH_H
#define PHYSICS_COLLISIONS_MATH_H

#include <vector>
#include <SDL2/SDL.h>

#include "geometry.h"

// Get number with the greatest absolute value
int maxAbsValue(std::vector<int> values);

// Get the previous multiple of TILE_SIZE
int floorCoord(int n);

// Get the following multiple of TILE_SIZE
int ceilCoord(int n);

// Get sides coordinates
struct SidesCoords {int left; int right; int top; int bottom;};
SidesCoords getSidesCoords(Rectangle collider);

#endif
