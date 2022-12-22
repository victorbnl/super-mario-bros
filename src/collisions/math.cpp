#include "collisions/math.h"

#include <vector>
#include <cmath>

#include "constants.h"

int maxAbsValue(std::vector<int> values)
{
    int max = values[0];
    for (int value : values)
    {
        if (std::abs(value) > std::abs(max))
            max = value;
    }

    return max;
}

int floorCoord(int n)
{
    return n - n % TILE_SIZE;
}

int ceilCoord(int n)
{
    return floorCoord(n) + TILE_SIZE;
}
