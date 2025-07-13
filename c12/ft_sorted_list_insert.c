#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem(void *data);

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list *new_elem;
    t_list *current;
    t_list *previous;

    new_elem = ft_create_elem(data);
    if (new_elem == NULL)
        return;

    if (*begin_list == NULL || cmp(data, (*begin_list)->data) <= 0)
    {
        new_elem->next = *begin_list;
        *begin_list = new_elem;
        return;
    }

    previous = *begin_list;
    current = (*begin_list)->next;
    while (current != NULL && cmp(data, current->data) > 0)
    {
        previous = current;
        current = current->next;
    }
    previous->next = new_elem;
    new_elem->next = current;
}
