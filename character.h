#ifndef CHARACTER_INCLUDE_GUARD
#define CHARACTER_INCLUDE_GUARD

#include <string>
#include <SDL2/SDL.h>

#include "ltexture.h"

class Character
{
    public:

        // Constructor
        Character();

        // Load texture
        bool loadTextureFromFile(SDL_Renderer* renderer, std::string path);

        // Free texture
        void freeTexture();

        // Move character horizontally
        void moveX(int direction);

        // Move character vertically
        void moveY(int direction);

        // Render character
        void update(SDL_Renderer* renderer);

    private:

        // Texture
        LTexture mTexture;

        // Character position
        float mPosX, mPosY;
};

#endif
