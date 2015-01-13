/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 23:34:43 by maducham          #+#    #+#             */
/*   Updated: 2014/11/17 01:53:52 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		function_t(t_info **nf, char *av)
{
	void	*f;
    int     f_t;

    f_t = 0;
	f = ft_strcmp;
    if (ft_strchr(av, 'a'))
        f_t = 1;
	ft_list_sort_time(&nf, f, f_t);
}
