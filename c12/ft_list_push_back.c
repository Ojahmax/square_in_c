#include "ft_list.h"
#include <stdlib.h>

t_list *ft_create_elem(void *data);

void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *new_elem;
    t_list *current;

    new_elem = ft_create_elem(data);
    if (new_elem == NULL)
        return;
    if (*begin_list == NULL)
    {
        *begin_list = new_elem;
        return;
    }
    current = *begin_list;
    while (current->next != NULL)
        current = current->next;
    current->next = new_elem;
}
