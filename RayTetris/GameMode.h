#pragma once

#include "Grid.h"
#include "Block.h"
#include <vector>

class GameMode
{
public:
    GameMode();
    ~GameMode();

    void HandleInput();
    void Update();
    void Draw();

private:
    Grid GameGrid;
    Block CurrentBlock;
    Block NextBlock;
    std::vector<Block> Blocks;
    bool bGameOver = false;
    int Score = 0;

    Font Font;
    Texture2D Logo;
    Music LoopMusic;
    Sound Confirm;
    Sound Swap;
    Sound Fail;

    void SetCurrentBlock();
    void SetRandomNextBlock();
    void FillBlocksArray();
    void MoveBlockRight();
    void MoveBlockLeft();
    void MoveBlockBottom();
    void RotateBlock();
    void AddScore(int NumOfRows);
    void Restart();

    // Timer for update movement
    float LastUpdateTime = 0.0;

    bool CanUpdate();
};
