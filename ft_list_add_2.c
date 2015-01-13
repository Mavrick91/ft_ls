#include "ft_ls.h"

void    ft_permissions(t_info *file, struct stat statbuf)
{
	file->permissions = (char*)malloc(sizeof(char));
	if (S_ISLNK(statbuf.st_mode))
		file->permissions[0] = 'l';
	else if (S_ISDIR(statbuf.st_mode))
		file->permissions[0] = 'd';
	else if (S_ISSOCK(statbuf.st_mode))
		file->permissions[0] = 's';
	else if (S_ISFIFO(statbuf.st_mode))
		file->permissions[0] = 'p';
	else if (S_ISCHR(statbuf.st_mode))
		file->permissions[0] = 'c';
	else if (S_ISBLK(statbuf.st_mode))
		file->permissions[0] = 'b';
	else
		file->permissions[0] = '-';
	file->permissions[1] = *( (statbuf.st_mode & S_IRUSR) ? "r" : "-");
	file->permissions[2] = *( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
	file->permissions[3] = *( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
	file->permissions[4] = *( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
	file->permissions[5] = *( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
	file->permissions[6] = *( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
	file->permissions[7] = *( (statbuf.st_mode & S_IROTH) ? "r" : "-");
	file->permissions[8] = *( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
	file->permissions[9] = *( (statbuf.st_mode & S_IXOTH) ? "x" : "-");
	file->permissions[10] = '\0';
}

void    ft_list_add_2(t_info **b_l, struct stat statbuf, int sec)
{
	t_info  *list;

	list = *b_l;
	if (list)
	{
		while (list->next)
			list = list->next;
		ft_permissions(list, statbuf);
		list->time_s = sec;
	}
}
