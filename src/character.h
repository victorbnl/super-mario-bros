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

        // Move character
        void moveX(int direction);
        void moveY(int direction);

        // Get collider
        SDL_Rect getCollider();

        // Render character
        void update(SDL_Renderer* renderer);

    private:

        // Texture
        LTexture mTexture;

        // Collider
        SDL_Rect mCollider;

        // Character position
        float mPosX, mPosY;
};

#endif
