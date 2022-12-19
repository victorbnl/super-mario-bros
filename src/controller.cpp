#include "controller.h"

#include <SDL2/SDL.h>

#include "entities/character.h"

void Controller::init(Character* character)
{
    mCharacter = character;
}

void Controller::update(bool* quit)
{
    // Quit game
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            *quit = true;

    // Get keypresses
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    // Left key
    if (keystates[SDL_SCANCODE_LEFT])
        mCharacter->walk(-1);

    // Right key
    if (keystates[SDL_SCANCODE_RIGHT])
        mCharacter->walk(1);

    // Up key
    if (keystates[SDL_SCANCODE_UP])
        mCharacter->jump();
}
