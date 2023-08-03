#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval){ }

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        game.MoveBlockDown();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}