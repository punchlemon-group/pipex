/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:23:22 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 14:21:39 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

int	path_dirs_init(char ***path_dirs_p, char *str)
{
	*path_dirs_p = ft_split(str, ':');
	if (!*path_dirs_p)
		return (1);
	return (0);
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

void	print_path_dirs(char **path_dirs)
{
	int	i;

	if (path_dirs == NULL)
		return ;
	i = 0;
	while (path_dirs[i])
	{
		if (i > 0)
			ft_printf(", ");
		ft_printf("%s", path_dirs[i]);
		i++;
	}
	ft_printf("\n");
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

int	check_path(char **old_p, char **new_p, char *path_dir, const char *cmd)
{
	*new_p = join_path(path_dir, cmd);
	if (*new_p == NULL)
		return (free(*old_p), 1); // handle malloc failure gracefully
	if (access(*new_p, F_OK) == 0)
	{
		if (access(*new_p, X_OK) == 0)
			return (free(*old_p), 1);
		else if (*old_p == NULL)
			*old_p = *new_p;
		else
			free(*new_p);
	}
	else
		free(*new_p);
	return (0);
}

char	*find_path(const char *cmd, char **path_dirs)
{
	int		i;
	char	*new;
	char	*old;

	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0 && ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	if (path_dirs == NULL)
		return (NULL);
	old = NULL;
	i = 0;
	while (path_dirs[i])
	{
		if (check_path(&old, &new, path_dirs[i], cmd))
			return (new);
		i++;
	}
	return (old);
}
