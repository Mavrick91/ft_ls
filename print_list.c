#include "ft_ls.h"

void    print_list(t_info **nf, char *av)
{
    t_info  *list;
    int     f_list;

    list = *nf;
    f_list = 0;
    if (ft_strchr(av, 'a'))
        f_list = 1;
    if (!(ft_strchr(av, 'l')))
    {
        while (list)
        {
            if ((f_list == 1) || (list->file_name[0] != '.'))
                ft_printf("%s\n", list->file_name);
            list = list->next;
        }
    }
}
