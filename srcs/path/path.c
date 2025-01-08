/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:23:22 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 06:36:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

int	path_dirs_init(char ***path_dirs_p, t_env *env)
{
	if (env != NULL && env->str != NULL)
	{
		*path_dirs_p = ft_split(env->str, ':');
		if (*path_dirs_p == NULL)
			return (MALLOC_FAILURE);
	}
	else
		*path_dirs_p = NULL;
	return (SUCCESS);
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
