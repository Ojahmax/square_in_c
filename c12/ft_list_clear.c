#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *current;
    t_list *next;

    current = begin_list;
    while (current != NULL)
    {
        next = current->next;
        if (free_fct != NULL)
            free_fct(current->data);
        free(current);
        current = next;
    }
}
