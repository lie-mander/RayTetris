#include "Block.h"

Block::Block()
{
    RotationState = EBlockRotationState::UP_ROTATION;
    ColumOffset = NUM_COLUMS / 2 - 2;
}

void Block::Draw(int OffsetX, int OffsetY)
{
    SetLocationByOffset();

    for (Vector2 Location : BlockLocation)
    {
        DrawRectangleLinesEx(
            Rectangle{
                Location.y * BOX_SIZE + HEIGHT_OFFSET / 2 + OffsetX,  //
                Location.x * BOX_SIZE + HEIGHT_OFFSET / 2 + OffsetY,  //
                BOX_SIZE,                                             //
                BOX_SIZE                                              //
            },                                                        //
            2.f,                                                      //
            BLACK                                                     //
        );
        DrawRectangle(                                                //
            Location.y * BOX_SIZE + 6 + HEIGHT_OFFSET / 2 + OffsetX,  //
            Location.x * BOX_SIZE + 6 + HEIGHT_OFFSET / 2 + OffsetY,  //
            BOX_SIZE - 12,                                            //
            BOX_SIZE - 12,                                            //
            BLACK                                                     //
        );
    }
}

void Block::Rotate()
{
    switch (RotationState)
    {
        case EBlockRotationState::UP_ROTATION: RotationState = EBlockRotationState::RIGHT_ROTATION; break;
        case EBlockRotationState::RIGHT_ROTATION: RotationState = EBlockRotationState::BOTTOM_ROTATION; break;
        case EBlockRotationState::BOTTOM_ROTATION: RotationState = EBlockRotationState::LEFT_ROTATION; break;
        case EBlockRotationState::LEFT_ROTATION: RotationState = EBlockRotationState::UP_ROTATION; break;
    }

    SetLocationByOffset();
}

void Block::UndoRotate()
{
    switch (RotationState)
    {
        case EBlockRotationState::UP_ROTATION: RotationState = EBlockRotationState::LEFT_ROTATION; break;
        case EBlockRotationState::RIGHT_ROTATION: RotationState = EBlockRotationState::UP_ROTATION; break;
        case EBlockRotationState::BOTTOM_ROTATION: RotationState = EBlockRotationState::RIGHT_ROTATION; break;
        case EBlockRotationState::LEFT_ROTATION: RotationState = EBlockRotationState::BOTTOM_ROTATION; break;
    }

    SetLocationByOffset();
}

void Block::Move(int RowToMove, int ColumToMove)
{
    RowOffset += RowToMove;
    ColumOffset += ColumToMove;

    SetLocationByOffset();
}

void Block::SetLocationByOffset()
{
    BlockLocation = RotationMap[RotationState];

    for (Vector2& Location : BlockLocation)
    {
        Location.x += float(RowOffset);
        Location.y += float(ColumOffset);
    }
}

bool Block::IsBlockOutside() const
{
    for (const Vector2& Location : BlockLocation)
    {
        if (Location.x >= NUM_ROWS || Location.x < 0 || Location.y >= NUM_COLUMS || Location.y < 0)
        {
            return true;
        }
    }
    return false;
}
