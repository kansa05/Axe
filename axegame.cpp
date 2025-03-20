#include "raylib.h"

int main()
{
    int width{450};
    int height{350};
    InitWindow(width,height,"Axe Game");

    int circlex{225};
    int circley{175};

    SetTargetFPS(60); //sets time for how fast it upgrades
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(PINK);


        DrawCircle(circlex,circley,25, BLUE);

        if (IsKeyDown(KEY_RIGHT)&& circlex<450)
        {
            circlex=circlex+5;
        }

        if (IsKeyDown(KEY_LEFT)&& circlex>0)
        {
            circlex=circlex-5;
        }

        EndDrawing();
    }


}