void ft_ultimate_div_mod(int *a, int *b)
{
    if (*b != 0)
    {
        int temp = *a;
        *a = temp / *b;
        *b = temp % *b;
    }
}
/*
#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
    int x = 20;
    int y = 6;

    ft_ultimate_div_mod(&x, &y);

    printf("Division result in x: %d\n", x); // Should print 3
    printf("Remainder in y: %d\n", y);      // Should print 2

    return 0;
}
*/
