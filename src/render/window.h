#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "../structs.h"
#include "ltexture.h"

class Window
{
    public:

        // Initialise window
        Window();

        // Free everything
        ~Window();

        // Load texture from file, return a pointer to the loaded texture
        LTexture* loadTexture(std::string path);

        // Render texture
        void drawTexture(Coordinates pos, LTexture* texture);

        // Clear window
        void clear();

        // Update renderer
        void update();

    private:

        // Window
        SDL_Window* mWindow;

        // Renderer
        SDL_Renderer* mRenderer;

        // Loaded textures
        std::vector<LTexture*> mTextures;
};

#endif
