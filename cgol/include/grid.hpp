#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid {
  public:
    // Constructor for Grid object, we pass in predefined window sizes and cell
    // size
    Grid(int width, int height, int cell_size);

  private:
    // Integer representation for the number of rows
    int rows;
    // Integer representation for the number of columns
    int cols;
    // Predefined cell size as an integer
    int cell_size;
    // A vector of vectors to store integers
    // this helps us represent alive and dead cells as int values
    std::vector<std::vector<int>> cells;
};

#endif