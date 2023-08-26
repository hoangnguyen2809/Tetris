#include <raylib.h>

int main()
{
    Color darkGrey = { 20,20,20,20 };

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetrix");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGrey);
       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}