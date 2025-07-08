int ft_sqrt(int nb)
{
    int sqrt;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    sqrt = 1;
    while (sqrt * sqrt <= nb)
    {
        if (sqrt * sqrt == nb)
            return (sqrt);
        sqrt++;
    }
    return (0);
}
