#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem(void *data);

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new_elem;

    new_elem = ft_create_elem(data);
    if (new_elem == NULL)
        return;
    if (*begin_list == NULL)
        *begin_list = new_elem;
    else
    {
        new_elem->next = *begin_list;
        *begin_list = new_elem;
    }
}
