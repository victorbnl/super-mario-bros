#include "spritesheet/sprite.h"

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite()
{
    texture = NULL;
    w = h = 0;
}

Sprite::~Sprite()
{
    if (texture != NULL)
        SDL_DestroyTexture(texture);
}

void Sprite::loadFromFile(SDL_Renderer* renderer, std::string path)
{
    // Load as surface
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL)
        std::cout << "Failed to load surface: " << path << std::endl;

    // Get dimensions
    w = surface->w;
    h = surface->h;

    // Convert to texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Free surface
    SDL_FreeSurface(surface);
}
