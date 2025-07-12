void ft_sort_string_tab(char **tab)
{
    int i;
    int j;
    char *temp;

    if (!tab || !*tab)
        return;

    i = 0;
    while (tab[i + 1] != NULL)
    {
        j = 0;
        while (tab[j + 1] != NULL)
        {
            if (ft_strcmp(tab[j], tab[j + 1]) > 0)
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

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
