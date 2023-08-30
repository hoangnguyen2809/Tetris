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
    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGrey);
        
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}