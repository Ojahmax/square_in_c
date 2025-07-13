#include "ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list *current;
    t_list *next_node;
    void *temp_data;
    int swapped;

    if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
        return;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        current = *begin_list;
        while (current->next != NULL)
        {
            next_node = current->next;
            if (cmp(current->data, next_node->data) > 0)
            {
                temp_data = current->data;
                current->data = next_node->data;
                next_node->data = temp_data;
                swapped = 1;
            }
            current = current->next;
        }
    }
}
