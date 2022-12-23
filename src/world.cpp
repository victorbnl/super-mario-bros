#include "world.h"

#include "constants.h"
#include "geometry.h"
#include "render/window.h"

World::World()
{
    // Set background
    backgroundSprite = SPRITES::SKY;

    // Initialise level
    level.load("assets/levels/level.csv");
}
