#ifndef CONSTANTS_H
#define CONSTANTS_H

// Tile size
const int TILE_SIZE = 48;

// Window size
const int SCREEN_WIDTH = 15 * TILE_SIZE;
const int SCREEN_HEIGHT = 9 * TILE_SIZE;
const int SCREEN_PADDING_X = 250;

// Speed
const int CHARACTER_SPEED = 6;
const float GRAVITY = 20;
const float GRAVITY_STEPS = 0.2;
const float JUMP_HEIGHT = GRAVITY * 0.4;

#endif
