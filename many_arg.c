/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 05:11:04 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 01:10:11 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*many_arg(int ac, char **av)
{
	char	*s;
	int		i;
	char	*sr;
	int		o;

	o = 1;
	i = 1;
	sr = NULL;
	s = (char*)malloc(sizeof(char) * 50);
	sr = (char*)malloc(sizeof(char) * 50);
	while (--ac)
		s = ft_strjoin(s, av[i++]);
	sr[0] = s[0];
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] != '-')
		{
			sr[o] = s[i];
			o++;
		}
		i++;
	}
	sr[i] = '\0';
	return (sr);
}
