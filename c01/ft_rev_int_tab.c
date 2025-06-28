void ft_rev_int_tab(int *tab, int size)
{
    int i = 0;
    int temp;

    while (i < size / 2)
    {
        temp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = temp;
        i++;
    }
}
/*
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    ft_rev_int_tab(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);  // Should print: 5 4 3 2 1

    return 0;
}
*/
