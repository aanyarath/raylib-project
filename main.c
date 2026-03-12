#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
int spawnAlienX(void);

int main(void)
{
   
    int screenWidth = 800; // Set the window dimensions
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "balls"); // Initialize the window

    int playerposx = 400; // Initialize the player's position at the center of the screen
    int playerposy = 150;
    int movementSpeed = 10; // Set the movement speed of the player

    float bulletposx=0.0f; // Initialize the bullet's position and speed
    float bulletposy=0.0f;
    float bulletspeed=0.25f; 

    int alienposx = spawnAlienX(); // Initialize the alien's position
    int alienposy = 400;
    float alienSpeed = 0.25f; // Movement speed of the alien
    bool alienState = false; // State of the alien (true for alive, false for dead)

    int score=0; // Initialize the player's score

    
    
    while(!WindowShouldClose())
    {
        DrawText("Use WASD to move the ball", 50, 50, 20, BLUE);
        DrawText("Press SPACE to shoot", 50, 80, 20, BLUE);
        DrawText(TextFormat("Score: %d", score), 50, 110, 20, BLUE);
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
        if (IsKeyPressed(KEY_SPACE))
        {
            DrawCircleV((Vector2){bulletposx, bulletposy}, 5, RED); // Draw the bullet as a red circle
            bulletposx=playerposx;
            bulletposy=playerposy;
            while (bulletposx<screenWidth && bulletposy<screenHeight && bulletposx>0 && bulletposy>0) // Move the bullet until it goes off-screen
            {
                //bulletposx+=bulletspeed;
                bulletposy+=bulletspeed;
                BeginDrawing(); 
                ClearBackground(RAYWHITE);
                DrawCircleV((Vector2){bulletposx, bulletposy}, 5, RED); // Draw the bullet as a red circle
                DrawCircleV((Vector2){playerposx, playerposy}, 10, BLUE); // Draw the player as a blue circlE
                EndDrawing();
                if (CheckCollisionCircles((Vector2){bulletposx, bulletposy}, 5, (Vector2){alienposx, 400}, 10)) // Check for collision between the bullet and the alien
                {
                    alienState = false; // Set the alien's state to false (dead)
                    alienposx = spawnAlienX(); // Respawn the alien at a new random position
                    alienposy = 400; // Reset the alien's y position
                    BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawCircleV((Vector2){alienposx, alienposy}, 10, GREEN);
                    EndDrawing();
                    score++; // Increment the player's score
                    break; // Exit the bullet movement loop
                }
            }
            printf("shoot\n");

        }
        BeginDrawing(); 
        ClearBackground(RAYWHITE);
        DrawCircleV((Vector2){playerposx, playerposy}, 10, BLUE); // Draw the player as a blue circle
        DrawCircleV((Vector2){alienposx, alienposy}, 10, GREEN); // Draw the alien as a green circle
        EndDrawing();
        
    

    }

    CloseWindow();
    return 0;
}
//function to spawn the alien at a random position within a certain range on the screen
int spawnAlienX(void)
{
    return 200 + rand() % 400;
}


