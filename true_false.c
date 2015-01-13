/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_false.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 23:35:53 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 00:00:51 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		true_false(char *av)
{
	int		i;
	int		j;
	char	*faux;

	i = 1;
	faux = (char*)malloc(sizeof(char) * 50);
	faux = "bcdefghijkmnopqsuvwxyz23456789";
	while (av[i])
	{
		j = 0;
		while (faux[j])
		{
			if (av[i] == faux[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
