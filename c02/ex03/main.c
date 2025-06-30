#include <stdio.h>

int ft_str_is_numeric(char *str);

int main(void)
{
    printf("%d\n", ft_str_is_numeric("123456")); // Output: 1
    printf("%d\n", ft_str_is_numeric("42abc"));  // Output: 0
    printf("%d\n", ft_str_is_numeric(""));       // Output: 1
    return 0;
}

