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

        // Destructor
        ~Character();

        // Load texture
        bool loadTextureFromFile(SDL_Renderer* renderer, std::string path);

        // Move character horizontally
        void move(int direction);

        // Render character
        void update(SDL_Renderer* renderer);

    private:

        // Texture
        LTexture mTexture;

        // Character position
        float mX;
        float mY;
};

#endif