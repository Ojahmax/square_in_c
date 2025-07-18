#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_number(int n)
{
    ft_putchar((n / 10) + '0');
    ft_putchar((n % 10) + '0');
}

void ft_print_comb2(void)
{
    int a;
    int b;

    a = 0;
    while (a <= 98)
    {
        b = a + 1;
        while (b <= 99)
        {
            ft_print_number(a);
            ft_putchar(' ');
            ft_print_number(b);
            if (!(a == 98 && b == 99))
            {
                ft_putchar(',');
                ft_putchar(' ');
            }
            b++;
        }
        a++;
    }
}

int main(void)
{
    ft_print_comb2();
    return 0;
}
