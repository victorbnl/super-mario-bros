#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>

#include "camera.h"
#include "ltexture.h"
#include "character.h"
#include "level/level.h"
#include "physics/physics.h"

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

        // Camera
        Camera mCamera;

        // Tiles
        Level mLevel;

        // Character
        Character mCharacter;

        // Physics engine
        PhysicsEngine mPhysics;
};

#endif
