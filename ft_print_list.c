#include "ft_ls.h"

void    ft_print_list(t_info *e)
{
    t_info  *list;

    list = e;
    while (list)
    {
        printf("file name = %s\n", list->file_name);
        list = list->next;
    }
    printf("\n\n\n\n");
}
