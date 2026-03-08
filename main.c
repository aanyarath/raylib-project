#include <stdio.h>
#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "test");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}