/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_many_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 22:34:02 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 01:52:02 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		verif_many_param(int ac, char **sr)
{
	int		i;

	i = 1;
	while (i != ac)
	{
		if (sr[i][0] != '-')
			return (0);
		i++;
	}
	return (1);
}
