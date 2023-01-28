#include "world.h"

#include "constants.h"

World::World()
{
    // Set background
    backgroundSprite = SPRITES::SKY;

    // Initialise level
    level.load("assets/levels/level.csv");
}
