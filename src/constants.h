#ifndef CONSTANTS_H
#define CONSTANTS_H

// Tile size
const int TILE_SIZE = 48;

// Window size
const int SCREEN_WIDTH = 15 * TILE_SIZE;
const int SCREEN_HEIGHT = 9 * TILE_SIZE;
const int SCREEN_PADDING_X = 150;

// Speed
const int SPEED = 6;
const float GRAVITY = 2;
const float GRAVITY_STEPS = 0.2;
const float JUMP_HEIGHT = GRAVITY_STEPS * 12;

#endif
