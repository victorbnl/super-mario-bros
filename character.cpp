#include <iostream>
#include <string>

#include "character.h"

const float SPEED = 0.5;

Character::Character()
{
    mX = 70;
    mY = 400;
}

Character::~Character()
{
    mTexture.free();
}

bool Character::loadTextureFromFile(SDL_Renderer* renderer, std::string path)
{
    if (!mTexture.loadFromFile(renderer, path))
    {
        std::cout << "Failed to load character texture: " << path << std::endl;
        return false;
    }

    return true;
}

void Character::move(int direction)
{
    mX += SPEED * direction;
}

void Character::update(SDL_Renderer* renderer)
{
    // Move character according to velocity
    mTexture.render(renderer, round(mX), round(mY));
}
