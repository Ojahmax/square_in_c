#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
    char src[] = "Hello";
    char dest[10];

    ft_strncpy(dest, src, 10);

    printf("Copied string: '%s'\n", dest); // Output will be "Hello" followed by nulls
    return 0;
}

