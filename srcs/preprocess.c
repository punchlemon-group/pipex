/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:30:06 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 05:18:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "preprocess.h"

void	set_args(t_args *args, int argc, const char **argv, char **envp)
{
	args->argc = argc;
	args->argv = argv;
	args->envp = envp;
}

void	set_first(t_data *data, int argc, const char **argv, char **envp)
{
	set_args(&data->args, argc, argv, envp);
	data->env_list = NULL;
	data->path_dirs = NULL;
	data->exarg_list = NULL;
	data->i_fd = -1;
	data->o_fd = -1;
}

void	preprocess(t_data *data, int argc, const char **argv, char **envp)
{
	set_first(data, argc, argv, envp);
	if (env_list_init(&data->env_list, envp) == MALLOC_FAILURE)
		pipex_end(data, "malloc", EXIT_FAILURE);
	if (path_dirs_init(&data->path_dirs, search_env_list(data->env_list, "PATH"))
		== MALLOC_FAILURE)
		pipex_end(data, "malloc", EXIT_FAILURE);
}
