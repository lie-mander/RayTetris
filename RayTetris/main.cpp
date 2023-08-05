// Created by Liemander

#include "raylib.h"
#include "GameTypes.h"
#include "GameMode.h"

// Main game loop
int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RayTetris");
    SetTargetFPS(60);

    GameMode Game;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN_BACKGROUND);

        Game.HandleInput();
        Game.Update();
        Game.Draw();

        EndDrawing();
    }

    return 0;
}
