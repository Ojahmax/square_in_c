#include <stdio.h>

char *ft_strlowcase(char *str);

int main(void)
{
    char text1[] = "HELLO World!";
    char text2[] = "already lowercase";
    char text3[] = "";

    printf("%s\n", ft_strlowcase(text1)); // Output: "hello world!"
    printf("%s\n", ft_strlowcase(text2)); // Output: "already lowercase"
    printf("%s\n", ft_strlowcase(text3)); // Output: ""
    return 0;
}

