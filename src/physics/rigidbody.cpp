#include "rigidbody.h"

RigidBody::RigidBody()
{
    x = 0;
    y = 0;

    w = 0;
    h = 0;

    velX = 0;
    velY = 0;
}

void RigidBody::init(int x_, int y_, int w_, int h_)
{
    x = x_;
    y = y_;

    w = w_;
    h = h_;

    update();
}

void RigidBody::update()
{
    left = x;
    right = x + w;
    top = y;
    bottom = y + h;
}
