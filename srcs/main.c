/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 14:15:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "env.h"
#include "path.h"

void	pipex_end(t_data *data, char *error_str, int status)
{
	if (data->envs)
		ft_lstclear(&data->envs, delete_env);
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
		// print_env(search_envs(data->envs, "PATH"));
	}
	else
	{
		// waitpid();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd;
	t_env	*path_env;
	t_data	data;
	char	*path;

	if (argc < 5)
		return (write(2, "arguments is too short\n", 23), EXIT_FAILURE);
	if (envs_init(&data.envs, envp))
		pipex_end(&data, "malloc", EXIT_FAILURE);
	path_env = search_envs(data.envs, "PATH");
	if (path_env)
	{
		if (path_dirs_init(&data.path_dirs, path_env->str))
			pipex_end(&data, "malloc", EXIT_FAILURE);
	}
	else
	{
		// ft_printf("no path\n"); // temporaly
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		pipex_end(&data, argv[1], EXIT_FAILURE);
	path = find_path(argv[2], data.path_dirs);
	if (path == NULL)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	ft_printf("path:%s\n", path);
	free(path);
	make_child(&data);
	close(fd);
	return (pipex_end(&data, NULL, EXIT_SUCCESS), EXIT_SUCCESS);
}
