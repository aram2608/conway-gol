#include "simulation.hpp"

Simulation::Simulation(int width, int height, int cell_size)
    : grid(width, height, cell_size), tmp_grid(width, height, cell_size) {
    run = SimulationState::OFF;
    grid.fill_rand();
}

void Simulation::draw() { grid.draw(); }

void Simulation::set_cell_value(int r, int c, int value) {
    grid.set_value(r, c, value);
}

int Simulation::count_neighbors(int r, int c) {
    // An int value to keep track of neighbors
    int live_neighbors = 0;
    // We make a vector of pairs to represent the cells around the cell of
    // interest
    std::vector<std::pair<int, int>> n_offset = {
        {-1, 0},  // Above
        {1, 0},   // Below
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Upper left
        {-1, 1},  // Upper right
        {1, -1},  // Lower left
        {1, 1}    // Lower right
    };
    // We iterate over each offset
    for (const auto &offset : n_offset) {
        // We use modulo arithmetic to create  a toroidal array, meaning the
        // right most edge wraps around and "touches" the leftmost edge so a
        // cell at [5][29] has a neighbor at [5][0]
        int neighbor_row =
            (r + offset.first + grid.get_rows()) % grid.get_rows();
        int neighbor_col =
            (c + offset.second + grid.get_cols()) % grid.get_cols();
        // We return the value of at the neighbors location and directly add it
        // to the live neighbor count
        live_neighbors += grid.get_value(neighbor_row, neighbor_col);
    }
    return live_neighbors;
}

void Simulation::update() {
    // We only run if the state is on
    if (is_running()) {
        for (int r = 0; r < grid.get_rows(); ++r) {
            for (int c = 0; c < grid.get_cols(); ++c) {
                int live_neighbors = count_neighbors(r, c);
                int cell_value = grid.get_value(r, c);

                // If the cell is alive
                if (cell_value == 1) {
                    // We test if it has more than 3 neighbors or less than 2
                    if (live_neighbors > 3 || live_neighbors < 2) {
                        // And kill it
                        tmp_grid.set_value(r, c, 0);
                    } else {
                        // Otherwise we leave it alive
                        // We need this else statement since the tmp grid has no
                        // values
                        tmp_grid.set_value(r, c, 1);
                    }
                }
                // Otherwise we assume the cell is dead
                else {
                    // If it has 3 neighbors we bring it to life
                    if (live_neighbors == 3) {
                        tmp_grid.set_value(r, c, 1);
                        // Otherwise it stays dead
                    } else {
                        tmp_grid.set_value(r, c, 0);
                    }
                }
            }
        }
        // Now we can copy the values from our temporary grid into the original
        // This is wicked inefficient but its easy to implement
        grid = tmp_grid;
    }
}

// We return the simulation's state
bool Simulation::is_running() { return run == SimulationState::ON; }

void Simulation::start() { run = SimulationState::ON; }

void Simulation::stop() { run = SimulationState::OFF; }

void Simulation::catch_keyboard() {
    if(IsKeyPressed(KEY_ENTER)) run = SimulationState::ON;
    if(IsKeyPressed(KEY_SPACE)) run = SimulationState::OFF;
}
