#include "T_Block.h"

T_Block::T_Block() 
{
    Id = 5;
    RotationMap[EBlockRotationState::UP_ROTATION] = {Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}, Vector2{1, 2}};
    RotationMap[EBlockRotationState::RIGHT_ROTATION] = {Vector2{0, 1}, Vector2{1, 1}, Vector2{1, 2}, Vector2{2, 1}};
    RotationMap[EBlockRotationState::BOTTOM_ROTATION] = {Vector2{1, 0}, Vector2{1, 1}, Vector2{1, 2}, Vector2{2, 1}};
    RotationMap[EBlockRotationState::LEFT_ROTATION] = {Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}, Vector2{2, 1}};
}
