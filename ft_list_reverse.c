/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:43:49 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 01:51:05 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_list_reverse(t_info **begin_list)
{
    t_info *tmp_list;
    t_info *tmp;

    if (*begin_list == NULL || (*begin_list)->next == NULL)
        return ;
    tmp_list = *begin_list;
    tmp = tmp_list->next;
    ft_list_reverse(&tmp);
    tmp_list->next->next = tmp_list;
    tmp_list->next = NULL;
    *begin_list = tmp;
}
