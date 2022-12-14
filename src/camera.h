#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

#include "structs.h"

class Character;

class Camera
{
    public:

        Camera();

        void followCharacter(Character* character);

        void update();

        int x;

    private:

        Character* mCharacter;
};

#endif
