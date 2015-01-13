/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:42:01 by maducham          #+#    #+#             */
/*   Updated: 2015/01/08 17:44:14 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

struct group	*grp;
struct passwd	*pwd;
struct dirent	*sd;
struct stat		statbuf;
struct timespec		*tm;
typedef struct		s_info
{
	unsigned char	*file_time;
	char			*file_name;
	char			*group;
	char			*domaine;
	char			*permissions;
	int				size;
	int				link;
	int				size_to;
	int				time_s;
	int				time_modif;
	struct s_info	*next;
}					t_info;

t_info				*ft_create_elem(char *date, char *name, char *grp);
void				ft_list_push_back(t_info **b_l, char *date, char *name, char *grp);
void				ft_putstr(char const *c);
void				ft_list_reverse(t_info **begin_list);
char				*ft_strchr(const char *s, int c);
void				readdirectory(t_info **nf);
void				without_arg(t_info *nf);
void				with_arg(t_info **nf, char *av);
void				function_r(t_info **nf, char *av);
int					function_t(t_info **nf, char *av);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_strnew(size_t len);
size_t				ft_strlen(char const *s);
void				ft_list_sort(t_info **begin_list, int (*cmp)());
char				*many_arg(int ac, char **av);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isalpha(int c);
int					verif_1_param(char *sr);
int					verif_many_param(int ac, char **sr);
int					true_false(char *av);
void				ft_print_list(t_info *e);
void				ft_list_add_1(t_info **b_l, char *domain, int size, int link);
void				ft_list_add_2(t_info **b_l, struct stat statbuf, int sec);
void				ft_printf(char *str, ...);
void				function_l(t_info **nf, char *av, int space_link, int space_size);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				number_space(int n);
void				ft_list_sort_without(t_info **begin_list, int (*cmp)());
void				space_link_function(t_info **b_l, int *space_link, int *space_size ,int f_a);
int					ft_strncmp(const char *s1, const char *s2, unsigned  int i);
void				ft_list_sort_time(t_info ***begin_list, int (*cmp)(), int f_t);
void				print_list(t_info **nf, char *av);
void				calcul_time(t_info **nf, char *time);
int					ft_atoi(char *n);
#endif
