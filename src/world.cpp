#include "world.h"

#include "geometry.h"
#include "render/window.h"

void World::init(Window* window)
{
    // Load background texture
    backgroundTexture = window->loadTexture("assets/textures/sky.png");

    // Initialise level
    level.load(window, "assets/levels/level.csv");

    // Initialise character
    LTexture* characterTexture = window->loadTexture("assets/textures/character.png");
    character.init(characterTexture);
}

void World::render(Window* window, int cameraX)
{
    // Clear screen
    window->clear();

    // Draw background
    window->drawTexture({0, 0}, backgroundTexture);

    // Draw level tiles
    for (int i = 0; i < size(level.tiles); i++)
    {
        for (int j = 0; j < size(level.tiles[i]); j++)
        {
            if (level.tiles[i][j].type > -1)
            {
                Coordinates pos {j * TILE_SIZE, i * TILE_SIZE};
                window->drawTexture(
                    {
                        pos.x - cameraX,
                        pos.y
                    },
                    level.tiles[i][j].texture
                );
            }
        }
    }

    // Render character
    window->drawTexture(
        {
            (int)character.body.x - cameraX,
            (int)character.body.y
        },
        character.texture
    );

    // Update renderer
    window->update();
}
