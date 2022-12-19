#include "physics/collisions/collisions.h"

#include "entities/character.h"
#include "level/level.h"
#include "physics/collisions/solve_collisions.h"

void CollisionsEngine::init(Character* character, Level* level)
{
    mCharacter = character;
    mLevel = level;
}

void CollisionsEngine::solveX()
{
    solveCollisionsX(mCharacter, mLevel);
}

void CollisionsEngine::solveY()
{
    solveCollisionsY(mCharacter, mLevel);
}
