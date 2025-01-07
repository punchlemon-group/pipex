/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/07 07:13:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errno.h"

void	pipex_end(t_data *data, const char *error_str, int status)
{
	if (error_str)
		perror(error_str);
	if (data->i_fd != -1)
		close(data->i_fd);
	if (data->o_fd != -1)
		close(data->o_fd);
	if (data->env_list)
		ft_lstclear(&data->env_list, delete_env_content);
	if (data->path_dirs)
		delete_path_dirs(data->path_dirs);
	if (data->exarg_list)
		ft_lstclear(&data->exarg_list, delete_exarg_content);
	exit(status);
}

void	execve_child(t_data *data, t_exarg *exarg_content)
{
	pid_t	pid;
	int		wstatus;
	int		exit_status;

	if (exarg_content->status == COMMAND_NOT_FOUND)
	{
		write(2, "Command '", 9);
		write(2, exarg_content->argv[0], ft_strlen(exarg_content->argv[0]));
		write(2, "' not found\n", 12);
		pipex_end(data, NULL, PERMISSION_DENIED_STATUS);
	}
	pid = fork();
	if (pid == -1)
		pipex_end(data, "fork", EXIT_FAILURE);
	else if (pid == 0)
	{
		if (exarg_content->status == EXECUTABLE
			|| exarg_content->status == PERMISSION_DENIED)
			execve(exarg_content->path, exarg_content->argv,
				exarg_content->envp);
		exit(errno);
	}
	else
	{
		if (waitpid(pid, &wstatus, 0) == -1)
			pipex_end(data, "waitpid failed", EXIT_FAILURE);
		if (WIFEXITED(wstatus))
		{
			exit_status = WEXITSTATUS(wstatus);
			if (exit_status == EACCES)
			{
				write(2, "pipex: ", 7);
				pipex_end(data, exarg_content->path, PERMISSION_DENIED_STATUS);
			}
		}
		else if (WIFSIGNALED(wstatus))
		{
			ft_printf("terminated:%d\n", WTERMSIG(wstatus));
		}
	}
}

void	make_child(t_data *data)
{
	execve_child(data, (t_exarg *)data->exarg_list->content);
}

void	set_zero(t_data *data)
{
	data->env_list = NULL;
	data->path_dirs = NULL;
	data->exarg_list = NULL;
	data->i_fd = -1;
	data->o_fd = -1;
}

void	set_args(t_args *args, int argc, const char **argv, char **envp)
{
	args->argc = argc;
	args->argv = argv;
	args->envp = envp;
}

int	main(int argc, const char **argv, char **envp)
{
	t_data	data;
	int	i;

	// if (argc < 5)
	// 	return (write(2, "arguments is too short\n", 23), 0);
	set_args(&data.args, argc, argv, envp);
	set_zero(&data);
	if (env_list_init(&data.env_list, envp) == ENV_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	if (path_dirs_init(&data.path_dirs, search_env_list(data.env_list, "PATH"))
		== PATH_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);

	i = 1;
	data.i_fd = open(argv[i], O_RDONLY);
	if (data.i_fd == -1)
		pipex_end(&data, argv[i], EXIT_FAILURE);
	i++;
	if (exarg_list_init(&data.exarg_list, &data.args, data.path_dirs, &i)
		== EXARG_FAILURE)
		pipex_end(&data, "malloc", EXIT_FAILURE);
	data.o_fd = open(argv[i], O_CREAT | O_WRONLY, 0644);
	if (data.o_fd == -1)
		pipex_end(&data, argv[i], EXIT_FAILURE);

	make_child(&data);

	// t_exarg	*exarg_content;
	// t_list	*list;
	// list = data.exarg_list;
	// while (list != NULL)
	// {
	// 	exarg_content = (t_exarg *)list->content;
	// 	print_exarg_content(exarg_content);
	// 	list = list->next;
	// }

	return (pipex_end(&data, NULL, EXIT_SUCCESS), EXIT_SUCCESS);
}
