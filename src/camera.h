#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>

#include "structures.h"

class Character;

class Camera
{
    public:

        Camera();

        void init(Character* character, Rectangle levelBoundaries);

        void update();

        int x;

    private:

        Character* mCharacter;
        Rectangle mLevelBoundaries;
};

#endif
