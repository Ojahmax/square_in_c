#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
    t_list *previous;
    t_list *current;
    t_list *next;

    previous = NULL;
    current = *begin_list;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin_list = previous;
}
