void ft_div_mod(int a, int b, int *div, int *mod)
{
    if (b != 0)
    {
        *div = a / b;
        *mod = a % b;
    }
}
/*
#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
    int a = 17;
    int b = 5;
    int div, mod;

    ft_div_mod(a, b, &div, &mod);

    printf("Division: %d\n", div); // Should print 3
    printf("Modulus: %d\n", mod);  // Should print 2

    return 0;
}
*/
