#include <stdio.h>

int ft_str_is_printable(char *str);

int main(void)
{
    printf("%d\n", ft_str_is_printable("Hello, World!")); // Output: 1
    printf("%d\n", ft_str_is_printable("Line\nBreak"));    // Output: 0 (contains \n = ASCII 10)
    printf("%d\n", ft_str_is_printable(""));               // Output: 1
    return 0;
}

