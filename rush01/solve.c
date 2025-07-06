#include "solve.h"

// Checks if number can be placed at position
int check_valid(int grid[4][4], int row, int col, int height, int constraints[16])
{
    int i = -1;
    // Check row and column for duplicates
    while (++i < 4)
        if (grid[row][i] == height || grid[i][col] == height)
            return (0);
    return (1);
}

// Recursive backtracking function
int try_place(int grid[4][4], int pos, int constraints[16])
{
    int row = pos / 4;  // Convert position to row
    int col = pos % 4;  // Convert position to column
    int height = 0;

    // Base case: grid filled
    if (pos == 16)
        return (print_grid(grid), 1);
    
    // Skip already filled cells
    if (grid[row][col] != 0)
        return (try_place(grid, pos + 1, constraints));
    
    // Try numbers 1-4
    while (++height <= 4)
    {
        if (check_valid(grid, row, col, height, constraints))
        {
            grid[row][col] = height; // Place number
            // Recursively try next position
            if (try_place(grid, pos + 1, constraints))
                return (1);
            grid[row][col] = 0; // Backtrack
        }
    }
    return (0); // No valid number found
}

// Starts the solving process
int solve_grid(int grid[4][4], int constraints[16])
{
    return (try_place(grid, 0, constraints));
}
