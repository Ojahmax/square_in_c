#include <unistd.h>
#include "parse.h"

int parse_input(int argc, char **argv, int *constraints)
{
    int i = 0;
    int count = 0;
    char *str = argv[1]; // Get input string

    // Check exactly 1 argument provided
    if (argc != 2)
        return (0);
    
    // Process each character
    while (str[i] && count < 16)
    {
        // If digit 1-4, store in constraints
        if (str[i] >= '1' && str[i] <= '4')
            constraints[count++] = str[i] - '0';
        // If not space, invalid
        else if (str[i] != ' ')
            return (0);
        i++;
    }
    // Must have exactly 16 numbers
    return (count == 16);
}
