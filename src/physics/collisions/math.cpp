#include "physics/collisions/math.h"

#include <vector>
#include <cmath>

#include "constants.h"

int maxAbsValue(std::vector<int> values)
{
    int max = values[0];
    for (int i = 0; i < size(values); i++)
    {
        if (std::abs(values[i]) > std::abs(max))
            max = values[i];
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
