#include "collisions.h"

#include "../../character.h"
#include "../../level/level.h"
#include "../../structures.h"
#include "solve_collisions.h"

void CollisionsEngine::init(Character* character, Level* level, Rectangle levelBoundaries)
{
    mCharacter = character;
    mLevel = level;
    mLevelBoundaries = levelBoundaries;
}

void CollisionsEngine::solveX()
{
    solveCollisionsX(mCharacter, mLevel, mLevelBoundaries);
}

void CollisionsEngine::solveY()
{
    solveCollisionsY(mCharacter, mLevel, mLevelBoundaries);
}
