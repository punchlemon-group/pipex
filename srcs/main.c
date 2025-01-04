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

# include "pipex.h"

void	pipex_end(t_data *data, char *error_str, int status)
{
	if (data->env)
		delete_env(data->env);
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
		ft_printf("%s\n", search_env(data->env, "PATH"));
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

	env_init(&data, envp);
	// if (!data.env)
	// 	pipex_end(&data, "malloc", EXIT_FAILURE);
	// print_env(data.env);
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			pipex_end(&data, argv[1], EXIT_FAILURE);
		close(fd);
	}
	return (pipex_end(&data, NULL, EXIT_SUCCESS), 0);
}
