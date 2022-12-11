#include <iostream>
#include <string>

#include "character.h"

const float SPEED = 5;

Character::Character()
{
    mPosX = 70;
    mPosY = 200;
}

bool Character::loadTextureFromFile(SDL_Renderer* renderer, std::string path)
{
    bool success = true;

    if (!mTexture.loadFromFile(renderer, path))
    {
        std::cout << "Failed to load character texture: " << path << std::endl;
        success = false;
    }

    // Initialise collider
    mCollider = {mPosX, mPosY, mTexture.getWidth(), mTexture.getHeight()};

    return success;
}

void Character::freeTexture()
{
    mTexture.free();
}

void Character::moveX(int distance)
{
    mPosX += distance;
    mCollider.x = mPosX;
}

void Character::moveY(int distance)
{
    mPosY += distance;
    mCollider.y = mPosY;
}

SDL_Rect Character::getCollider()
{
    return mCollider;
}

void Character::update(SDL_Renderer* renderer)
{
    mTexture.render(renderer, mPosX, mPosY);
}
