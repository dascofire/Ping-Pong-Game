#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <iostream>

using namespace std;

double LastUpdateTime = 0;

bool EventTriggered(double Interval){
    double CurrentTime = GetTime();
    if (CurrentTime - LastUpdateTime >= Interval)
    {
        LastUpdateTime = CurrentTime;
        return true;
    }
    return false;
}

int main (){

    //STEP #1 : Create The Window Game
    Color DarkBlue = {44, 44, 127, 255}; // Declare The Color
    InitWindow(510, 620, "Tetris Game"); //Window Size
    SetTargetFPS(60); // This Function For Optimisation This Game In all Techs

    Font font = LoadFontEx("fonts/Super.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false) // this condition if open this window not close 
    {
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing(); // This Function For Begin Drawing The Object

        ClearBackground(DarkBlue); // Call it Here The Color

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
;
        if (game.GameOver)
        {
            DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60} , 0.3, 6, lightblue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font , scoreText, 38, 2); 

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180} , 0.3, 6, lightblue);
        game.Draw();

        EndDrawing(); // This Function For ending Drawing The Object 
    }
    

    CloseWindow(); // if closed The Window turn on this Function
}