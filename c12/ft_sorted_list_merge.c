#include "ft_list.h"

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
    t_list *merged;
    t_list *current;

    if (begin_list1 == NULL)
        return;
    if (*begin_list1 == NULL)
    {
        *begin_list1 = begin_list2;
        return;
    }
    if (begin_list2 == NULL)
        return;

    if (cmp((*begin_list1)->data, begin_list2->data) <= 0)
    {
        merged = *begin_list1;
        (*begin_list1) = (*begin_list1)->next;
    }
    else
    {
        merged = begin_list2;
        begin_list2 = begin_list2->next;
    }
    current = merged;

    while (*begin_list1 != NULL && begin_list2 != NULL)
    {
        if (cmp((*begin_list1)->data, begin_list2->data) <= 0)
        {
            current->next = *begin_list1;
            *begin_list1 = (*begin_list1)->next;
        }
        else
        {
            current->next = begin_list2;
            begin_list2 = begin_list2->next;
        }
        current = current->next;
    }

    if (*begin_list1 != NULL)
        current->next = *begin_list1;
    else
        current->next = begin_list2;

    *begin_list1 = merged;
}
