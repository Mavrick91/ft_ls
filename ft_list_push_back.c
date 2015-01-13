#include "ft_ls.h"

void		ft_list_push_back(t_info **b_l, char *date, char *name, char *grp)
{
    t_info *list;

    list = *b_l;
    if (list)
    {
        while (list->next != NULL)
            list = list->next;
        list->next = ft_create_elem(date, name, grp);
    }
    else
    {
        *b_l = ft_create_elem(date, name, grp);
    }
}
