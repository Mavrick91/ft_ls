#include "ft_ls.h"

void    ft_list_add_1(t_info **b_l, char *domain, int size, int link)
{
    t_info  *list;
    char    buf[1024];
    int     len;

    len = 0;
    list = *b_l;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->domaine = domain;
        len = readlink(list->file_name, buf, 1023);
        if (len != -1)
            list->size = len;
        else
            list->size = size;
        list->link = link;
    }
}
