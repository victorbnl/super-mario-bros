#ifndef GAME_H
#define GAME_H

#include "camera.h"
#include "controller.h"
#include "entities/character.h"
#include "render/ltexture.h"
#include "render/window.h"
#include "level/level.h"
#include "physics/physics.h"

class Game
{
    public:

        // Constructor
        Game();

        // Main
        void main();

    private:

        // Window
        Window mWindow;

        // Controller (handle input)
        Controller mController;

        // Camera
        Camera mCamera;

        // Background
        LTexture* mBackgroundTexture;

        // Tiles
        Level mLevel;

        // Character
        Character mCharacter;

        // Physics engine
        PhysicsEngine mPhysics;
};

#endif
