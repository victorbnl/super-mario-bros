#include "structures.h"

Rectangle::Rectangle()
{
    x = 0;
    y = 0;

    w = 0;
    h = 0;

    left = 0;
    right = 0;
    top = 0;
    bottom = 0;
}

void Rectangle::init(int x_, int y_, int w_, int h_)
{
    x = x_;
    y = y_;

    w = w_;
    h = h_;

    update();
}

void Rectangle::update()
{
    left = x;
    right = x + w;
    top = y;
    bottom = y + h;
}
