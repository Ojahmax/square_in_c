#include <stdio.h>

int ft_str_is_uppercase(char *str);

int main(void)
{
    printf("%d\n", ft_str_is_uppercase("HELLO"));   // Output: 1
    printf("%d\n", ft_str_is_uppercase("Hello"));   // Output: 0
    printf("%d\n", ft_str_is_uppercase(""));        // Output: 1
    return 0;
}

