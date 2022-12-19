#include "game.h"

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "camera.h"
#include "level/level.h"
#include "physics/physics.h"

#include<unistd.h>

Game::Game()
{
    // Load background texture
    mBackgroundTexture = mWindow.loadTexture("assets/textures/sky.png");

    // Load character texture
    LTexture* characterTexture = mWindow.loadTexture("assets/textures/character.png");
    mCharacter.init(characterTexture);

    // Load level
    mLevel.load(&mWindow, "assets/levels/level.csv");

    // Initialise camera
    mCamera.init(&mCharacter, mLevel.body);

    // Initialise physics engine
    mPhysics.init(&mCharacter, &mLevel);
}

void Game::main()
{
    // Main loop
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        // Event handlers
        while (SDL_PollEvent( &e ))
        {
            // Quit game
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Get keypresses
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

        // Update physics (apply forces and solve collisions)
        mPhysics.update();

        mCharacter.stand();
        // Left key
        if (keystates[SDL_SCANCODE_LEFT])
            mCharacter.walk(-1);
        // Right key
        if (keystates[SDL_SCANCODE_RIGHT])
            mCharacter.walk(1);
        // Up key
        if (keystates[SDL_SCANCODE_UP])
            mCharacter.jump();

        // mCharacter.body.velX = +1;

        // Update camera
        mCamera.update();

        // Clear screen
        mWindow.clear();

        // Draw background
        mWindow.drawTexture({0, 0}, mBackgroundTexture);

        // Draw level tiles
        for (int i = 0; i < size(mLevel.tiles); i++)
        {
            for (int j = 0; j < size(mLevel.tiles[i]); j++)
            {
                if (mLevel.tiles[i][j].type > -1)
                {
                    Coordinates pos {j * TILE_SIZE, i * TILE_SIZE};
                    mWindow.drawTexture({pos.x - mCamera.x, pos.y}, mLevel.tiles[i][j].texture);
                }
            }
        }

        // Render character
        mWindow.drawTexture(
            {
                (int)mCharacter.body.x - mCamera.x,
                (int)mCharacter.body.y
            },
            mCharacter.texture
        );

        // Update renderer
        mWindow.update();

        // Slow down game for debugging purposes
        // unsigned int second = 1000000;
        // usleep(0.1 * second);
    }
}
