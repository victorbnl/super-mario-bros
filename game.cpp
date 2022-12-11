#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"

const int SCREEN_HEIGHT = 500;
const int SCREEN_WIDTH = 500;

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

    // Load sky texture
    if (!mSkyTexture.loadFromFile(mRenderer, "assets/sky.png"))
    {
        std::cout << "Failed to load sky texture" << std::endl;
    }

    // Load character texture
    if (!mCharacter.loadTextureFromFile(mRenderer, "assets/character.png"))
    {
        std::cout << "Failed to load character texture" << std::endl;
    }
}

Game::~Game()
{
    // Free textures
    mSkyTexture.free();
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
            mCharacter.move(-1);
        }
        if (keystates[SDL_SCANCODE_RIGHT])
        {
            mCharacter.move(+1);
        }

        // Draw sky
        mSkyTexture.render(mRenderer, 0, 0);

        // Update character
        mCharacter.update(mRenderer);

        // Update renderer
        SDL_RenderPresent(mRenderer);
    }
}
