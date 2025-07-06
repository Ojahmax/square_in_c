#include <unistd.h>
#include "print.h"

// Prints "Error\n"
void print_error(void)
{
    write(1, "Error\n", 6);
}

// Prints the solved grid
void print_grid(int grid[4][4])
{
    int i = -1;
    int j;
    char c;

    while (++i < 4) // For each row
    {
        j = -1;
        while (++j < 4) // For each column
        {
            c = grid[i][j] + '0'; // Convert to char
            write(1, &c, 1);      // Print digit
            if (j != 3)
                write(1, " ", 1); // Print space between numbers
        }
        write(1, "\n", 1); // Newline after each row
    }
}
