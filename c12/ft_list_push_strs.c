#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem(void *data);

t_list *ft_list_push_strs(int size, char **strs)
{
    t_list *list;
    t_list *elem;
    int i;

    list = NULL;
    i = 0;
    while (i < size)
    {
        elem = ft_create_elem(strs[i]);
        if (elem == NULL)
            return (NULL);
        elem->next = list;
        list = elem;
        i++;
    }
    return (list);
}
