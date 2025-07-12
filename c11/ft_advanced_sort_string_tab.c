void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
    int i;
    int j;
    char *temp;

    if (!tab || !*tab || !cmp)
        return;

    i = 0;
    while (tab[i + 1] != NULL)
    {
        j = 0;
        while (tab[j + 1] != NULL)
        {
            if (cmp(tab[j], tab[j + 1]) > 0)
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
