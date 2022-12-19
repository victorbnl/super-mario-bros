#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include "geometry.h"
#include "physics/structs.h"

class Body
{
    public:

        // Constructor
        Body();

        // Position
        int x;
        int y;

        // Collider
        Rectangle collider;

        // Get coordinates, but as (left, right, top, bottom)
        SideCoords getSideCoords();
};

class StaticBody : public Body {};

class RigidBody : public Body
{
    public:

        // Constructor
        RigidBody();

        // Velocity
        Vector vel;
};

#endif
