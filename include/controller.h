#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "character.h"

class Controller
{
    public:

        // Initialise controller
        void init(Character* character);

        // Poll key events & react
        void update(bool* quit);

    private:

        Character* mCharacter;
};

#endif
