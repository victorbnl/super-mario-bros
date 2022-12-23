#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include <SDL2/SDL.h>

class Sprite
{
    public:

        Sprite();
        ~Sprite();

        void loadFromFile(SDL_Renderer* renderer, std::string path);

        int w, h;

        SDL_Texture* texture;
};

#endif
