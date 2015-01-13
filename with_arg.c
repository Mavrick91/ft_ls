/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:31:59 by maducham          #+#    #+#             */
/*   Updated: 2015/01/08 18:25:45 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
 *void    ft_size_to(t_info **nf, int f_a)
 *{
 *    t_info *list;
 *    int     somme;
 *
 *    somme = 0;
 *    list = *nf;
 *    while (list)
 *    {
 *        if (f_a == 1 || list->file_name[0] != '.') 
 *            somme += statbuf.st_blocks;
 *        list = list->next;
 *    }
 *    list = *nf;
 *    list->size_to = somme;
 *    calcul_time(nf, list->file_time);
 *}
 */

void	with_arg(t_info **nf, char *av)
{
	void    *f;
	int     space_link;
	int     space_size;
	int     f_a;

	f_a = 0;
	if (ft_strchr(av, 'a'))
		f_a = 1;
	f = ft_strcmp;
	ft_list_sort(nf, f);
	space_link_function(nf, &space_link, &space_size, f_a);
	if (av[0] == '-' && (true_false(av)))
	{
		if (ft_strchr(av, 't'))
			function_t(nf, av);
		if (ft_strchr(av, 'r'))
			function_r(nf, av);
		if (ft_strchr(av, 'l'))
			function_l(nf, av, space_link, space_size);
		print_list(nf, av);
	}
}
