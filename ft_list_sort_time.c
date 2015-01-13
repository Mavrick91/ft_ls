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


void    ft_swap_time(t_info *tmp, t_info *b_l)
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

int     ft_list_size_time(t_info *begin_list)
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

int        ft_month(char *m1)
{
    if (m1[0] == 'j' && m1[2] == 'n')
        return (1);
    if (m1[0] == 'F' && m1[2] == 'b')
        return (2);
    if (m1[0] == 'M' && m1[2] == 'r')
        return (3);
    if (m1[0] == 'A' && m1[2] == 'r')
        return (4);
    if (m1[0] == 'M' && m1[2] == 'y')
        return (5);
    if (m1[0] == 'J' && m1[2] == 'n')
        return (6);
    if (m1[0] == 'J' && m1[2] == 'l')
        return (7);
    if (m1[0] == 'A' && m1[2] == 'g')
        return (8);
    if (m1[0] == 'S' && m1[2] == 'p')
        return (9);
    if (m1[0] == 'O' && m1[2] == 't')
        return (10);
    if (m1[0] == 'N' && m1[2] == 'v')
        return (11);
    if (m1[0] == 'D' && m1[2] == 'c')
        return (12);
}

char    *ft_day(char *time)
{
    char    *str;

    str = ft_strsub(time, 4, ft_strlen(time));
    return (str);
}

int        cmp_time(char *time, char *time_next)
{
    int     month;
    int     month_next;
    char    *day;
    char    *day_next;

    month = ft_month(time);
    month_next = ft_month(time_next);
    day = ft_day(time);
    day_next= ft_day(time_next);
    if (month < month_next)
        return (1);
    else if (month == month_next)
        if (ft_strcmp(day, day_next) < 0)
            return (1);
    return (0);
}

void		ft_list_sort_time(t_info ***begin_list, int (*cmp)(), int f_t)
{
    t_info	*list;
    t_info	*tmp;
    int     size;
    int     i;
    int     j;

    i = 0;
    list = **begin_list;
    tmp = (t_info*)malloc(sizeof(t_info));
    size = ft_list_size_time(**begin_list);
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if ((f_t == 1) || (list->file_name[0] != '.'))
                if (cmp_time(list->file_time, list->next->file_time))
                    ft_swap_time(tmp, list);
            list = list->next;
            j++;
        }
        list = **begin_list;
        i++;
    }
}
