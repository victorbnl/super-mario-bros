#include "render/window.h"

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"

Window::Window()
{
    // Initialise SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;

    // Initialise PNG image loader
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        std::cout << "Failed to initialise IMG loader: " << IMG_GetError() << std::endl;

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

    // Load sprites
    mSpriteSheet.load(mRenderer);
}

Window::~Window()
{
    // Destroy SDL entities
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    // Quit SDL
    IMG_Quit();
    SDL_Quit();
}

void Window::drawSprite(Coordinates pos, int sprite)
{
    Sprite* actualSprite = mSpriteSheet.get(sprite);

    SDL_Rect dstRect;
    dstRect = {pos.x, pos.y, actualSprite->w, actualSprite->h};

    SDL_RenderCopy(mRenderer, actualSprite->texture, NULL, &dstRect);
}

void Window::clear()
{
    SDL_RenderClear(mRenderer);
}

void Window::update()
{
    SDL_RenderPresent(mRenderer);
}

void Window::renderWorld(World* world, int cameraX)
{
    // Clear screen
    clear();

    // Draw background
    drawSprite({0, 0}, world->backgroundSprite);

    // Draw level tiles
    for (int i = 0; i < size(world->level.tiles); i++)
    {
        for (int j = 0; j < size(world->level.tiles[i]); j++)
        {
            if (world->level.tiles[i][j].sprite > -1)
            {
                int x = j * TILE_SIZE;
                int y = i * TILE_SIZE;

                drawSprite(
                    {
                        x - cameraX,
                        y
                    },
                    world->level.tiles[i][j].sprite
                );
            }
        }
    }

    // Render character
    drawSprite(
        {
            (int)world->character.body.x - cameraX,
            (int)world->character.body.y
        },
        world->character.sprite
    );

    // Update renderer
    update();
}
