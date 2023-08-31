#include <raylib.h>
#include<iostream>
#include"game.h"

using namespace std;

int main()
{
    Color darkGrey = { 65,65,65,255 };
    
    const int screenWidth = 500;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetrix");
    SetTargetFPS(60);
    
    Font font = LoadFontEx("Font/Minecraft.ttf", 64, 0, 0);

    Game game = Game();

    double lastBlockMoveTime = GetTime();

    while (!WindowShouldClose())
    {
        game.handleInput();
       
        static float time = 1;
        if (!game.gameOver)
        {
            double currentTime = GetTime();
            if (currentTime - lastBlockMoveTime >= time) // Check if 0.2 seconds have passed
            {
                game.moveBlockDown();
                lastBlockMoveTime = currentTime; // Update the last move time
            }

            if (game.score >= game.level * 500)
            {
                time -= 0.1; // Decrease the time interval by 0.2 seconds
                game.level++;
            }

            BeginDrawing();
            ClearBackground(darkGrey);

            DrawRectangle(302, 0, 200, 600, black);

            DrawTextEx(font, "Score", { 355, 69 }, 28, 3, white);

            char scoreText[10];
            sprintf_s(scoreText, "%d", game.score);
            Vector2 textSize = MeasureTextEx(font, scoreText, 28, 3);

            DrawTextEx(font, scoreText, { 322 + (170 - textSize.x) / 2, 109 }, 28, 3, white);



            DrawTextEx(font, "Next", { 360, 200 }, 28, 3, white);
            Rectangle nextRectangle = { 316, 230, 170, 130 };
            DrawRectangleRec(nextRectangle, BLACK);
            DrawRectangleLines(nextRectangle.x, nextRectangle.y, nextRectangle.width, nextRectangle.height, darkGrey);

            DrawTextEx(font, "Level", { 360, 420 }, 28, 3, white);

            char levelText[10];
            sprintf_s(levelText, "%d", game.level);
            Vector2 levelTextSize = MeasureTextEx(font, levelText, 28, 3);

            DrawTextEx(font, levelText, { 322 + (170 - levelTextSize.x) / 2, 466 }, 28, 3, white);




            game.grid.gridPrint();
            game.Draw();
        }


        if (game.gameOver)
        {
            ClearBackground(black);
        
            DrawTextEx(font, "GAME OVER", { 120, 210 }, 38, 2, WHITE);
            DrawTextEx(font, "Press any key to play again :)", {10, 260 }, 28, 3, white);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}