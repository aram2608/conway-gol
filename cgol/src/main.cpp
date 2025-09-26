#include "simulation.hpp"
#include <iostream>
#include <raylib.h>

int main() {
    // Hard coded window values
    const int window_w = 750;
    const int window_h = 750;
    const int cell_size = 25;
    Color dark_grey = Color{29, 29, 29, 255};

    // Game window //
    InitWindow(window_w, window_h, "C++ - Game of Life");

    // Target FPS of 12
    SetTargetFPS(12);
    Simulation sim{window_w, window_h, cell_size};

    // Simulation loop. Runs will the window is not closed
    while (!WindowShouldClose()) {

        // Function to catch keyboard events
        sim.catch_keyboard();

        // We update the simulation prior to drawing
        sim.update();

        // Main logic for drawing to game window
        BeginDrawing();
        ClearBackground(dark_grey);
        sim.draw();
        EndDrawing();
    }
    // Close our game window
    CloseWindow();
    return 0;
}