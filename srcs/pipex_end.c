/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:33:35 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 05:16:43 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> // perror
#include "pipex_end.h"
#include "env.h"
#include "path.h"
#include "exarg.h"

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
