#include "game.h"

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "camera.h"
#include "level/level.h"
#include "physics/physics.h"

Game::Game()
{
    // Load background texture
    mBackgroundTexture = mWindow.loadTexture("assets/textures/sky.png");

    // Load character texture
    LTexture* characterTexture = mWindow.loadTexture("assets/textures/character.png");
    mCharacter.init(characterTexture);

    // Load level
    mLevel.load(&mWindow, "assets/levels/level.csv");

    // Calculate level boundaries
    Rectangle levelBoundaries {0, 0, mLevel.getWidth(), SCREEN_HEIGHT};

    // Initialise camera
    mCamera.init(&mCharacter, levelBoundaries);

    // Initialise physics engine
    mPhysics.init(&mCharacter, &mLevel, levelBoundaries);
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

        // Left key
        if (keystates[SDL_SCANCODE_LEFT])
            mCharacter.moveX(-SPEED);
        // Right key
        if (keystates[SDL_SCANCODE_RIGHT])
            mCharacter.moveX(SPEED);
        if (keystates[SDL_SCANCODE_UP])
            mCharacter.jump();

        // Update physics (apply forces and solve collisions)
        mPhysics.update();

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
                if (mLevel.tiles[i][j].getType() > -1)
                {
                    Coordinates pos {j * TILE_SIZE, i * TILE_SIZE};
                    mWindow.drawTexture({pos.x - mCamera.x, pos.y}, mLevel.tiles[i][j].texture);
                }
            }
        }

        // Render character
        mWindow.drawTexture({mCharacter.pos.x - mCamera.x, mCharacter.pos.y}, mCharacter.texture);

        // Update renderer
        mWindow.update();
    }
}
