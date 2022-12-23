#ifndef CONSTANTS_H
#define CONSTANTS_H

// Tiles
inline const int TILE_SIZE = 48;

// Window size
inline const int SCREEN_WIDTH = 15 * TILE_SIZE;
inline const int SCREEN_HEIGHT = 9 * TILE_SIZE;
inline const int SCREEN_PADDING_X = 250;

// Speed
inline const int CHARACTER_SPEED = 6;
inline const float GRAVITY = 20;
inline const float GRAVITY_STEPS = 0.5;
inline const float JUMP_HEIGHT = GRAVITY * 0.5;

// Sprite sheet
inline const int SPRITESHEET_LENGTH = 6;
enum SPRITES {
    GRASS,
    DIRT,
    BRICKS,
    LUCK,
    CHARACTER,
    SKY
};

#endif
