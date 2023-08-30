#include <raylib.h>
#include<iostream>
#include"game.h"

using namespace std;

int main()
{
    Color darkGrey = { 65,65,65,255 };
    
    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetrix");
    SetTargetFPS(60);
    
    Game game = Game();

    double lastBlockMoveTime = GetTime();

    while (!WindowShouldClose())
    {
        game.handleInput();

        double currentTime = GetTime();
        if (currentTime - lastBlockMoveTime >= 0.002) // Check if 0.2 seconds have passed
        {
            game.moveBlockDown();
            lastBlockMoveTime = currentTime; // Update the last move time
        }
        BeginDrawing();
        ClearBackground(darkGrey);

        game.grid.gridPrint();
        
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}