#include <iostream>
#include <SDL2/SDL_image.h>

#include "ltexture.h"

LTexture::LTexture()
{
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    free();
}

void LTexture::free()
{
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path)
{
    // Load image into a surface
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL)
    {
        std::cout << "Failed to load surface: " << path << std::endl;
        return false;
    }

    // Get image dimensions
    mWidth = surface->w;
    mHeight = surface->h;

    // Create a texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        std::cout << "Failed to create texture from surface: " << path << std::endl;
        return false;
    }

    // Free old surface
    SDL_FreeSurface(surface);

    mTexture = texture;

    return true;
}

void LTexture::render(SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect dstRect;
    dstRect = {x, y, mWidth, mHeight};
    SDL_RenderCopy(renderer, mTexture, NULL, &dstRect);
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}
