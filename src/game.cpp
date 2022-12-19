#include "game.h"

#include "constants.h"
#include "geometry.h"
#include "render/ltexture.h"

Game::Game()
{
    // Initialise controller (handle input)
    mController.init(&mWorld.character);

    // Initialise world (level & entities)
    mWorld.init(&mWindow);

    // Initialise camera
    mCamera.init(&mWorld.character, mWorld.level.body);

    // Initialise physics engine
    mPhysics.init(&mWorld.character, &mWorld.level);
}

void Game::main()
{
    // Main loop
    bool quit = false;
    while (quit == false)
    {
        // Update physics (apply forces and solve collisions)
        mPhysics.update();

        // Set character's X velocity to 0
        // so that it stops walking when releasing arrow keys
        mWorld.character.stand();

        // Handle input
        mController.update(&quit);

        // Update camera
        mCamera.update();

        // Render
        mWorld.render(&mWindow, mCamera.x);
    }
}
