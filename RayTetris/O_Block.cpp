#include "O_Block.h"

O_Block::O_Block() 
{
    Id = 3;
    RotationMap[EBlockRotationState::UP_ROTATION] = {Vector2{0, 0}, Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}};
    RotationMap[EBlockRotationState::RIGHT_ROTATION] = {Vector2{0, 0}, Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}};
    RotationMap[EBlockRotationState::BOTTOM_ROTATION] = {Vector2{0, 0}, Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}};
    RotationMap[EBlockRotationState::LEFT_ROTATION] = {Vector2{0, 0}, Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}};

    ColumOffset = NUM_COLUMS / 2 - 1;
}
