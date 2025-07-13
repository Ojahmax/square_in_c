#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int count = 0;
    t_list *current = begin_list;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
