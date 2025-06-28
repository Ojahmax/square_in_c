#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}
/*
#include <stdio.h>

void ft_putstr(char *str);

int main(void)
{
    ft_putstr("Hello world!\n");  // Should print: Hello, world!
    return 0;
}
*/
