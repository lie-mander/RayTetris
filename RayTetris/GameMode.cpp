#include "GameMode.h"
#include "raymath.h"
#include "L_Block.h"
#include "J_Block.h"
#include "I_Block.h"
#include "O_Block.h"
#include "S_Block.h"
#include "T_Block.h"
#include "Z_Block.h"
#include <iostream>

GameMode::GameMode()
{
    GameGrid = Grid();

    FillBlocksArray();
    SetRandomNextBlock();
    SetCurrentBlock();

    Font = LoadFontEx("../Content/Font.ttf", 40, 0, 0);

    Image LogoImage = LoadImage("../Content/Dino.png");
    Logo = LoadTextureFromImage(LogoImage);
    UnloadImage(LogoImage);

    InitAudioDevice();
    const int RandMusic = GetRandomValue(0, 2);
    switch (RandMusic)
    {
        case 0: LoopMusic = LoadMusicStream("../Content/Music.mp3"); break;
        case 1: LoopMusic = LoadMusicStream("../Content/Music_1.mp3"); break;
        case 2: LoopMusic = LoadMusicStream("../Content/Music_2.mp3"); break;
    }
    PlayMusicStream(LoopMusic);
    SetMusicVolume(LoopMusic, 0.2f);

    Confirm = LoadSound("../Content/Confirm.mp3");
    SetSoundVolume(Confirm, 0.1f);
    Swap = LoadSound("../Content/Swap.mp3");
    SetSoundVolume(Swap, 0.1f);
    Fail = LoadSound("../Content/Fail.mp3");
    SetSoundVolume(Fail, 0.1f);
}

GameMode::~GameMode()
{
    UnloadFont(Font);
    UnloadTexture(Logo);
    UnloadSound(Confirm);
    UnloadSound(Swap);

    CloseAudioDevice();
}

void GameMode::HandleInput()
{
    if (bGameOver && IsKeyDown(KEY_ENTER))
    {
        Restart();
        bGameOver = false;
    }

    if (bGameOver) return;

    if (IsKeyDown(KEY_DOWN))
    {
        Score += 1;
        MoveBlockBottom();
    }

    int Key = GetKeyPressed();
    switch (Key)
    {
        case KEY_RIGHT: MoveBlockRight(); break;
        case KEY_LEFT: MoveBlockLeft(); break;
        case KEY_UP: RotateBlock(); break;
    }
}

void GameMode::Update()
{
    UpdateMusicStream(LoopMusic);

    if (CanUpdate() && !bGameOver)
    {
        MoveBlockBottom();
    }
}

void GameMode::Draw()
{
    GameGrid.Draw();
    CurrentBlock.Draw(0, 0);
    NextBlock.Draw(320, 300);

    DrawTextEx(Font, "Score:", {470, 40}, 35.f, 2.f, BLACK);
    DrawTextEx(Font, TextFormat("%d", Score), {470, 80}, 35.f, 2.f, BLACK);
    DrawTextEx(Font, "Next:", {470, 220}, 35.f, 2.f, BLACK);
    DrawRectangleLinesEx(Rectangle{HEIGHT_OFFSET / 2, HEIGHT_OFFSET / 2, NUM_COLUMS * BOX_SIZE, NUM_ROWS * BOX_SIZE}, 2.f, BLACK);

    if (bGameOver) 
{
        DrawTexture(Logo, 470, 480, BLACK);
        DrawTextEx(Font, "GAME\nOVER", {480, 650}, 35.f, 2.f, BLACK);
        DrawTextEx(Font, "[Press ENTER]", {430, 750}, 25.f, 2.f, BLACK);
    }
}

void GameMode::SetCurrentBlock()
{
    CurrentBlock = NextBlock;
    CurrentBlock.SetLocationByOffset();

    SetRandomNextBlock();

    if (GameGrid.CheckCollisionWithAllBlocks(CurrentBlock.GetBlockLocation()))
    {
        bGameOver = true;
        PlaySound(Fail);
    }
}

void GameMode::SetRandomNextBlock()
{
    const int RandIndex = GetRandomValue(0, Blocks.size() - 1);
    NextBlock = Blocks[RandIndex];
    Blocks.erase(Blocks.begin() + RandIndex);

    if (Blocks.empty())
    {
        FillBlocksArray();
    }
}

void GameMode::FillBlocksArray()
{
    Blocks = {L_Block(), J_Block(), I_Block(), O_Block(), S_Block(), T_Block(), Z_Block()};
}

void GameMode::MoveBlockRight()
{
    CurrentBlock.Move(0, 1);
    if (CurrentBlock.IsBlockOutside() || GameGrid.CheckCollisionWithAllBlocks(CurrentBlock.GetBlockLocation()))
    {
        CurrentBlock.Move(0, -1);
    }
}

void GameMode::MoveBlockLeft()
{
    CurrentBlock.Move(0, -1);
    if (CurrentBlock.IsBlockOutside() || GameGrid.CheckCollisionWithAllBlocks(CurrentBlock.GetBlockLocation()))
    {
        CurrentBlock.Move(0, 1);
    }
}

void GameMode::MoveBlockBottom()
{
    CurrentBlock.Move(1, 0);
    if (CurrentBlock.IsBlockOutside() || GameGrid.CheckCollisionWithAllBlocks(CurrentBlock.GetBlockLocation()))
    {
        CurrentBlock.Move(-1, 0);
        const int NumOfCompletedRows = GameGrid.LockBlock(CurrentBlock.GetBlockLocation());
        if (NumOfCompletedRows > 0)
        {
            AddScore(NumOfCompletedRows);
        }
        SetCurrentBlock();
    }
}

void GameMode::RotateBlock()
{
    CurrentBlock.Rotate();
    if (CurrentBlock.IsBlockOutside())
    {
        CurrentBlock.UndoRotate();
    }
    else
    {
        PlaySound(Swap);
    }
}

void GameMode::AddScore(int NumOfRows)
{
    PlaySound(Confirm);
    Score += (NumOfRows * 100) + 100;
}

void GameMode::Restart() 
{
    GameGrid.Restart();
    Score = 0;

    FillBlocksArray();
    SetRandomNextBlock();
    SetCurrentBlock();
}

bool GameMode::CanUpdate()
{
    if (GetTime() - LastUpdateTime > DELAY_TETRIS_UPDATE)
    {
        LastUpdateTime = float(GetTime());
        return true;
    }
    return false;
}
