/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 13:35:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // perror
#include "pipex.h"

void	execute_child(t_data *data, t_exarg *exarg_content)
{
	execve(exarg_content->path, exarg_content->argv, exarg_content->envp);
	ft_dprintf(STDERR_FILENO, "pipex: ");
	perror(exarg_content->path);
	pipex_end(data, NULL, errno);
}

void	execute_parent(pid_t pid, t_data *data, t_exarg *exarg_content)
{
	int	wstatus;
	int	exit_status;

	(void)exarg_content;
	if (waitpid(pid, &wstatus, 0) == -1)
		pipex_end(data, "waitpid failed", EXIT_FAILURE);
	if (WIFEXITED(wstatus))
	{
		exit_status = WEXITSTATUS(wstatus);
		if (exit_status == EACCES)
		{
			pipex_end(data, NULL, PERMISSION_DENIED_STATUS);
		}
	}
	// parent cant get here because signal sent to parent too.
	else if (WIFSIGNALED(wstatus))
	{
		ft_dprintf(STDERR_FILENO, "terminated:%d\n", WTERMSIG(wstatus));
	}
}

void	fork_process(t_data *data, t_exarg *exarg_content)
{
	pid_t	pid;

	if (exarg_content->path == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s: command not found\n", exarg_content->argv[0]);
		// pipex_end(data, NULL, PERMISSION_DENIED_STATUS);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			pipex_end(data, "fork", EXIT_FAILURE);
		else if (pid == 0)
			execute_child(data, exarg_content);
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
	// 	return (ft_dprintf(STDERR_FILENO, "arguments is too short\n"), 0);
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
