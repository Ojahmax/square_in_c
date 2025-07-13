#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
    t_list *current;

    if (begin_list == NULL)
        return NULL;
    current = begin_list;
    while (current->next != NULL)
        current = current->next;
    return current;
}
