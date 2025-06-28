#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_numbers(void)
{
    char digit = '0';
    while (digit <= '9')
    {
        ft_putchar(digit);
        digit++;
    }
}

int main(void)
{
    ft_print_numbers();
    return 0;
}
