#include <stdlib.h>

char *ft_strdup(char *src)
{
    char *dest;
    int i = 0;
    
    // Calculate the length of the source string
    while (src[i])
        i++;
    
    // Allocate memory for the new string (+1 for null terminator)
    dest = (char *)malloc(sizeof(char) * (i + 1));
    if (dest == NULL)
        return NULL;
    
    // Copy the string
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    
    return dest;
}
