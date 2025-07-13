#include "ft_list.h"

void ft_list_reverse_fun(t_list *begin_list)
{
    t_list *start;
    t_list *end;
    void *temp;

    if (begin_list == NULL)
        return;

    start = begin_list;
    end = begin_list;
    while (end->next != NULL)
        end = end->next;

    while (start != end && start->next != end)
    {
        temp = start->data;
        start->data = end->data;
        end->data = temp;
        start = start->next;
        end = begin_list;
        while (end->next != start)
            end = end->next;
    }
}
