#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
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

    // Draw black rect
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_Rect rect;
    rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderFillRect(gRenderer, &rect);

    // Update
    SDL_RenderPresent(gRenderer);

    // Main loop
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

    return 0;
}
