#include "ltexture.h"

#include <iostream>
#include <memory>
#include <SDL2/SDL_image.h>

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
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path)
{
    bool success = true;

    // Load image into a surface
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL)
    {
        std::cout << "Failed to load surface: " << path << std::endl;
        success = false;
    }

    // Get image dimensions
    mWidth = surface->w;
    mHeight = surface->h;

    // Create a texture from the surface
    mTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (mTexture == NULL)
    {
        std::cout << "Failed to create texture from surface: " << path << std::endl;
        success = false;
    }

    // Free old surface
    SDL_FreeSurface(surface);

    return success;
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
