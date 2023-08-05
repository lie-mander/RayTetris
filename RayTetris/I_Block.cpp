#include "I_Block.h"

I_Block::I_Block() 
{
    Id = 2;
    RotationMap[EBlockRotationState::UP_ROTATION] = {Vector2{1, 0}, Vector2{1, 1}, Vector2{1, 2}, Vector2{1, 3}};
    RotationMap[EBlockRotationState::RIGHT_ROTATION] = {Vector2{0, 2}, Vector2{1, 2}, Vector2{2, 2}, Vector2{3, 2}};
    RotationMap[EBlockRotationState::BOTTOM_ROTATION] = {Vector2{2, 0}, Vector2{2, 1}, Vector2{2, 2}, Vector2{2, 3}};
    RotationMap[EBlockRotationState::LEFT_ROTATION] = {Vector2{0, 1}, Vector2{1, 1}, Vector2{2, 1}, Vector2{3, 1}};

    RowOffset -= 1;
    ColumOffset = NUM_COLUMS / 2 - 2;
}
