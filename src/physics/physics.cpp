#include "physics/physics.h"

#include "character.h"
#include "level/level.h"
#include "constants.h"

void PhysicsEngine::init(Character* character, Level* level, Rectangle levelBoundaries)
{
    // Initialise variables
    mCharacter = character;
    mLevel = level;

    // Initialise collisions engine
    mCollisions.init(character, level, levelBoundaries);
}

void PhysicsEngine::update()
{
    // Add gravity
    if (mCharacter->body.velY < GRAVITY)
        mCharacter->body.velY += GRAVITY_STEPS;

    // Apply X velocity
    mCharacter->body.x += mCharacter->body.velX;
    mCharacter->body.update();
    // Solve X collisions
    mCollisions.solveX();

    // Apply Y velocity
    mCharacter->body.y += mCharacter->body.velY;
    mCharacter->body.update();
    // Solve Y collisions
    mCollisions.solveY();
}
