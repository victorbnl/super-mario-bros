#include "render/ltexture.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

LTexture::LTexture()
{
    sTexture = NULL;
    w = 0;
    h = 0;
}

LTexture::~LTexture()
{
    free();
}

void LTexture::free()
{
    // Destroy the texture if it exists
    if (sTexture != NULL)
        SDL_DestroyTexture(sTexture);
}

void LTexture::loadFromFile(SDL_Renderer* renderer, std::string path)
{
    // Load image into a surface
    SDL_Surface* surface = IMG_Load(path.c_str());

    // Get texture dimensions
    w = surface->w;
    h = surface->h;

    // Create a texture from the surface
    sTexture = SDL_CreateTextureFromSurface(renderer, surface);

    // Free old surface
    SDL_FreeSurface(surface);
}
