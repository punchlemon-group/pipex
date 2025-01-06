/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:23:22 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 07:25:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"
#include "exarg.h"

int		path_dirs_init(char ***path_dirs_p, char *str)
{
	if (str == NULL)
		return (*path_dirs_p = NULL, PATH_SUCCESS);
	*path_dirs_p = ft_split(str, ':');
	if (*path_dirs_p == NULL)
		return (PATH_FAILURE);
	return (PATH_SUCCESS);
}

void	delete_path_dirs(char **path_dirs)
{
	int	i;

	if (path_dirs == NULL)
		return ;
	i = 0;
	while (path_dirs[i])
	{
		free(path_dirs[i]);
		i++;
	}
	free(path_dirs);
}

char	*join_path(char *path_dir, const char *cmd)
{
	size_t	path_dir_len;
	size_t	cmd_len;
	size_t	need_slash;
	char	*path;

	cmd_len = ft_strlen(cmd);
	path_dir_len = ft_strlen(path_dir);
	need_slash = path_dir[path_dir_len - 1] != '/';
	path = malloc(path_dir_len + need_slash + cmd_len + 1);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, path_dir, path_dir_len + need_slash + cmd_len + 1);
	if (need_slash)
		path[path_dir_len] = '/';
	ft_strlcpy(path + path_dir_len + need_slash, cmd, cmd_len + 1);
	return (path);
}

int		check_path(char **new_p, char **old_p, const char *cmd, char *path_dir)
{
	*new_p = join_path(path_dir, cmd);
	if (*new_p == NULL)
		return (free(*old_p), MALLOC_FAILURE);
	if (access(*new_p, F_OK) == 0)
	{
		if (access(*new_p, X_OK) == 0)
			return (free(*old_p), EXECUTABLE);
		else if (*old_p == NULL)
			*old_p = *new_p;
		else
			free(*new_p);
		return (PERMISSION_DENIED);
	}
	free(*new_p);
	return (COMMAND_NOT_FOUND);
}

int		find_path(char **pathname_p, const char *cmd, char **path_dirs)
{
	int		i;
	char	*new;
	char	*old;
	int		tmp;
	int		result;

	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0 && ft_strchr(cmd, '/'))
		return (*pathname_p = ft_strdup(cmd), EXECUTABLE);
	if (path_dirs == NULL)
		return (*pathname_p = NULL, COMMAND_NOT_FOUND);
	result = COMMAND_NOT_FOUND;
	old = NULL;
	i = 0;
	while (path_dirs[i])
	{
		tmp = check_path(&new, &old, cmd, path_dirs[i]);
		if (tmp == MALLOC_FAILURE)
			return (*pathname_p = NULL, MALLOC_FAILURE);
		if (tmp == EXECUTABLE)
			return (*pathname_p = new, EXECUTABLE);
		else if (tmp == PERMISSION_DENIED)
			result = tmp;
		i++;
	}
	return (*pathname_p = old, result);
}

// void	print_path_dirs(char **path_dirs)
// {
// 	int	i;

// 	if (path_dirs == NULL)
// 		return ;
// 	i = 0;
// 	while (path_dirs[i])
// 	{
// 		if (i > 0)
// 			ft_printf(", ");
// 		ft_printf("%s", path_dirs[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
// }
