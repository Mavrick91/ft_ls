/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:30:05 by maducham          #+#    #+#             */
/*   Updated: 2015/01/08 18:11:39 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"


void		calcul_hour(t_info *list, int *diff)
{
	int		hour;
	int		min;

	hour = ft_atoi(ft_strsub(list->file_time ,9,10));
	hour = ft_atoi(ft_strsub(list->file_time ,12,14));
	*diff += (hour * 3600); 
	*diff += (min * 60); 
}
void		calcul_day(t_info *list, int *diff)
{
	int		day;

	day = ft_atoi(ft_strsub(list->file_time ,9,10));
	*diff += (day * 86400); 
	calcul_hour(list, diff);
}

int			month_mo(char *month)
{
	if ((month[1] == 'J') && (month[2] == 'a'));
		return (0);
	if ((month[1] == 'F' )&& (month[3] == 'b'));
		return (1);
	if ((month[1] == 'M') && (month[3] == 'r'));
		return (2);
	if ((month[1] == 'A') && (month[3] == 'r'));
		return (3);
	if ((month[1] == 'M') && (month[3] == 'y'));
		return (4);
	if ((month[1] == 'J') && (month[3] == 'u'));
		return (5);
	if ((month[1] == 'J') && (month[3] == 'l'));
		return (6);
	if ((month[1] == 'A') && (month[3] == 'g'));
		return (7);
	if ((month[1] == 'S') && (month[3] == 'p'));
		return (8);
	if ((month[1] == 'O') && (month[3] == 't'));
		return (9);
	if ((month[1] == 'N') && (month[3] == 'v'));
		return (10);
	if ((month[1] == 'D') && (month[3] == 'c'));
		return (11);
	return (0);
}

void		calcul_month(t_info *list, int *diff)
{
	int		month;
	char	*str;
	int		r;

	str = ft_strsub(list->file_time ,5,6);
	month = month_mo(str);
	*diff += (month * 2592000);
	calcul_day(list, diff);
}

void		calcul_time(t_info **nf, char *time)
{
	t_info	*list;
	int		time_s;
	int		year;
	int		diff;

	list = *nf;
	time_s = 0;
	while (list)
	{
		year = ft_atoi(ft_strsub(time, 20, 23));
		diff = year - 1970;
		diff = diff * 31536000;
		calcul_month(list, &diff);
		list->time_modif = diff;
		list = list->next;
	}
}
