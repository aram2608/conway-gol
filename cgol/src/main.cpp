#include <iostream>
#include <raylib.h>

int main() {
    // Hard coded window values w/offest
    int off_set = 50;
    int window_w = 750;
    int window_h = 700;

    // Game window Audio Device //
    // INITIALIZE FIRST BEFORE LOADING GPU RESOURCES //
    InitWindow(window_w + off_set, window_h + (2 * off_set),
               "C++ - Game of Life");

    // Target FPS of 60
    SetTargetFPS(60);

    // Game loop. Runs will the window is not closed
    while (!WindowShouldClose()) {

        // Main logic for drawing to game window
        BeginDrawing();

        EndDrawing();
    }
    // Close our game window
    CloseWindow();
    CloseAudioDevice();
    return 0;
}