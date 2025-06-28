void ft_sort_int_tab(int *tab, int size)
{
    int i, temp;
    int sorted = 0;

    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                sorted = 0;
            }
            i++;
        }
    }
}
/*
#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main(void)
{
    int arr[] = {9, 3, 1, 5, 4};
    int size = 5;

    ft_sort_int_tab(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);  // Should print: 1 3 4 5 9

    return 0;
}
*/
