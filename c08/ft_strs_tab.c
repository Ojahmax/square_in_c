#include "ft_stock_str.h"
#include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *dest = malloc(len + 1);
    if (!dest)
        return NULL;
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    if (ac < 0 || !av)
        return NULL;
    
    t_stock_str *tab = malloc(sizeof(t_stock_str) * (ac + 1));
    if (!tab)
        return NULL;
    
    for (int i = 0; i < ac; i++)
    {
        tab[i].size = ft_strlen(av[i]);
        tab[i].str = av[i];
        tab[i].copy = ft_strdup(av[i]);
        if (!tab[i].copy)
        {
            while (i-- > 0)
                free(tab[i].copy);
            free(tab);
            return NULL;
        }
    }
    
    tab[ac].str = 0;
    return tab;
}
