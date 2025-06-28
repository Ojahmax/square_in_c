int ft_strlen(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
/*
#include <stdio.h>

int ft_strlen(char *str);

int main(void)
{
    char *text = "42 is awesome!";
    printf("Length: %d\n", ft_strlen(text));  // Should print: Length: 14
    return 0;
}
*/
