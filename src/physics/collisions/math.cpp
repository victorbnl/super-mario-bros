#include "physics/collisions/math.h"

#include "constants.h"
#include "structures.h"

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

SidesCoords getSidesCoords(Rectangle collider)
{
    SidesCoords sidesCoords;

    sidesCoords.top = collider.y;
    sidesCoords.bottom = collider.y + collider.h;
    sidesCoords.left = collider.x;
    sidesCoords.right = collider.x + collider.w;

    return sidesCoords;
}
