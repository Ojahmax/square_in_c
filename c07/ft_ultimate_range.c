#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int size;
    int i;
    
    // Handle invalid case where min >= max
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }
    
    // Calculate the size needed
    size = max - min;
    
    // Allocate memory for the range
    *range = (int *)malloc(sizeof(int) * size);
    if (*range == NULL)
        return -1;
    
    // Fill the array with values from min to max-1
    i = 0;
    while (i < size)
    {
        (*range)[i] = min + i;
        i++;
    }
    
    return size;
}
/*
int *arr;
int size = ft_ultimate_range(&arr, 5, 10);
// arr will point to [5, 6, 7, 8, 9]
// size will be 5
 */
