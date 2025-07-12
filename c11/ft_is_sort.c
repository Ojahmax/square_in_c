int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    int direction;

    if (length <= 1)
        return (1);
    direction = f(tab[0], tab[1]);
    i = 1;
    while (i < length - 1)
    {
        if (direction == 0)
            direction = f(tab[i], tab[i + 1]);
        else
        {
            int cmp = f(tab[i], tab[i + 1]);
            if (direction > 0 && cmp < 0)
                return (0);
            if (direction < 0 && cmp > 0)
                return (0);
        }
        i++;
    }
    return (1);
}
