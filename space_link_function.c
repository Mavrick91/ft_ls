#include "ft_ls.h"

void    space_size_function(t_info **b_l, int *space_size, int f_a)
{
    int     i;
    t_info  *list;

    i = 0;
    list = *b_l;
    *space_size = 0;
    while (list)
    {
        if ((f_a == 1) || (list->file_name[0] != '.'))
        {
            if (list->size > *space_size)
                *space_size = list->size; 
        }
        list = list->next;
    }
    while (*space_size != 0)
    {
        *space_size /= 10;
        i++;
    }
    *space_size = i;
}

void    space_link_function(t_info **b_l, int *space_link, int *space_size ,int f_a)
{
    int     i;
    t_info  *list;

    i = 0;
    list = *b_l;
    *space_link = 0;
    while (list)
    {
        if ((f_a == 1) || (list->file_name[0] != '.'))
        {
            if (list->link > *space_link)
                *space_link = list->link;
        }
        list = list->next;
    }
    while (*space_link != 0)
    {
        *space_link /= 10;
        i++;
    }
    *space_link = i;
    space_size_function(b_l, space_size, f_a);
}
