#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_is_negative(int n)
{
    if (n < 0)
        ft_putchar('N');
    else
        ft_putchar('P');
}

int main(void)
{
    ft_is_negative(-5);  // Output: N
    ft_is_negative(0);   // Output: P
    ft_is_negative(42);  // Output: P
    return 0;
}
