#include "raylib.h"

int main()
{
    int width{900};
    int height{550};
    InitWindow(width,height,"Axe Game");

    int circlex{200};
    int circley{200};

    int circleRadius(25);
// circle edges
    int l_circlex{circlex-circleRadius};
    int r_circlex{circlex+circleRadius};
    int u_circley{circley-circleRadius};
    int b_circley{circley+circleRadius};

    int axex{400};
    int axey{0};
    int axelength{50};
//axe adges
    int l_axex{axex};
    int r_axex{axex+axelength};
    int u_axey{axey};
    int b_axey{axey+axelength};

    int direction{5};

    SetTargetFPS(60); //sets time for how fast it upgrades
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(PINK);


        DrawCircle(circlex,circley,circleRadius, BLUE);
        DrawRectangle(axex,axey,axelength,axelength,WHITE);

        axey+=direction;
        if(axey>height|| axey<0)
        {
            direction = -direction;

        }

        if (IsKeyDown(KEY_RIGHT)&& circlex<width)
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