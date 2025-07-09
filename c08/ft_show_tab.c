#include "ft_stock_str.h"
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
}

void ft_show_tab(struct s_stock_str *par)
{
    if (!par)
        return;
    
    while (par->str)
    {
        ft_putstr(par->str);
        ft_putchar('\n');
        
        ft_putnbr(par->size);
        ft_putchar('\n');
        
        ft_putstr(par->copy);
        ft_putchar('\n');
        
        par++;
    }
}
