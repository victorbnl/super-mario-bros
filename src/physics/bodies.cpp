#include "physics/bodies.h"

#include "physics/structs.h"

Body::Body()
{
    x = 0;
    y = 0;
}

SideCoords Body::getSideCoords()
{
    SideCoords sideCoords;

    sideCoords.left = x;
    sideCoords.right = x + collider.w;
    sideCoords.top = y;
    sideCoords.bottom = y + collider.h;

    return sideCoords;
}
