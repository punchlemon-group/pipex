/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 06:30:58 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 06:37:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

char	*join_path(char *path_dir, const char *cmd)
{
	size_t	path_dir_len;
	size_t	cmd_len;
	size_t	need_slash;
	char	*path;

	cmd_len = ft_strlen(cmd);
	path_dir_len = 0;
	need_slash = 0;
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

int	set_path_if_accessible(const char *cmd, char **path_p)
{
	if (access(cmd, F_OK) == 0)
	{
		*path_p = ft_strdup(cmd);
		if (*path_p == NULL)
			return (MALLOC_FAILURE);
	}
	else
		*path_p = NULL;
	return (SUCCESS);
}

int	find_executable_path_in_env(char **path_dirs, const char *cmd, char **path_p)
{
	int		i;
	char	*new;
	char	*old;

	old = NULL;
	i = 0;
	while (path_dirs[i])
	{
		new = join_path(path_dirs[i], cmd);
		if (new == NULL)
			return (free(old), *path_p = NULL, MALLOC_FAILURE);
		if (access(new, F_OK) == 0)
		{
			if (access(new, X_OK) == 0)
				return (free(old), *path_p = new, SUCCESS);
			else if (old == NULL)
			{
				old = new;
				new = NULL;
			}
		}
		free(new);
		i++;
	}
	return (*path_p = old, SUCCESS);
}

int	get_executable_path(char **path_dirs, char **path_p, const char *cmd)
{
	if (path_dirs == NULL || path_dirs[0] == NULL
		|| ft_strchr(cmd, '/') != NULL)
		return (set_path_if_accessible(cmd, path_p));
	else
		return (find_executable_path_in_env(path_dirs, cmd, path_p));
}
