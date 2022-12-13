#ifndef CHARACTER_INCLUDE_GUARD
#define CHARACTER_INCLUDE_GUARD

#include <string>
#include <SDL2/SDL.h>

#include "ltexture.h"
#include "structs.h"

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

        // Jump
        void jump();

        // Get collider
        SDL_Rect getCollider();

        // Update character
        void update();

        // Render character
        void render(SDL_Renderer* renderer);

        // Character position
        Position mPos;

        // Character velocity
        Velocity mVel;

    private:

        // Texture
        LTexture mTexture;

        // Collider
        SDL_Rect mCollider;

        bool mIsJumping;
};

#endif
