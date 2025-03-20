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
//axe edges
    int l_axex{axex};
    int r_axex{axex+axelength};
    int u_axey{axey};
    int b_axey{axey+axelength};

    int directionY{10};
    int directionX{7}

    bool collisionWithAxe = 
                            (b_axey>=u_circley) &&
                            (u_axey<=b_circley) && 
                            (r_axex >= l_circlex) && 
                            (l_axex<=r_circlex);

    SetTargetFPS(60); //sets time for how fast it upgrades
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(PINK);

        if (collisionWithAxe)
        {
            DrawText("GAME OVER!",400,200,50,RED);
        }
        else
        {
            //update the edges
            l_circlex=circlex-circleRadius;
            r_circlex=circlex+circleRadius;
            u_circley=circley-circleRadius;
            b_circley=circley-circleRadius;

            l_axex=axex;
            r_axex=axex +axelength;
            u_axey=axey;
            b_axey=axey+axelength;

            collisionWithAxe = 
                            (b_axey>=u_circley) &&
                            (u_axey<=b_circley) && 
                            (r_axex >= l_circlex) && 
                            (l_axex<=r_circlex);

            DrawCircle(circlex,circley,circleRadius, BLUE);
            DrawRectangle(axex,axey,axelength,axelength,WHITE);
    
            axey += directionY;
            if (axey > height - axelength || axey < 0)
            {
                directionY = -directionY;  
            }

            axex += directionX;
            if (axex > width - axelength || axex < 0)
            {
                directionX = -directionX;  

    
            if (IsKeyDown(KEY_RIGHT)&& circlex<width)
            {
                circlex=circlex+5;
            }
    
            if (IsKeyDown(KEY_LEFT)&& circlex>0)
            {
                circlex=circlex-5;
            }
        }




        EndDrawing();
    }


}