#pragma once

#include <vector>
#include <map>
#include "raylib.h"
#include "GameTypes.h"

class Block
{
public:
    Block();

    void Draw(int OffsetX, int OffsetY);
    void Rotate();
    void UndoRotate();
    void Move(int RowToMove, int ColumToMove);

    void SetLocationByOffset();
    std::vector<Vector2> GetBlockLocation() const { return BlockLocation; }
    bool IsBlockOutside() const;

protected:
    int Id = 0;

    int RowOffset = 0;
    int ColumOffset = 0;

    // Vector2.x = Row
    // Vector2.y = Colum
    std::map<EBlockRotationState, std::vector<Vector2>> RotationMap;

private:
    std::vector<Vector2> BlockLocation;
    EBlockRotationState RotationState;
};
