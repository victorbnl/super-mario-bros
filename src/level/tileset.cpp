#include "level/tileset.h"

#include <string>

#include "render/ltexture.h"
#include "render/window.h"

LTexture* loadTexture(Window* window, std::string path)
{
    LTexture* texturePtr = window->loadTexture(path);
    return texturePtr;
}

void Tileset::load(Window* window)
{
    std::string prefix = "assets/textures/";
    std::string ext = ".png";

    mTileset[0] = loadTexture(window, prefix + "grass" + ext);
    mTileset[1] = loadTexture(window, prefix + "dirt" + ext);
    mTileset[2] = loadTexture(window, prefix + "bricks" + ext);
    mTileset[3] = loadTexture(window, prefix + "luck" + ext);
}

LTexture* Tileset::get(int type)
{
    LTexture* texturePtr = mTileset[type];
    return texturePtr;
}
