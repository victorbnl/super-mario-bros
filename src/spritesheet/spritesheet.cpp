#include "spritesheet/spritesheet.h"

#include <string>

#include "constants.h"

// TODO: Fix hardcoded values
#include <array>
std::string pathPrefix = "assets/textures/";
std::string pathSuffix = ".png";
std::array<std::string, SPRITESHEET_LENGTH> textures {
    "grass",
    "dirt",
    "bricks",
    "luck",
    "character",
    "sky"
};

void SpriteSheet::load(SDL_Renderer* renderer)
{
    // Load each sprite texture
    for (int i = 0; i < textures.size(); i++)
    {
        std::string path = pathPrefix + textures[i] + pathSuffix;
        sprites[i].loadFromFile(renderer, path);
    }
}

Sprite* SpriteSheet::get(int i)
{
    return &sprites[i];
}
