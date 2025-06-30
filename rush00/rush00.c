void ft_putchar(char c);

void rush(int x, int y)
{
    int row = 1;
    int col;

    if (x <= 0 || y <= 0)
        return;

    while (row <= y)
    {
        col = 1;
        while (col <= x)
        {
            if ((row == 1 || row == y) && (col == 1 || col == x))
                ft_putchar('o');
            else if (row == 1 || row == y)
                ft_putchar('-');
            else if (col == 1 || col == x)
                ft_putchar('|');
            else
                ft_putchar(' ');
            col++;
        }
        ft_putchar('\n');
        row++;
    }
}
