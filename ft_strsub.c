/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <maducham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:49:10 by maducham          #+#    #+#             */
/*   Updated: 2015/01/08 17:44:01 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s1)
	{
		i = 0;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		while (i < len && s1[start])
		{
			str[i] = s1[start];
			i++;
			start++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
