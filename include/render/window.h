#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "geometry.h"
#include "world.h"
#include "spritesheet/spritesheet.h"

class Window
{
    public:

        // Initialise window
        Window();

        // Free everything
        ~Window();

        // Render texture
        void drawSprite(Coordinates pos, int sprite);

        // Clear window
        void clear();

        // Update renderer
        void update();

        // Render world
        void renderWorld(World* world, int cameraX);

    private:

        // Window
        SDL_Window* mWindow;

        // Renderer
        SDL_Renderer* mRenderer;

        // Loaded textures
        SpriteSheet mSpriteSheet;
};

#endif
