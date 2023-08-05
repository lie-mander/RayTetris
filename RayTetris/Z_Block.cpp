#include "Z_Block.h"

Z_Block::Z_Block() 
{
    Id = 6;
    RotationMap[EBlockRotationState::UP_ROTATION] = {Vector2{0, 0}, Vector2{0, 1}, Vector2{1, 1}, Vector2{1, 2}};
    RotationMap[EBlockRotationState::RIGHT_ROTATION] = {Vector2{0, 2}, Vector2{1, 1}, Vector2{1, 2}, Vector2{2, 1}};
    RotationMap[EBlockRotationState::BOTTOM_ROTATION] = {Vector2{1, 0}, Vector2{1, 1}, Vector2{2, 1}, Vector2{2, 2}};
    RotationMap[EBlockRotationState::LEFT_ROTATION] = {Vector2{0, 1}, Vector2{1, 0}, Vector2{1, 1}, Vector2{2, 0}};
}
