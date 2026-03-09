#include <stdio.h>
#include "raylib.h"

int main(void)
{
   
    int screenWidth = 800; // Set the window dimensions
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "balls"); // Initialize the window

    int playerposx = 400; // Initialize the player's position at the center of the screen
    int playerposy = 150;
    int bulletposx=0; // Initialize the bullet's position and speed
    int bulletposy=0;
    int bulletspeed=10; 

    int movementSpeed = 5; // Set the movement speed of the player

    while(!WindowShouldClose())
    {
        
        if (IsKeyPressed(KEY_W)) // Check if the W key is pressed
        {
            playerposy-=movementSpeed;
            printf("forward\n");
        }
        if (IsKeyPressed(KEY_S)) // Check if the S key is pressed
        {
            printf("backward\n");
            playerposy+=movementSpeed;
                    
        }
        if (IsKeyPressed(KEY_A)) // Check if the A key is pressed
        {
            printf("left\n");
            playerposx-=movementSpeed;       
        }
        if (IsKeyPressed(KEY_D)) // Check if the D key is pressed
        {
            printf("right\n");
            playerposx+=movementSpeed;
        }
        if (IsKeyPressed(KEY_SPACE)) // Check if the ESC key is pressed
        {
            DrawCircleV((Vector2){bulletposx, bulletposy}, 5, RED); // Draw the bullet as a red circle
            bulletposx=playerposx;
            bulletposy=playerposy;
            while (bulletposx<screenWidth && bulletposy<screenHeight && bulletposx>0 && bulletposy>0) // Move the bullet until it goes off-screen
            {
                bulletposx+=bulletspeed;
                bulletposy+=bulletspeed;
                BeginDrawing(); 
                ClearBackground(RAYWHITE);
                DrawCircleV((Vector2){playerposx, playerposy}, 10, BLUE); // Draw the player as a blue circle
                DrawCircleV((Vector2){bulletposx, bulletposy}, 5, RED); // Draw the bullet as a red circle
                EndDrawing();
            }
            printf("shoot\n");

        }
        BeginDrawing(); 
        ClearBackground(RAYWHITE);
        DrawCircleV((Vector2){playerposx, playerposy}, 10, BLUE); // Draw the player as a blue circle
        
        DrawText("Use WASD to move the ball", 100, 100, 20, DARKGRAY);
        EndDrawing();

    }
   
    CloseWindow();
    return 0;
}
