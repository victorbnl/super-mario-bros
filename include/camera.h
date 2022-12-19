#ifndef CAMERA_H
#define CAMERA_H

#include "character.h"
#include "physics/bodies.h"

class Character;

class Camera
{
    public:

        Camera();

        void init(Character* character, Body levelBody);

        void update();

        int x;

    private:

        Character* mCharacter;
        Body mLevelBody;
};

#endif
