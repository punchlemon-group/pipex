/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:23:22 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 08:37:54 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

int	paths_init(char ***paths, char *str)
{
	*paths = ft_split(str, ':');
	if (!*paths)
	{
		// delete_paths
		return (1);
	}
	return (0);
}

void	print_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (i > 0)
			ft_printf(", ");
		ft_printf("%s", paths[i]);
		i++;
	}
	ft_printf("\n");
}

char	*find_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_;
	char	*path;
	char	*result;

	result = NULL;
	cmd_ = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd_);
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) == 0)
			{
				free(result);
				result = path;
				return (result);
			}
			else if (result == NULL)
				result = path;
			else
				free(path);
		}
		i++;
	}
	free(cmd_);
	return (result);
}

// char	*find_executable_path(char *cmd, char **paths)
// {
// 	int	i;
// }
