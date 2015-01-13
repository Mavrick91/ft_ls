/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:40:48 by maducham          #+#    #+#             */
/*   Updated: 2015/01/05 19:54:09 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	s_o_d(void)
{
    ft_putstr("ls: illegal option -- -\n");
    ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
    ft_putstr(" [file ...]\n");
}

int		main(int ac, char **av)
{
    t_info	*nf;

	nf = NULL;
    readdirectory(&nf);
    if (ac == 1)
        without_arg(nf);
    else if (ac == 2)
    {
        if (verif_1_param(av[1]) == 0 || true_false(av[1]) == 0)
        {
            s_o_d();
            return (0);
        }
        with_arg(&nf, av[1]);
    }
    /*else if (ac > 1)
    {
        if ((verif_many_param(ac, av)) == 0
                || true_false(many_arg(ac, av)) == 0)
        {
            s_o_d();
            return (0);
        }
        with_arg(&nf, many_arg(ac, av));
    }*/
    return (0);
}
