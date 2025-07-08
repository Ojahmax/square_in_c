#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *range;
    int i;
    int size;

    // Handle invalid cases where min >= max
    if (min >= max)
        return NULL;

    // Calculate the size needed (max - min)
    size = max - min;

    // Allocate memory for the range
    range = (int *)malloc(sizeof(int) * size);
    if (range == NULL)
        return NULL;

    // Fill the array with values from min to max-1
    i = 0;
    while (i < size)
    {
        range[i] = min + i;
        i++;
    }

    return range;
}
