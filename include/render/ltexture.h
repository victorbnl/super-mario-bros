#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <string>

#include <SDL2/SDL.h>

class LTexture
{
    public:

        // Constructor
        LTexture();

        // Destructor
        ~LTexture();

        // Free texture
        void free();

        // Load texture from file
        void loadFromFile(SDL_Renderer* renderer, std::string path);

        // Actual SDL texture
        SDL_Texture* sTexture;

        // Texture dimensions
        int w, h;
};

#endif
