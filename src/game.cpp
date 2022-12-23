#include "game.h"

#include "constants.h"
#include "geometry.h"

Game::Game()
{
    // Initialise controller (handle input)
    mController.init(&mWorld.character);

    // Initialise camera
    mCamera.init(&mWorld.character, mWorld.level.body);

    // Initialise physics engine
    mPhysics.init(&mWorld.character, &mWorld.level);

    // Initialise collisions engine
    mCollisions.init(&mWorld.character, &mWorld.level);
}

void Game::main()
{
    // Main loop
    bool quit = false;
    while (quit == false)
    {
        // Update physics (apply forces)
        mPhysics.update();

        // Solve collisions
        mCollisions.solve();

        // Set character's X velocity to 0
        // so that it stops walking when releasing arrow keys
        mWorld.character.stand();

        // Handle input
        mController.update(&quit);

        // Update camera
        mCamera.update();

        // Render
        mWindow.renderWorld(&mWorld, mCamera.x);
    }
}
