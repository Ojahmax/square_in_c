#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list *current;
    unsigned int i;

    current = begin_list;
    i = 0;
    while (current != NULL)
    {
        if (i == nbr)
            return (current);
        current = current->next;
        i++;
    }
    return (NULL);
}
