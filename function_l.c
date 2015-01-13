#include "ft_ls.h"

void    space_size_num(int size, int space_size)
{
	int     i;
	int     j;

	i = 0;
	j = 0;
	if (size == 0)
		size = 1;
	while (size)
	{
		size /= 10;
		i++;
	}
	while (j != space_size - i)
	{
		ft_putstr(" ");
		j++;
	}
}

void    space_link_num(int link, int space_link)
{
	int     i;
	int     j;

	i = 0;
	j = 0;
	if (link == 0)
		link = 1;
	while (link)
	{
		link /= 10;
		i++;
	}
	while (j != space_link - i)
	{
		ft_putstr(" ");
		j++;
	}
}

void    print(t_info *list, int space_link, int space_size)
{
	ft_printf("%s  ", list->permissions);
	space_link_num(list->link, space_link);
	ft_printf("%d ", list->link);
	ft_printf("%s  ", list->domaine);
	ft_printf("%s  ", list->group);
	space_size_num(list->size, space_size);
	ft_printf("%d ", list->size);
	if ((list->time_s - list->time_modif) > 15811200)
		ft_printf("%s ",ft_strsub(list->file_time, 20, 23));
	else
		ft_printf("%s ",ft_strsub(list->file_time, 4, 12));
	ft_printf("%s\n", list->file_name);
}

void    function_l(t_info **nf, char *av, int space_link, int space_size)
{
	t_info  *list;

	list = *nf;
	ft_printf("total %d\n", list->size_to);
	while (list)
	{
		if (!(ft_strchr(av, 'a')))
		{
			if (!(list->file_name[0] == '.'))
				print(list, space_link, space_size);
		}
		else
			print(list, space_link, space_size);
		list = list->next;
	}
}
