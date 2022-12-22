#include "physics/collisions/collisions.h"

#include <vector>
#include <cmath>

#include "entities/character.h"
#include "level/level.h"
#include "physics/collisions/get_collisions.h"

void CollisionsEngine::init(Character* character, Level* level)
{
    mCharacter = character;
    mLevel = level;
}

void CollisionsEngine::solve()
{
    std::vector<Collision> collisions = getCollisions(mCharacter, mLevel);

    while (collisions.size() > 0)
    {
        Vector move {0, 0};

        // Deal with first collision
        Collision collision = collisions[0];

        // Remove current velocity if collision resolved
        if (collision.solution.x != 0)
            mCharacter->body.vel.x = 0;
        if (collision.solution.y != 0)
            mCharacter->body.vel.y = 0;

        // If character is moved up to solve a collision, he is on the ground
        if (collision.solution.y < 0)
            mCharacter->isOnGround = true;

        // Actually move the character
        mCharacter->body.x += collision.solution.x;
        mCharacter->body.y += collision.solution.y;

        collisions = getCollisions(mCharacter, mLevel);
    }
}
