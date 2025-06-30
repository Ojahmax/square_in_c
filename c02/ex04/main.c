#include <stdio.h>

int ft_str_is_lowercase(char *str);

int main(void)
{
    printf("%d\n", ft_str_is_lowercase("hello"));   // Output: 1
    printf("%d\n", ft_str_is_lowercase("Hello"));   // Output: 0
    printf("%d\n", ft_str_is_lowercase(""));        // Output: 1
    return 0;
}

