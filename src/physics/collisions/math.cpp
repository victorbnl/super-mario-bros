#include "physics/collisions/math.h"

#include "constants.h"
#include "geometry.h"

int maxAbsValue(std::vector<int> values)
{
    int max = values[0];
    for (int i = 0; i < size(values); i++)
    {
        if (abs(values[i]) > abs(max))
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
