#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
    int *result;
    int i;

    if (length <= 0)
        return (NULL);
    result = (int *)malloc(length * sizeof(int));
    if (result == NULL)
        return (NULL);
    i = 0;
    while (i < length)
    {
        result[i] = f(tab[i]);
        i++;
    }
    return (result);
}
