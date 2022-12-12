#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "level/level.h"
#include "collisions.h"

const int SCREEN_HEIGHT = 48*10;
const int SCREEN_WIDTH = 48*15;
const int SPEED = 5;

Game::Game()
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to initialise SDL" << std::endl;
    }

    // Initialise PNG image loader
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "Failed to initialise PNG image loader" << std::endl;
    }

    // Create a window
    mWindow = SDL_CreateWindow(
        "Super Mario Bros",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (mWindow == NULL)
    {
        std::cout << "Failed to initialise window" << std::endl;
    }

    // Create renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mRenderer == NULL)
    {
        std::cout << "Failed to create renderer" << std::endl;
    }

    // Load character texture
    if (!mCharacter.loadTextureFromFile(mRenderer, "assets/character.png"))
    {
        std::cout << "Failed to load character texture" << std::endl;
    }

    // Load level
    mLevel.load(mRenderer, "assets/levels/level.csv");
}

Game::~Game()
{
    // Free textures
    mCharacter.freeTexture();

    // Destroy renderer
    SDL_DestroyRenderer(mRenderer);
    mRenderer = NULL;

    // Destroy window
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;

    // Quit SDL
    IMG_Quit();
    SDL_Quit();
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

        // Keypresses handlers
        if (keystates[SDL_SCANCODE_LEFT])
        {
            mCharacter.moveX(-SPEED);
        }
        if (keystates[SDL_SCANCODE_RIGHT])
        {
            mCharacter.moveX(SPEED);
        }

        // Collisions
        solveCollisions(&mCharacter, mLevel, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Clear screen
        SDL_RenderClear(mRenderer);

        // Draw sky
        SDL_SetRenderDrawColor(mRenderer, 0, 169, 255, SDL_ALPHA_OPAQUE);
        SDL_Rect skyRect;
        skyRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_RenderFillRect(mRenderer, &skyRect);

        // Draw tiles
        mLevel.render(mRenderer);

        // Update character
        mCharacter.update(mRenderer);

        // Update renderer
        SDL_RenderPresent(mRenderer);
    }
}
