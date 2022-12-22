#include "physics/physics.h"

#include "constants.h"
#include "entities/character.h"
#include "level/level.h"

void PhysicsEngine::init(Character* character, Level* level)
{
    // Initialise variables
    mCharacter = character;
    mLevel = level;

    // Initialise collisions engine
    mCollisions.init(character, level);
}

void PhysicsEngine::update()
{
    // Add gravity
    if (mCharacter->body.vel.y < GRAVITY)
        mCharacter->body.vel.y += GRAVITY_STEPS;

    // Apply X velocity
    mCharacter->body.x += mCharacter->body.vel.x;
    mCharacter->body.y += mCharacter->body.vel.y;

    // Solve collisions
    mCollisions.solve();
}
