#include "physics.h"

#include "../character.h"
#include "../level/level.h"
#include "../constants.h"

void PhysicsEngine::init(Character* character)
{
    // Initialise variables
    mCharacter = character;
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
}
