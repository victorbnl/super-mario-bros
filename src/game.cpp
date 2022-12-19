#include "game.h"

#include "constants.h"
#include "geometry.h"
#include "render/ltexture.h"

Game::Game()
{
    // Initialise controller
    mController.init(&mCharacter);

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
    bool quit = false;
    while (quit == false)
    {
        // Update physics (apply forces and solve collisions)
        mPhysics.update();

        // Set character's X velocity to 0
        // so that it stops walking when releasing arrow keys
        mCharacter.stand();

        // Handle input
        mController.update(&quit);

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
    }
}
