#include "Grid.h"
#include <iostream>

Grid::Grid()
{
    ResetGridArray();
}

void Grid::Draw()
{
    for (int i = 0; i < NUM_ROWS; ++i)
    {
        for (int j = 0; j < NUM_COLUMS; j++)
        {
            if (GridArray[i][j] == 0)
            {
                DrawRectangleLines(j * BOX_SIZE + HEIGHT_OFFSET / 2, i * BOX_SIZE + HEIGHT_OFFSET / 2, BOX_SIZE, BOX_SIZE, EMPTY_BOX);
                DrawRectangle(
                    j * BOX_SIZE + 6 + HEIGHT_OFFSET / 2, i * BOX_SIZE + 6 + HEIGHT_OFFSET / 2, BOX_SIZE - 12, BOX_SIZE - 12, EMPTY_BOX);
            }
            else if (GridArray[i][j] == 1)
            {
                DrawRectangleLinesEx(
                    Rectangle{float(j) * BOX_SIZE + HEIGHT_OFFSET / 2, float(i) * BOX_SIZE + HEIGHT_OFFSET / 2, BOX_SIZE, BOX_SIZE}, 2.f,
                    BLACK);
                DrawRectangle(
                    j * BOX_SIZE + 6 + HEIGHT_OFFSET / 2, i * BOX_SIZE + 6 + HEIGHT_OFFSET / 2, BOX_SIZE - 12, BOX_SIZE - 12, BLACK);
            }
        }
    }
}

void Grid::Restart() 
{
    ResetGridArray();
}

int Grid::LockBlock(const std::vector<Vector2>& BlockLocation)
{
    for (const Vector2& Location : BlockLocation)
    {
        GridArray[int(Location.x)][int(Location.y)] = 1;
    }

    return HandleCompleteRows();
}

bool Grid::CheckCollisionWithAllBlocks(const std::vector<Vector2>& BlockLocation) const
{
    for (const Vector2& Location : BlockLocation)
    {
        if (GridArray[int(Location.x)][int(Location.y)] == 1)
        {
            return true;
        }
    }
    return false;
}

void Grid::ResetGridArray()
{
    for (int i = 0; i < NUM_ROWS; ++i)
    {
        for (int j = 0; j < NUM_COLUMS; j++)
        {
            GridArray[i][j] = 0;
        }
    }
}

int Grid::HandleCompleteRows()
{
    int CompletedRows = 0;

    for (int i = 0; i < NUM_ROWS; ++i)
    {
        for (int j = 0; j < NUM_COLUMS; j++)
        {
            if (GridArray[i][j] == 0)
            {
                break;
            }
            else if (j == NUM_COLUMS - 1)
            {
                ++CompletedRows;

                ClearCompletedRow(i);
                MoveDownRows(i);
            }
        }
    }

    return CompletedRows;
}

void Grid::ClearCompletedRow(int Height)
{
    for (int j = 0; j < NUM_COLUMS; j++)
    {
        GridArray[Height][j] = 0;
    }
}

void Grid::MoveDownRows(int RowsTo)
{
    for (int i = RowsTo - 1; i >= 0; --i)
    {
        for (int j = 0; j < NUM_COLUMS; j++)
        {
            GridArray[i + 1][j] = GridArray[i][j];
        }
    }
}

void Grid::DrawGridArray()
{
    for (int i = 0; i < NUM_ROWS; ++i)
    {
        for (int j = 0; j < NUM_COLUMS; j++)
        {
            std::cout << GridArray[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
