#pragma once

#include "raylib.h"

const int NUM_ROWS = 20;
const int NUM_COLUMS = 10;
const int BOX_SIZE = 40;
const int HEIGHT_OFFSET = 20;
const int WIDTH_OFFSET = 250;
const int WINDOW_HEIGHT = NUM_ROWS * BOX_SIZE + HEIGHT_OFFSET;
const int WINDOW_WIDTH = NUM_COLUMS * BOX_SIZE + WIDTH_OFFSET;
const float DELAY_TETRIS_UPDATE = 0.4f;
const Color GREEN_BACKGROUND = Color{153, 176, 134, 255};
const Color EMPTY_BOX = Color{135, 147, 114, 255};

enum class EBlockRotationState
{
    UP_ROTATION,
    RIGHT_ROTATION,
    BOTTOM_ROTATION,
    LEFT_ROTATION
};