#include <raylib.h>

int main() {
    // Hard coded window values
    const int window_w = 750;
    const int window_h = 750;
    Color dark_green = Color{20, 160, 133, 255};

    // Game window //
    // INITIALIZE FIRST BEFORE LOADING GPU RESOURCES //
    InitWindow(window_w, window_h, "C++ - Game of Life");

    // Target FPS of 12
    SetTargetFPS(12);

    // Simulation loop. Runs will the window is not closed
    while (!WindowShouldClose()) {

        // Main logic for drawing to game window
        BeginDrawing();
        ClearBackground(dark_green);

        EndDrawing();
    }
    // Close our game window
    CloseWindow();
    return 0;
}