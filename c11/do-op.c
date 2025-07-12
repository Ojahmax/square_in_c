#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void ft_putnbr(int nb)
{
    char c;
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

int main(int argc, char **argv)
{
    int a;
    int b;
    int (*op[5])(int, int) = {add, sub, mul, div, mod};
    char *ops = "+-*/%";
    int i;

    if (argc != 4)
        return (0);
    a = ft_atoi(argv[1]);
    b = ft_atoi(argv[3]);
    i = 0;
    while (i < 5)
    {
        if (argv[2][0] == ops[i] && argv[2][1] == '\0')
        {
            if (i == 3 && b == 0)
            {
                write(1, "Stop : division by zero\n", 24);
                return (0);
            }
            if (i == 4 && b == 0)
            {
                write(1, "Stop : modulo by zero\n", 22);
                return (0);
            }
            ft_putnbr(op[i](a, b));
            write(1, "\n", 1);
            return (0);
        }
        i++;
    }
    write(1, "0\n", 2);
    return (0);
}
