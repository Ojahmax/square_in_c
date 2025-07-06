#include "parse.h"
#include "solve.h"
#include "print.h"

int main(int argc, char **argv)
{
    int constraints[16];  // Stores the 16 input constraints
    int grid[4][4] = {0}; // Initializes 4x4 grid with 0s

    // Step 1: Parse input
    if (!parse_input(argc, argv, constraints))
        return (print_error(), 0); // If invalid input, print error and exit
    
    // Step 2: Solve puzzle
    if (!solve_grid(grid, constraints))
        return (print_error(), 0); // If no solution, print error and exit
    
    return (0); // Success
}
