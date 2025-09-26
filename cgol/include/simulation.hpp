#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "grid.hpp"
#include <raylib.h>
#include <utility>
#include <vector>

class Simulation {
  public:
    Simulation(int width, int height, int cell_size);
    void draw();
    void set_cell_value(int r, int c, int value);
    int count_neighbors(int r, int c);

  private:
    Grid grid;
};

#endif