/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:50:50 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 02:02:17 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_swap_without(t_info *tmp, t_info *b_l)
{
    t_info  *list;

    list = b_l;
    tmp->file_name = list->next->file_name;
    tmp->file_time = list->next->file_time;
    tmp->group = list->next->group;
    tmp->domaine = list->next->domaine;
    tmp->permissions = list->next->permissions;
    tmp->size = list->next->size;
    tmp->link = list->next->link;
    list->next->file_name = list->file_name;
    list->next->file_time = list->file_time;
    list->next->group = list->group;
    list->next->domaine = list->domaine;
    list->next->permissions = list->permissions;
    list->next->size = list->size;
    list->next->link = list->link;
    list->file_name = tmp->file_name;
    list->file_time = tmp->file_time;
    list->group = tmp->group;
    list->domaine = tmp->domaine;
    list->permissions = tmp->permissions;
    list->size = tmp->size;
    list->link = tmp->link;
}

int     ft_list_size_without(t_info *begin_list)
{
    t_info      *list;
    int         nb_elem;

    list = begin_list;
    nb_elem = 0;
    while (list)
    {
        nb_elem++;
        list = list->next;
    }
    return (nb_elem);
}

void		ft_list_sort_without(t_info **begin_list, int (*cmp)())
{
	t_info	*list;
	t_info	*tmp;
    int     size;
    int     i;
    int     j;

    i = 0;
	list = *begin_list;
	if (!(tmp = (t_info*)malloc(sizeof(t_info))))
        exit (0);
	size = ft_list_size_without(*begin_list);
    while (i < size - 1)
	{
        j = i + 1;
        while (j < size)
        {
            if (cmp(list->file_name, list->next->file_name) > 0)
                ft_swap_without(tmp, list);
		    list = list->next;
            j++;
        }
        list = *begin_list;
        i++;
	}
}
