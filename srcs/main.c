/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 07:17:11 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "env.h"
#include "path.h"
#include "exe.h"

void	pipex_end(t_data *data, const char *error_str, int status)
{
	if (data->env_list)
		ft_lstclear(&data->env_list, delete_env_content);
	if (data->path_dirs)
		delete_path_dirs(data->path_dirs);
	if (data->exarg_list)
		ft_lstclear(&data->exarg_list, delete_exarg_content);
	if (error_str)
		perror(error_str);
	exit(status);
}

void	make_child(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		pipex_end(data, "fork", EXIT_FAILURE);
	else if (pid == 0)
	{
		// print_env(search_envs(data->env_list, "PATH"));
	}
	else
	{
		// waitpid();
	}
}

void	set_zero(t_data *data)
{
	data->env_list = NULL;
	data->path_dirs = NULL;
	data->exarg_list = NULL;
}

void	set_args(t_args *args, int argc, const char **argv, char **envp)
{
	args->argc = argc;
	args->argv = argv;
	args->envp = envp;
}

int		main(int argc, const char **argv, char **envp)
{
	int		fd;
	t_env	*path_env;
	t_data	data;
	t_list	*list;
	t_exarg	*exarg_content;
	// char	*path;

	set_args(&data.args, argc, argv, envp);
	set_zero(&data);
	if (env_list_init(&data.env_list, envp) == ENV_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	path_env = search_env_list(data.env_list, "PATH");
	if (path_dirs_init(&data.path_dirs, path_env->str) == PATH_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	if (exarg_list_init(&data.exarg_list, &data.args, data.path_dirs)
		== EXE_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	list = data.exarg_list;
	while (list != NULL)
	{
		exarg_content = (t_exarg *)list->content;
		print_exarg_content(exarg_content);
		list = list->next;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		pipex_end(&data, argv[1], EXIT_FAILURE);

	// path = find_path(argv[2], data.path_dirs);
	// if (path == NULL)
	// 	ft_printf("Command '%s' not found\n", argv[2]);

	// else
	// {
	// 	ft_printf("path:%s\n", path);
	// 	free(path);
	// 	make_child(&data);
	// }
	close(fd);
	return (pipex_end(&data, NULL, EXIT_SUCCESS), EXIT_SUCCESS);
}
