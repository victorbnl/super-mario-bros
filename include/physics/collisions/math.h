#ifndef PHYSICS_COLLISIONS_MATH_H
#define PHYSICS_COLLISIONS_MATH_H

#include <vector>

// Get number with the greatest absolute value
int maxAbsValue(std::vector<int> values);

// Get the previous multiple of TILE_SIZE
int floorCoord(int n);

// Get the following multiple of TILE_SIZE
int ceilCoord(int n);

#endif
