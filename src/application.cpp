#include "application.h"
#include "raylib.h"
#include "stdio.h"
#include "ball.h"
#include <vector>

// Application::Application(char *title, int screenWidth, int screenHeight){
//     title = title;
//     screenWidth = screenWidth;
//     screenHeight = screenHeight;
// }

Application::Application(char *title, int screenWidth, int screenHeight)
    : title(title), screenWidth(screenWidth), screenHeight(screenHeight)
{
}

void Application::run()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Objects
    // Ball ballOne(
    //     {(float)GetRandomValue(1, GetScreenWidth()), (float)GetRandomValue(0, GetScreenWidth())},
    //     {2, 3},
    //     BLUE);
    // Ball ballTwo(
    //     {(float)GetRandomValue(1, GetScreenWidth()), (float)GetRandomValue(0, GetScreenWidth())},
    //     {1,2},
    //     RED);
    std::vector<Ball> balls;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        if(IsMouseButtonPressed(0)){
            balls.push_back(Ball(
                GetMousePosition(),
                {5.0, 5.0},
                RED 
            ));
            printf("accX: %f, accY: %f \n", balls[0].getAccX(), balls[0].getAccY());
            printf("Mouse clicked \n");
            printf("No. of balls: %lld \n", balls.size());
        }
        for(Ball& ball : balls){
            ball.update(screenWidth, screenHeight);
            printf("%f \n", ball.getX());
        }
        //----------------------------------------------------------------------------------
        // ballOne.update(screenWidth, screenHeight);
        // ballTwo.update(screenWidth, screenHeight);

        // ballTwo.update(screenWidth, screenHeight);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for(Ball& ball : balls){
                ball.draw();
            }
            DrawText(TextFormat("FPS: %d ", GetFPS()), 0, 0, 20, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

Application::~Application()
{
}