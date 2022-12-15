#include "collisions.h"

#include "../../character.h"
#include "../../level/level.h"
#include "../../structs.h"
#include "solve_collisions.h"

void CollisionsEngine::init(Character* character, Level* level, Rectangle levelBoundaries)
{
    mCharacter = character;
    mLevel = level;
    mLevelBoundaries = levelBoundaries;
}

void CollisionsEngine::update()
{
    solveCollisions(mCharacter, mLevel, mLevelBoundaries);
}
