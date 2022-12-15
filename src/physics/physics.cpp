#include "physics.h"

#include "../character.h"
#include "../level/level.h"
#include "../constants.h"

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
    if (mCharacter->vel.y < GRAVITY)
        mCharacter->vel.y += 1;

    // Apply forces
    mCharacter->pos.y += mCharacter->vel.y * SPEED;

    // Update character's collider
    mCharacter->updateCollider();

    // Update collisions
    mCollisions.update();
}
