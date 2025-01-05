/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/02 17:14:56y retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	t_env	*env;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		pipex_end(data, "fork", EXIT_FAILURE);
	else if (pid == 0)
	{
		env = (t_env *)(search_envs(data->envs, "PATH")->content);
		print_env(env);
	}
	else
	{
		// waitpid();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd;
	t_data	data;

	if (envs_init(&data, envp))
		pipex_end(&data, "malloc", EXIT_FAILURE);
	if (argc > 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			pipex_end(&data, argv[1], EXIT_FAILURE);
		make_child(&data);
		close(fd);
	}
	return (pipex_end(&data, NULL, EXIT_SUCCESS), 0);
}
