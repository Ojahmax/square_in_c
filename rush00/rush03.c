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
            if ((row == 1 && col == 1) || (row == 1 && col == x))
                ft_putchar('o');
            else if ((row == 1 && col > 1 && col < x) || (row == y && col > 1 && col < x))
                ft_putchar('-');
	    else if ((col == 1 && row > 1 && row != y) || (row != y && row > 1 && col == x))
                ft_putchar('|');
	    else if ((col == 1 && row == y) || (row == y && col == x))
		ft_putchar('o');
            else
                ft_putchar(' ');
            col++;
        }
        ft_putchar('\n');
        row++;
    }
}
	/*{
    if (x <= 0 || y <= 0)
        return;
    
    for (int row = 1; row <= y; row++)
    {
        for (int col = 1; col <= x; col++)
        {
            if ((row == 1 || row == y) && (col == 1 || col == x))
                ft_putchar('o');
            else if (row == 1 || row == y)
                ft_putchar('-');
            else if (col == 1 || col == x)
                ft_putchar('|');
            else
                ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}*/
