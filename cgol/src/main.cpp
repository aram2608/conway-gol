#include "grid.hpp"
#include <raylib.h>

int main() {
    // Hard coded window values
    const int window_w = 750;
    const int window_h = 750;
    const int cell_size = 25;
    Color dark_grey = Color{29, 29, 29, 255};

    // Game window //
    // INITIALIZE FIRST BEFORE LOADING GPU RESOURCES //
    InitWindow(window_w, window_h, "C++ - Game of Life");

    // Target FPS of 12
    SetTargetFPS(12);

    Grid grid{window_w, window_h, cell_size};
    grid.set_value(0, 0, 1);

    // Simulation loop. Runs will the window is not closed
    while (!WindowShouldClose()) {

        // Main logic for drawing to game window
        BeginDrawing();
        ClearBackground(dark_grey);

        grid.draw();

        EndDrawing();
    }
    // Close our game window
    CloseWindow();
    return 0;
}