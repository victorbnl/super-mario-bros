#ifndef PHYSICS_RIGIDBODY_H
#define PHYSICS_RIGIDBODY_H

class RigidBody
{
    public:

        // Constructor
        RigidBody();
        void init(int x_, int y_, int w_, int h_);
        void update();

        // Position
        int x;
        int y;

        // Size
        int w;
        int h;

        // Other representation of coordinates for easier calculations
        int left;
        int right;
        int top;
        int bottom;

        // Velocity
        float velX;
        float velY;
};

#endif
