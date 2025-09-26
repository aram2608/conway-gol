#include "grid.hpp"

/*
 * Constructor for our Grid object
 * We pass in the width and height of the screen as well as our predefined cell
 * size We then use a list initialization to initalize the number of rows and
 * columns as well as the cell_size and grid of cells
 */
Grid::Grid(int width, int height, int cell_size)
    : rows(height / cell_size), cols(width / cell_size), cell_size(cell_size),
      // The rows parameter gives us the number of vectors
      // The cols parameter gives us the number of values, that are all
      // initialized to 0
      cells(rows, std::vector<int>(cols, 0)) {}