#include "render/window.h"

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "render/ltexture.h"

Window::Window()
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << "Failed to initialise SDL" << std::endl;

    // Initialise PNG image loader
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        std::cout << "Failed to initialise PNG image loader" << std::endl;

    // Create a window
    mWindow = SDL_CreateWindow(
        "Super Mario Bros",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    // Check window creation error
    if (mWindow == NULL)
        std::cout << "Failed to initialise window" << std::endl;

    // Create renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Check renderer creation error
    if (mRenderer == NULL)
        std::cout << "Failed to create renderer" << std::endl;
}

Window::~Window()
{
    // Free all textures
    for (int i = 0; i < size(mTextures); i++)
    {
        mTextures[i]->free();
    }

    // Destroy SDL entities
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    // Quit SDL
    IMG_Quit();
    SDL_Quit();
}

LTexture* Window::loadTexture(std::string path)
{
    // Load texture on the heap
    LTexture* texture = new LTexture();
    texture->loadFromFile(mRenderer, path);
    mTextures.push_back(texture);

    return texture;
}

void Window::drawTexture(Coordinates pos, LTexture* texture)
{
    SDL_Rect dstRect;
    dstRect = {pos.x, pos.y, texture->w, texture->h};
    SDL_RenderCopy(mRenderer, texture->sTexture, NULL, &dstRect);
}

void Window::clear()
{
    SDL_RenderClear(mRenderer);
}

void Window::update()
{
    SDL_RenderPresent(mRenderer);
}
