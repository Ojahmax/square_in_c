#ifndef SOLVE_H
#define SOLVE_H

int solve_grid(int grid[4][4], int constraints[16]);
int try_place(int grid[4][4], int pos, int constraints[16]);
int check_valid(int grid[4][4], int row, int col, int height, int constraints[16]);

#endif
