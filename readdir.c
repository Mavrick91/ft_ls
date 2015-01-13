/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:04:38 by maducham          #+#    #+#             */
/*   Updated: 2015/01/08 18:27:06 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_size_to(int	taille)
{
	static int size;

	size += taille;
}

void        readdirectory(t_info **nf)
{
	DIR     *dir;
	char    *crutime;
	int		sec;

	dir = opendir(".");
	while ((sd = readdir(dir)) != NULL)
	{
		stat(sd->d_name, &statbuf);
		crutime = ctime(&statbuf.st_mtime);
		crutime = ft_strsub(crutime, 0, ft_strlen(crutime) - 1);
		pwd = getpwuid(statbuf.st_uid);
		grp = getgrgid(statbuf.st_gid);
		sec = time(&tm->tv_sec);
		ft_list_push_back(nf, crutime, sd->d_name, grp->gr_name);
		ft_list_add_1(nf, pwd->pw_name, statbuf.st_size, statbuf.st_nlink);
		ft_size_to(statbuf.st_blksize);
		ft_list_add_2(nf, statbuf, sec);
	}
}
