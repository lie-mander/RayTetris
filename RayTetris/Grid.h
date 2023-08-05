#pragma once

#include "GameTypes.h"
#include <vector>

class Grid
{
public:
    Grid();

    void DrawGridArray();
    void Draw();
    void Restart();
    int LockBlock(const std::vector<Vector2>& BlockLocation);

    bool CheckCollisionWithAllBlocks(const std::vector<Vector2>& BlockLocation) const;

    int GridArray[NUM_ROWS][NUM_COLUMS];

private:
    void ResetGridArray();
    int HandleCompleteRows();
    void ClearCompletedRow(int Height);
    void MoveDownRows(int RowsTo);
};
