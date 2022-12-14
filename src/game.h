#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>

#include "ltexture.h"
#include "character.h"
#include "level/level.h"

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

        // Tiles
        Level mLevel;

        // Character
        Character mCharacter;
};

#endif
