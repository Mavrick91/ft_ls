/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:19:04 by maducham          #+#    #+#             */
/*   Updated: 2014/11/16 00:06:58 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	without_arg(t_info *nf)
{
    void    *f;
    t_info  *tmp_nf;

    f = ft_strcmp;
    tmp_nf = nf;
    ft_list_sort_without(&tmp_nf, f);
	while (tmp_nf)
	{
		if (!(tmp_nf->file_name[0] == '.'))
		{
			ft_putstr(tmp_nf->file_name);
			ft_putstr("\n");
		}
		tmp_nf = tmp_nf->next;
	}
}
