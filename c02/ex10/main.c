#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
    char dest[10];
    char *src = "Hello, World!";
    unsigned int len;

    len = ft_strlcpy(dest, src, sizeof(dest));
    printf("Copied string: '%s'\n", dest); // Output: "Hello, Wo"
    printf("Length of src: %u\n", len);     // Output: 13 (length of "Hello, World!")

    return 0;
}

