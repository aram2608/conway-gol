#include "grid.hpp"

/*
 * Constructor for our Grid object
 * We pass in the width and height of the screen as well as our predefined cell
 * size We then use a list initialization to initalize the number of rows and
 * columns as well as the cell_size and grid of cells
 */
Grid::Grid(int width, int height, int cell_size)
    // We calculate the total rows and cols by dividing the height and width by
    // cell_size
    : rows(height / cell_size), cols(width / cell_size), cell_size(cell_size),
      /*
       * The rows parameter gives us the number of vectors
       * The cols parameter gives us the number of values, that are all
       * initialized to 0
       */
      cells(rows, std::vector<int>(cols, 0)) {}

// Function to draw each cell in the grid
void Grid::draw() {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            /*
             * We test if the specific cell has the value 1 and if so, we
             * assign the color green. Otherwise we assign grey.
             *
             * The ternary operator is a conditional operater
             * for writing one liner if-else statements,
             * we evaluate cells[r][c] and if truthy we assign
             * the left expression and if falsy we assign the right expression.
             *
             * In C++, 1 is considered a truthy value and 0 is considered falsy,
             * we could have made a vector of vectors of booleans which would
             * have been more memory efficient but numbers are easier to modify
             */
            Color color =
                cells[r][c] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            // We use the x and y coordinate of the cells top left corner
            // and its width and height are the preset cell size
            // we calculate the coordinates by multiplying the columns position by
            // the cell size
            DrawRectangle(c * cell_size, r * cell_size, cell_size, cell_size,
                          color);
        }
    }
}
