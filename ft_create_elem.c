/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 01:51:37 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 01:51:41 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info		*ft_create_elem(char *date, char *name, char *grp)
{
	t_info		*list;

    list = (t_info*)malloc(sizeof(t_info));
    if (list == NULL)
        return (NULL);
	if (list)
	{
		list->file_time = date;
		list->file_name = name;
		list->group = grp;
		list->next = NULL;
	}
	return (list);
}
