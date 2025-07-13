#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list *current;
    t_list *previous;
    t_list *next;

    if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
        return;

    current = *begin_list;
    previous = NULL;

    while (current != NULL)
    {
        next = current->next;
        if (cmp(current->data, data_ref) == 0)
        {
            if (previous == NULL)
                *begin_list = next;
            else
                previous->next = next;
            if (free_fct != NULL)
                free_fct(current->data);
            free(current);
        }
        else
        {
            previous = current;
        }
        current = next;
    }
}
