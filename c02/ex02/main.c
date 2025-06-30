#include <stdio.h>

int ft_str_is_alpha(char *str);

int main(void)
{
    printf("%d\n", ft_str_is_alpha("Hello"));    // Output: 1
    printf("%d\n", ft_str_is_alpha("Hello123")); // Output: 0
    printf("%d\n", ft_str_is_alpha(""));         // Output: 1
    return 0;
}

