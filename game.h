#ifndef GAME_INCLUDE_GUARD
#define GAME_INCLUDE_GUARD

#include <SDL2/SDL.h>

#include "ltexture.h"
#include "character.h"

class Game
{
    public:

        // Constructor
        Game();

        // Destructor
        ~Game();

        // Main
        void main();

    private:

        // Window
        SDL_Window* mWindow;

        // Renderer
        SDL_Renderer* mRenderer;

        // Textures
        LTexture mSkyTexture;

        // Character
        Character mCharacter;
};

#endif
