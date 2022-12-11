#ifndef LTEXTURE_INCLUDE_GUARD
#define LTEXTURE_INCLUDE_GUARD

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
        bool loadFromFile(SDL_Renderer* renderer, std::string path);

        // Render texture
        void render(SDL_Renderer* renderer, int x, int y);

        // Get image dimensions
        int getWidth();
        int getHeight();

    private:

        SDL_Texture* mTexture;
        int mWidth;
        int mHeight;
};

#endif
