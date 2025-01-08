/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 05:51:14 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child(t_exarg *exarg_content)
{
	execve(exarg_content->path, exarg_content->argv, exarg_content->envp);
	exit(errno);
}

void	execute_parent(pid_t pid, t_data *data, t_exarg *exarg_content)
{
	int	wstatus;
	int	exit_status;

	if (waitpid(pid, &wstatus, 0) == -1)
		pipex_end(data, "waitpid failed", EXIT_FAILURE);
	if (WIFEXITED(wstatus))
	{
		exit_status = WEXITSTATUS(wstatus);
		if (exit_status == EACCES)
		{
			ft_dprintf(ERR_OUT, "pipex: ");
			pipex_end(data, exarg_content->path, PERMISSION_DENIED_STATUS);
		}
	}
	else if (WIFSIGNALED(wstatus))
	{
		ft_dprintf(ERR_OUT, "terminated:%d\n", WTERMSIG(wstatus));
	}
}

void	fork_process(t_data *data, t_exarg *exarg_content)
{
	pid_t	pid;

	if (exarg_content->path == NULL)
	{
		ft_dprintf(ERR_OUT, "Command '%s' not found\n", exarg_content->argv[0]);
		// pipex_end(data, NULL, PERMISSION_DENIED_STATUS);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			pipex_end(data, "fork", EXIT_FAILURE);
		else if (pid == 0)
			execute_child(exarg_content);
		else
			execute_parent(pid, data, exarg_content);
	}
}

void	make_child(t_data *data)
{
	t_list	*list;

	list = data->exarg_list;
	while (list != NULL)
	{
		fork_process(data, (t_exarg *)list->content);
		list = list->next;
	}
}

int	main(int argc, const char **argv, char **envp)
{
	t_data	data;
	int	i;

	// if (argc < 5)
	// 	return (ft_dprintf(ERR_OUT, "arguments is too short\n"), 0);
	preprocess(&data, argc, argv, envp);

	i = 1;
	data.i_fd = open(argv[i], O_RDONLY);
	if (data.i_fd == -1)
		pipex_end(&data, argv[i], EXIT_FAILURE);
	i++;
	if (exarg_list_init(&data.exarg_list, &data.args, data.path_dirs, &i)
		== MALLOC_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	data.o_fd = open(argv[i], O_CREAT | O_WRONLY, 0644);
	if (data.o_fd == -1)
		pipex_end(&data, argv[i], EXIT_FAILURE);

	make_child(&data);
	return (pipex_end(&data, NULL, EXIT_SUCCESS), EXIT_SUCCESS);
}
