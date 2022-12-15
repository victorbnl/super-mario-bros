#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <SDL2/SDL.h>

#include "ltexture.h"
#include "structs.h"
#include "camera.h"

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

        // Update character's collider
        void updateCollider();

        // Render character
        void render(SDL_Renderer* renderer, Camera* camera);

        // Character position
        Position pos;

        // Character velocity
        Velocity vel;

    private:

        // Texture
        LTexture mTexture;

        // Collider
        SDL_Rect mCollider;

        bool mIsJumping;
};

#endif
