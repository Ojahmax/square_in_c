#include <stdio.h>

char *ft_strupcase(char *str);

int main(void)
{
    char text1[] = "hello World!";
    char text2[] = "Already UPPERCASE";
    char text3[] = "";

    printf("%s\n", ft_strupcase(text1)); // Output: "HELLO WORLD!"
    printf("%s\n", ft_strupcase(text2)); // Output: "ALREADY UPPERCASE"
    printf("%s\n", ft_strupcase(text3)); // Output: ""
    return 0;
}

