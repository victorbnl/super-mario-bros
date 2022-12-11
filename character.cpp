#include <iostream>
#include <string>

#include "character.h"

const float SPEED = 5;

Character::Character()
{
    mPosX = 70;
    mPosY = 400;
}

bool Character::loadTextureFromFile(SDL_Renderer* renderer, std::string path)
{
    bool success = true;

    if (!mTexture.loadFromFile(renderer, path))
    {
        std::cout << "Failed to load character texture: " << path << std::endl;
        success = false;
    }

    return success;
}

void Character::freeTexture()
{
    mTexture.free();
}

void Character::move(int direction)
{
    mPosX += SPEED * direction;
}

void Character::update(SDL_Renderer* renderer)
{
    mTexture.render(renderer, mPosX, mPosY);
}
