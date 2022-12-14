#include <iostream>
#include <string>

#include "character.h"
#include "constants.h"
#include "camera.h"

Character::Character()
{
    pos = {150, 200};
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
    mCollider = {(int)pos.x, (int)pos.y, mTexture.getWidth(), mTexture.getHeight()};

    return success;
}

void Character::freeTexture()
{
    mTexture.free();
}

void Character::moveX(int distance)
{
    pos.x += distance;
    mCollider.x = pos.x;
}

void Character::moveY(int distance)
{
    pos.y += distance;
    mCollider.y = pos.y;
}

SDL_Rect Character::getCollider()
{
    return mCollider;
}

void Character::update()
{
    mCollider.x = pos.x;
    mCollider.y = pos.y;

    moveY(SPEED * mVel.y);
}

void Character::render(SDL_Renderer* renderer, Camera* camera)
{
    int x = pos.x - camera->x;
    int y = pos.y;
    mTexture.render(renderer, x, y);
}
