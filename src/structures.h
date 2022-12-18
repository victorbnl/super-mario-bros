#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Coordinates
{
    int x;
    int y;
};

struct Position
{
    float x;
    float y;
};

struct Vector
{
    int x;
    int y;
};

struct Velocity
{
    float x;
    float y;
};

class Rectangle
{
    public:

        Rectangle();
        void init(int x_, int y_, int w_, int h_);
        void update();

        // Coordinates
        int x;
        int y;

        // Dimensions
        int w;
        int h;

        // Coordinates of the sides
        int left;
        int right;
        int top;
        int bottom;
};

#endif
