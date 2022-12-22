#ifndef GAME_H
#define GAME_H

#include "camera.h"
#include "world.h"
#include "controller.h"
#include "render/window.h"
#include "physics/physics.h"
#include "collisions/collisions.h"

class Game
{
    public:

        // Constructor
        Game();

        // Main
        void main();

    private:

        // Window
        Window mWindow;

        // Camera
        Camera mCamera;

        // Controller (handle input)
        Controller mController;

        // World
        World mWorld;

        // Physics engine
        PhysicsEngine mPhysics;

        // Collisions engine
        CollisionsEngine mCollisions;
};

#endif
