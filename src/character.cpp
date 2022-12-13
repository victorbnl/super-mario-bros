#include <iostream>
#include <string>

#include "character.h"
#include "constants.h"

Character::Character()
{
    mPos = {150, 200};
    mVel = {80, 0};
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
    mCollider = {(int)mPos.x, (int)mPos.y, mTexture.getWidth(), mTexture.getHeight()};

    return success;
}

void Character::freeTexture()
{
    mTexture.free();
}

void Character::moveX(int distance)
{
    mPos.x += distance;
    mCollider.x = mPos.x;
}

void Character::moveY(int distance)
{
    mPos.y += distance;
    mCollider.y = mPos.y;
}

SDL_Rect Character::getCollider()
{
    return mCollider;
}

void Character::update()
{
    moveY(SPEED * mVel.y);
}

void Character::render(SDL_Renderer* renderer)
{
    mTexture.render(renderer, mPos.x, mPos.y);
}
