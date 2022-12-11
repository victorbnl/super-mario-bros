#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ltexture.h"

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

LTexture gSkyTexture;
LTexture gCharacterTexture;

bool init()
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to initialise SDL" << std::endl;
        return false;
    }

    // Initialise PNG image loader
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "Failed to initialise SDL" << std::endl;
        return false;
    }

    // Create a window
    gWindow = SDL_CreateWindow(
        "Super Mario Bros",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (gWindow == NULL)
    {
        std::cout << "Failed to initialise window" << std::endl;
        return false;
    }

    // Create renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    if (gRenderer == NULL)
    {
        std::cout << "Failed to create renderer" << std::endl;
        return false;
    }

    // Load sky texture
    if (!gSkyTexture.loadFromFile(gRenderer, "assets/sky.png"))
    {
        std::cout << "Failed to load sky texture" << std::endl;
        return false;
    }

    // Load character texture
    if (!gCharacterTexture.loadFromFile(gRenderer, "assets/character.png"))
    {
        std::cout << "Failed to load character texture" << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char* args[])
{
    // Initialise everything
    if (!init())
    {
        std::cout << "Failed to initialise" << std::endl;
        return 1;
    }

    // Draw sky
    gSkyTexture.render(gRenderer, 0, 0);

    // Draw character
    gCharacterTexture.render(gRenderer, 70, SCREEN_HEIGHT-(100+gCharacterTexture.getHeight()));

    // Update
    SDL_RenderPresent(gRenderer);

    // Main loop
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

    return 0;
}
